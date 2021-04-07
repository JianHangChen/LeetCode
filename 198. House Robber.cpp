// !!! sol3, dp, O(n),O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp0 = 0, dp1 = 0;
        for(int i = 1; i <= n; i++){
            int dp2 = max(dp0+nums[i-1], dp1);
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp1;
    }
};

//! sol2, my, dp, O(n), O(n)
// [1,2,3,1]
// 4
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);  
        // dp[i] means with [0, ..., i-1] houses, the maximum amount can rob
        // case1 with current i - 1, case2 without i-1
        // base case
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
};

!!! sol1, my dfs with memo, O(n), O(n)
class Solution {
public:
    unordered_map<int, int> memo;
    int rob(vector<int>& nums) {
        
        return helper(nums, 0);
    }
    int helper(vector<int>& nums, int start){
        
        int n = nums.size();
        if(start >= n) return 0;
        if(memo.count(start) > 0) return memo[start];
        
        int res = 0;
        
        // take the start:
        res = max(res, nums[start] + helper(nums, start + 2));
        // not take this house
        res = max(res, helper(nums, start + 1));
        memo[start] = res;
        return res;
        
    }
};

