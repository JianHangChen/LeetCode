

// !!! sol1, from gy, trick high--
// very important question, easily wrong

class Solution {
public:
    int findMin(vector<int>& nums) {
        int h = nums.size() - 1, l = 0;
        
        while(l < h){
            int mid = l + (h - l) / 2;
            if(nums[mid] > nums[h]){
                l = mid + 1;
            }
            else if(nums[mid] == nums[h]){
                h--;
            }
            else{
                h = mid;
            }
        }
        return nums[h];
        
    }
};


// sol2, from gy2, divide and conquer
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        return getMin(nums, 0, nums.size() - 1);
        
        
    }
    
    int getMin(vector<int>& nums, int start, int end){
        if(start == end) return nums[start];
        if(nums[start] < nums[end]) return nums[start];

        int mid = start + (end - start) / 2;
        
        return min(getMin(nums, start, mid), getMin(nums, mid+1, end));
        
    }
};

class Solution:
    
    # my sol1, recursively
    def findMin(self, nums: List[int]) -> int:
        
        def helpler(low, high):
            if low == high:
                return nums[low]
            mid = low + (high - low) // 2
            if nums[mid] > nums[high]:
                return helpler( mid+1, high)
            if nums[mid] < nums[high]:
                return helpler( low, mid)
            if nums[mid] > nums[low]:
                return helpler(low, mid - 1 )
            if nums[mid] < nums[low]:
                return helpler(low+1, mid)
            left = helpler(low, mid)
            if left < nums[mid]:
                return left
            else:
                return helpler(mid, high-1)
        
        low = 0
        high = len(nums) - 1
        return helpler(low, high)


    # my sol2, iteratively, binary search
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        while low < high:
            mid = low + (high - low)//2
            if nums[mid] > nums[high]:
                low = mid + 1
            elif nums[mid] < nums[high]:
                high = mid
            else: # nums[mid] == nums[high]
                if nums[low] < nums[high]:
                    return nums[low]
                if nums[low] > nums[high]:
                    high = mid
                    low = low + 1
                else: # nums[mid] == nums[high] == nums[low]
                    low = low + 1
                    high = high - 1
                    
        return nums[low]

    #  sol3,  using trick high--
    #from https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/discuss/167981/Beats-100-Binary-Search-with-Explanations
    
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums) - 1
        while low <high:
            mid = low + (high - low) // 2
            if nums[mid] > nums[high]:
                low = mid + 1
            elif nums[mid] < nums[low]:
                high = mid
                low = low + 1
            else:
                high = high - 1
        
        return nums[low]
