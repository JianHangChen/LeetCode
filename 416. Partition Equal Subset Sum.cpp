// sol2, dp, O(n*half), O(half)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num:nums) total+=num;
        if(total % 2 == 1) return false;
        int half = total / 2;
        
        int n = nums.size();
        vector<bool> dp(half+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = half; j >= 0; j--){ // 倒着来可以防止重复计算reach位置，避免一个nums[i-1]用好多次
                if(j - nums[i-1] >= 0){
                    dp[j] = dp[j] || dp[j - nums[i-1]];                         
                }
            }
        }
        return dp[half];
        
    }
};


// sol1, dp, O(n*half), O(n*half)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for(int num:nums) total+=num;
        if(total % 2 == 1) return false;
        int half = total / 2;
        
        // dp[i][j] using nums [0, i-1], can reach value j
        // dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i]];
        // base:
        // dp[0][0] = true; using 0 element can still reach 0
        // dp[i][0] = true;
        
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool> (half+1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= half; j++){
                if(j == 0) dp[i][j] = true;
                else{
                    dp[i][j] = dp[i-1][j];
                    if(j - nums[i-1] >= 0){
                        dp[i][j] = dp[i][j] || dp[i-1][j - nums[i-1]];                        
                    }
                }
            }
        }
        return dp[n][half];
        
    }
};
