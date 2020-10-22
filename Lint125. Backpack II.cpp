// sol2.1,from 9ch  O(mn), O(m), 1D DP
class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
    	vector<int> dp(m+1, 0); // dp[i] means when the size <= i (not exact =), the maximum value
    	int n = A.size();
    	for(int i = 0; i < n; i++){
    		for(int j = m; j >= A[i]; j--){
    			dp[j] = max(dp[j - A[i]] + V[i], dp[j]); // from back to front, avoid overwrite before use
    		}
    	}
    	return dp[m];
    }
};



//!!! sol2,my modify from 9ch  O(mn), O(m), 1D DP
class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int n = A.size();
        vector<int> dp(m+1, 0), dp2 = dp;
        
        for(int j = 0; j < n; j++){
            for(int i = 1; i <= m; i++){
                if(j == 0 ){
                    if(i - A[j] >= 0) dp2[i] = V[0];
                }
                else{
                    dp2[i] = dp[i];
                    if(i - A[j] >= 0) dp2[i] = max(dp[i-A[j]] + V[j], dp2[i]);
                }
            }
            dp = dp2;
        }
        return dp[m];
    }
};


//!!! sol1,from  O(mn), O(mn), 2D DP
class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        int n = A.size();
        // dp[i][j] the maximum value we have, until i, with total pack j
        vector<vector<int>> dp(n, vector<int> (m+1, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0){
                    if(j >= A[i]) dp[i][j] = V[i];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                    if(j >= A[i]){
                        dp[i][j] = max(dp[i][j], V[i] + dp[i-1][j-A[i]]);
                    }
                }
            }
        }
        return dp[n-1][m];
    }
};
