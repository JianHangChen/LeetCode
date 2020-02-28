

//!!! sol2, from sol2, iterative binary search, O(logn), O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums){
        int n = nums.size();
        int l = 0, h = n - 1;
        while(l < h ){
            mid = l + (h - l) / 2;
            if(nums[mid] > nums[mid+1]){
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};


// sol1, my, linear O(n), O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums){
        int n = nums.size();
        if(n == 1 || n > 1 && nums[0] > nums[1]) return 0;
        if(n - 2 >= 0 && nums[n-1] > nums[n-2]) return n-1;
        for(int i = 1; i < n - 1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        }
        return -1;
    }
};













class Solution:
    
    # sol1, my iteratively binary search, log(n) , O(1)
#     def findPeakElement(self, nums: List[int]) -> int:
        
#         low = 0
#         high = len(nums) - 1
        
#         while low <= high:
#             mid = low + (high - low) // 2
            
#             if mid > low:
#                 if nums[mid] < nums[mid - 1]:
#                     high = mid - 1
#                     continue
            
#             if mid < high:
#                 if nums[mid] < nums[mid + 1]:
#                     low = mid + 1
#                     continue
#             return mid
#         return -1


    # sol1.1, better iterative, from sol3
    def findPeakElement(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        
        while low < high:
            mid = low + (high - low) // 2
            if nums[mid] > nums[mid + 1]:
                high = mid
            else:
                low = mid + 1
        return low
    

    # sol2, recursivley log(n) , log(n), from sol2
#     def findPeakElement(self, nums: List[int]) -> int:
        
#         def search(l, r):
#             if l == r: return l
#             mid = l + (r - l)//2
#             if nums[mid] > nums[mid + 1]:
#                 return search(l, mid)
#             else:
#                 return search(mid + 1, r)
#         return search(0, len(nums) - 1 )
