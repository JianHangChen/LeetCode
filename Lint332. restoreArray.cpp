// sol1, dp, O(n), O(n)
// from https://github.com/wisdompeak/LintCode/tree/master/DP/332.Restore-Array

class Solution {
public:

    int restoreArray(int n, int l, int r) {
        int k  = r - l  + 1;
        int d = 1e9+7;
        vector<int> m(3, k / 3);
        if(k % 3 == 1){
            m[r%3]++;
        }
        else if(k % 3 == 2){
            m[r%3]++;
            m[(r-1)%3]++;
        }
        long long dp[n+1][3] = {};
        for(int i = 0; i < 3; i++) dp[1][i] = m[i];
        for(int i = 2; i <= n; i++){
            for(int j  = 0; j < 3; j++){
                for(int t = 0; t < 3; t++){
                    dp[i][j] = (dp[i][j] + dp[i-1][t] * m[(j - t + 3) % 3]) % d;
                }
            }
        }
        return dp[n][0] % d;
        
    }
};
