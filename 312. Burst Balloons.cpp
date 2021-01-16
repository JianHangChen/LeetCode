
// ! sol1, O(n^3), O(n^2)
// from https://www.youtube.com/watch?v=0PoWegfg03A&feature=youtu.be

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int l = nums.size(), n = l + 2;
        vector<int> arr(n, 1);
        for(int i = 0; i < l; i++){
            arr[i+1] = nums[i];
        }        
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        // dp[i][j] the maximum coins from i to j (included)
        
        int coins = 0;     
        for(int len = 3; len <= n; len++){
            for(int left = 0; left <= n - len; left++){
                int right = left + len - 1;
                for(int burstIdx = left + 1; burstIdx < right; burstIdx++){
                    dp[left][right] = max(dp[left][right], 
                                         dp[left][burstIdx] + arr[left] * arr[burstIdx] * arr[right] + dp[burstIdx][right]);
                }
            }
            
        }
        return dp[0][n-1];
        
    }
};
