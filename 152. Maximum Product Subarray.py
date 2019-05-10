class Solution:
    # !! sol1, dp, KEEP imax and imin
    # O(n), O(1)
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return
        res = nums[0]
        imin = imax = res  # the min, max prefix product containing nums[i]
        
        for i in range(1, n):
            if nums[i] < 0:
                imin, imax = imax, imin
            
            imax = max(nums[i], nums[i] * imax)
            imin = min(nums[i], nums[i] * imin)
            
            if res < imax:
                res = imax
        return res
        
            
    # sol2, dp
    # O(n), O(n)
    def maxProduct(self, nums: List[int]) -> int:
        rev = nums[::-1]
        for i in range(1,len(nums)):
            if nums[i - 1] != 0:
                nums[i] *= nums[i-1]
            if rev[i - 1] != 0:
                rev[i] *= rev[i-1]
        
        return max(rev+nums)
