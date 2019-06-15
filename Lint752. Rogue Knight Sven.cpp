long long getNumberOfWays(int n, int m, int limit, vector<int> &cost) {
        vector<vector<long>> dp(n+1, vector<long> (m+1, 0));
        
        dp[0][m] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = m; j >= 0; j--){
                int coin = j + cost[i];
                if(coin <= m){
                    for(int p = i - 1; p >= 0 && p >= i - limit; p--){
                        dp[i][j] += dp[p][coin];
                    }
                }
            }
        }
        
        long long ans = 0;

        for(auto i:dp[n]){
            ans += i;
        }
        return ans;
    }
