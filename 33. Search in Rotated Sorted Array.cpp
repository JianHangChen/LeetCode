

// !!! form sol2, O(logn), same as gy2
// check the "direction" of the part [i, mid]
// if [i, mid] is sorted, then if the target is in [i, mid], the search space is i, mid - 1
//                              if the target is not in [i, mid] then either it is bigger than nums[mid], or smaller than nums[i], those case locate in [mid + 1, j]

// if [i, mid] is not sorted, then the pivot point is inside [i, mid],
// so [mid, j] is sorted, then if the target is in [mid, j], then the search space is mid+ 1, j
//                               if the target is not in [mid, j], then either it is bigger than nums[j], or smaller than nums[mid], those case locate in [i, mid-1]

// follow-up: how about repeated number in the array

class Solution {
public:
    int search(vector<int>& nums, int target){
        int i = 0, j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j - i) / 2;
            if(nums[mid] == target) return mid;
            if(nums[i] == nums[mid]){
                i++; // follow up
            }
            else if(nums[i] < nums[mid]){
                if( nums[i] <= target && target < nums[mid]) j = mid - 1;
                else i = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[j]) i = mid + 1;
                else j = mid - 1;
            }

        }
        return -1;
    }
};


// class Solution:
    
//     # sol1
//     # from 2 of https://leetcode.windliang.cc/leetCode-33-Search-in-Rotated-Sorted-Array.html
// #     def search(self, nums: List[int], target: int) -> int:
// #         low = 0
// #         high = len(nums) - 1
// #         while low <= high:
// #             mid = (high + low)//2
            
// #             # here is very important
// #             # ( target > nums[0]) == (nums[mid] > nums[0]) is wrong!!!
// #             if ( ( target < nums[0]) == (nums[mid] < nums[0]) ): 
// #                 m = nums[mid]
// #             elif target < nums[0]:
// #                 m = -float('inf')
// #             else:
// #                 m = float('inf')

// #             if target > m:
// #                 low = mid + 1
// #             elif target < m:
// #                 high = mid - 1
// #             else:
// #                 return mid
// #         return -1

//     # sol2
//     # form sol1 of above link
// #     def search(self, nums: List[int], target: int) -> int:
// #         low = 0
// #         high = len(nums) - 1
        
// #         # find smalles value index
        
// #         while low < high:
// #             mid = low + (high - low) // 2
            
// #             if nums[mid] > nums[high]:
// #                 low = mid + 1
// #             else:
// #                 high = mid
// #         bias = low
        
// #         low = 0
// #         high = len(nums) - 1
        
// #         while low <= high:
// #             mid = low + (high - low) // 2
// #             trans_mid = (mid + bias) % len(nums)
            
// #             if nums[trans_mid] == target:
// #                 return trans_mid
// #             elif nums[trans_mid] > target:
// #                 high = mid - 1
// #             else:
// #                 low = mid + 1
                
// #         return -1

//     # sol3, 
//     # from above link
//     def search(self, nums: List[int], target: int) -> int:
//             low = 0
//             high = len(nums) - 1
            
//             while low <= high:
//                 mid = low + (high - low ) // 2
//                 if nums[mid] == target:
//                     return mid
//                 if nums[low] <= nums[mid]:
//                     if nums[mid] > target and target >= nums[low]:
//                         high = mid - 1
//                     else:
//                         low = mid + 1
//                 else:
//                     if nums[mid] < target and target <= nums[high]:
//                         low = mid + 1
//                     else:
//                         high = mid - 1
                        
//             return -1
