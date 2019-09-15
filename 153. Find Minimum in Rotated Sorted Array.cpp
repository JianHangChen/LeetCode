//!!! sol1, my
class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();
        int l = 0, h = length - 1, mid;
        
        while(l < h){
            mid = l + (h - l) / 2;
            if(nums[mid] > nums[h]){
                l = mid + 1;
            }
            else{
                h = mid;
            }
            
        }
        
        return nums[l];
        
        
    }
};


// sol2, divide and conquer, from gy2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int length = nums.size();        
        
        return getMin(nums, 0, length - 1);
    }
    
    int getMin(vector<int>& nums, int start, int end){
        if(nums[start] <= nums[end]) return nums[start];
        
        int mid = start + (end - start) / 2;
        return min(getMin(nums, start, mid), getMin(nums, mid+1, end));
        
    }
    
};







class Solution:
    # sol1, my binary search
#     def findMin(self, nums: List[int]) -> int:
#         low = 0
#         high = len(nums) - 1
        
#         while low < high:
#             mid = low + (high - low) // 2
            
#             if nums[mid] >= nums[low]:
#                 if nums[low] < nums[high]:
#                     return nums[low]
#                 else:
#                     low = mid + 1
#             else:
#                 high = mid
        
#         return nums[low]
    
    # sol2, from ans
    # seems similar, the idea is to find a good reflection point
    
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) -1 
        if nums[low] < nums[high]:
            return nums[low]
        
        
        
        while low < high:
            mid = low + (high - low) // 2
            if nums[mid] > nums[mid+1]:
                return nums[mid+1]
            if nums[mid] < nums[mid-1]:
                return nums[mid]
            
            if nums[mid] > nums[0]:
                low = mid + 1
            else:
                high = mid
                
        return nums[low]
