class Solution:
    

    
    # test case: [],  [1,2],  [1] 1
      
#       sol1, 2 binary search, write from ans    
#   def searchRange(self, nums: List[int], target: int) -> List[int]:    
#         if nums == []:
#             return [-1, -1]
        
#         low = 0
#         high = len(nums) - 1
        
#         while low + 1 < high:
#             mid = low + (high - low) // 2
            
#             if nums[mid] >= target:
#                 high = mid
#             else:
#                 low = mid + 1
                
#         if nums[low] == target:
#             start = low
#         elif nums[high] == target:
#             start = high
#         else:
#             return [-1, -1]
        
#         low = start
#         high = len(nums)
        
#         while low < high:
#             mid = low + (high - low) // 2
            
#             if nums[mid] > target:
#                 high = mid
#             else:
#                 low = mid + 1
#         end = low - 1
            
        # return [start, end] 
        
    # sol 1.1, from ans, iteratively 2 binary search
    
    # def searchRange(self, nums: List[int], target: int) -> List[int]:        
        
#         def search(isleft):
#             low = 0
#             high = len(nums)
#             while low < high:
                
#                 mid = low + (high - low) // 2
#                 # left not done: find the first appearance
#                 # left done: find the idx after last appearance
                
#                 if nums[mid] > target or (isleft and nums[mid] == target):
#                     high = mid
#                 else:
#                     low = mid + 1
#             return low
#         left_idx = search(isleft = True)
#         if left_idx >= len(nums) or nums[left_idx] != target:
#             return [-1, -1]
#         return [left_idx, search(isleft = False) - 1]

# sol1.2, best two binary search !!!
# from sol2 of https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14707/9-11-lines-O(log-n)
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def insert_idx(n): # get the idx if insert n to nums
            low = 0
            high = len(nums)
            
            while low < high:
                mid = low + (high - low) // 2
                
                if nums[mid] < n:
                    low = mid + 1
                else:
                    high = mid
            return low
        left = insert_idx(target)
        
        return [left, insert_idx(target+1) - 1] if target in nums[left:left+1]  else [-1, -1]
    
    # here  if target in nums[left:left+1], even if nums == [], we can say target not in nums
    # is not the same as nums[left] == target
        
    


        # sol2, my, brute force, linear scan O(n)
        
#         start = end = -1
#         for i in range(len(nums)):
#             if nums[i] == target:
#                 if start == -1:
#                     start = end = i
#                 else:
#                     end = i
                    
#         return [start, end]

#         # sol2.1, from the ans, better linear scan
    
#         for i in range(len(nums)):
#             if nums[i] == target:
#                 start = i
#                 break
#         else:
#             return [-1, -1]
        
#         for i in range(len(nums)-1, -1, -1):
#             if nums[i] == target:
#                 end = i
#                 break
                
#         return [start, end]
        

    # sol3, divide and conquer by recursion
#from https://leetcode.com/explore/learn/card/binary-search/135/template-iii/944/discuss/14707/9-11-lines-O(log-n)
#     def searchRange(self, nums: List[int], target: int) -> List[int]:
#         def search(low, high):
#             mid = low + (high - low) // 2
#             if nums[low] == nums[high] == target:
#                 return [low, high]
#             if nums[low] <= target <= nums[high]:
#                 left = search(low, mid)
#                 right = search(mid+1, high)
#                 return max(left , right) if -1 in (left+right) else [ left[0], right[1] ]
#             else:
#                 return [-1, -1]
            
#         return [-1, -1] if len(nums) == 0 else search(0, len(nums) - 1)
        
    # sol4, use python library
# from sol3 of https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14707/9-11-lines-O(log-n)
    # def searchRange(self, nums: List[int], target: int) -> List[int]:
    #     low = bisect.bisect_left(nums, target)
    #     return [low, bisect.bisect(nums, target) - 1] if target in nums[low:low+1] else [-1, -1]
        
