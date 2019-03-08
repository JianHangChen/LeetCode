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
