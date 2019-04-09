class Solution:
    
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        def NSum(left, target, N, result, results):
            if len(nums) < N or target < nums[left] * N or target > nums[-1] * N:
                return
            
            if N == 2:
                right = len(nums) - 1
                
                while left < right:
                    s = nums[left] + nums[right]
                    if s == target:
                        results.append(result + [nums[left], nums[right]])
                        left += 1
                        while left < right and nums[left] == nums[left - 1]:
                            left += 1
                    elif s > target:
                        right -= 1
                    else:
                        left += 1
                
                
            else:
                for i in range(left, len(nums) - N + 1):
                    if i == left or (i > left and nums[i] != nums[i-1]):
                        NSum(i+1, target - nums[i], N - 1, result + [nums[i]], results)
                
        
        
        results = []
        nums.sort()        
        NSum(0, target, 4, [], results)
        return results
        
