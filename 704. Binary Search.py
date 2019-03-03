class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        # sol1, my, brute force, O(n)
        # for idx, num in enumerate(nums):
        #     if num == target:
        #         return idx
        # return -1
    
        # sol2,my divide and conquer, recursively, log(n)
        
        def helpler(low, high):
            if low > high:
                return -1
            
            mid = (low+high)//2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                return helpler(low, mid-1)
            else:
                return helpler(mid+1, high)
            return -1
        return helpler(0, len(nums)-1)

        # sol3, my,  divide and conquer, iteratively, log(N)
#         low = 0
#         high = len(nums)-1
        
#         while low <= high:
#             mid = (low+high)//2
#             if nums[mid] == target:
#                 return mid
#             elif nums[mid] > target:
#                 high = mid-1
#             else:
#                 low = mid + 1
#         return -1
