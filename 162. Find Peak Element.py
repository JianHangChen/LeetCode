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
