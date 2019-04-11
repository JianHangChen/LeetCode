
class Solution:
    
    # sol1, bisearch + window O(nlog(W) + nlogn)
    def smallestDistancePair(self, nums: List[int], k: int) -> int:    
        n = len(nums)
        nums.sort()
        low = 0
        high = nums[-1] - nums[0]
        count = 0
        while low < high:
            mid = low + (high - low) // 2
            
            i = 0; j = 1; count = 0
            while i < n - 1:
                while j < n and mid >= nums[j] - nums[i]:
                    j += 1
                pairs = j - i - 1
                count += pairs
                i += 1
            
            if count < k:
                low = mid + 1
            else:
                high = mid
                
        return low

    # sol3, bisearch + presum
    # O(H + nlogW + nlogn)
    # H is the biggest nums, W is biggest nums[i] - nums[j]
    
    def smallestDistancePair(self, nums: List[int], k: int) -> int:    
        def count(m, upper_bound, prefix):
            c = 0
            for i in range(len(nums)):
                c += prefix[min(m + nums[i], upper_bound)] - (i+1)
            return c
        
        n = len(nums)
        nums.sort()
        low = 0;  high = nums[-1] - nums[0] ; upper_bound = nums[-1]
        
        prefix = [0] * (upper_bound + 1) # prefix v is the number of num <= v in nums
        j = 0; last = 0
        for i in range(upper_bound + 1):
            while j < n and i == nums[j]:
                last += 1
                j += 1
            prefix[i] += last
        
        while low < high:
            mid = low + (high - low) // 2
            if count(mid, upper_bound, prefix) < k:
                low = mid + 1
            else:
                high = mid
                
        return low
        
