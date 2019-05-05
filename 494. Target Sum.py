class Solution:
    # sol1, memorization
    # O(l*n), O(l*n), 472ms
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        def findTarget(i, sum, memo):
            if i == len(nums):
                if sum == S:
                    return 1
                else:
                    return 0
            else:
                if memo[i][sum+1000] == -float("inf"):
                    add = findTarget(i+1, sum + nums[i], memo)
                    sub = findTarget(i+1, sum - nums[i], memo)
                    memo[i][sum+1000] = add + sub
                return memo[i][sum+1000]
                
            
        #memo = [[-float('inf')]*2001]*len(nums) # wrong! careful about repeated reference in python
        memo = [[-float("inf")]*2001 for _ in range(len(nums))]
        
        return findTarget(0, 0, memo)
    
    # sol2, 2D DP, O(l*n), O(l*n) 476ms  
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if S < -1000 or S > 1000:
            return 0
        dp = [ [0]*2001 for _ in range(len(nums)) ]
        dp[0][nums[0]] += 1
        dp[0][-nums[0]] += 1
        
        for i in range(1, len(nums)):
            for sum in range(-1000, 1001):
                if dp[i-1][sum] > 0:
                    dp[i][sum + nums[i]] += dp[i-1][sum]
                    dp[i][sum - nums[i]] += dp[i-1][sum]
        return dp[len(nums)-1][S]
    
    # !!! sol4, 1D DP, O(l*n), O(n)
    # 348ms
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if S < -1000 or S > 1000:
            return 0
        dp = [0]*2001
        dp[nums[0]] += 1
        dp[-nums[0]] += 1
        
        for i in range(1, len(nums)):
            new = [0] * 2001
            for sum in range(-1000, 1001):
                if dp[sum] > 0:
                    new[sum + nums[i]] += dp[sum]
                    new[sum - nums[i]] += dp[sum]
            dp = new
        return dp[S]

        
            
