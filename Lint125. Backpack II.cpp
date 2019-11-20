//!!! sol2.1,from 9ch  O(mn), O(m), 1D DP
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



// sol2,my modify from 9ch  O(mn), O(m), 1D DP
class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
    	int n = A.size(); if(n == 0) return 0;
    	
    	vector<int> dp1(m+1, 0);
    	dp1[A[0]] = V[0];

    	for(int i = 1; i < n; i++){
    		vector<int> dp2(m+1, 0);
    		for(int j = 0; j <= m; j++){
    			int max1 = 0, max2 = 0;
    			max1 = dp1[j];
    			if(j - A[i] >= 0) max2 = dp1[j - A[i]] + V[i];
    			dp2[j] = max(max1, max2);
    		}
    		dp1 = dp2;
    	}
    	int res = 0;
    	for(int i = 0; i <= m; i++) res = max(res, dp1[i]);

    	return res;
    }
};



// sol1,from  O(mn), O(mn), 2D DP
class Solution {
public:
    int backPackII(int m, vector<int> &A, vector<int> &V) {
    	int n = A.size();
    	if(n == 0) return 0;
    	vector<vector<int>> dp(n, vector<int> (m + 1, 0)); // dp[i][j] means for (i+1) the element, the maximum value when the size is exactly = j
	    dp[0][A[0]] = V[0];

    	for(int i = 1; i < n; i++){ // i means i-th (i+1) element
    		for(int j = 0; j <= m; j++){ // j means the total size of candidates 
    			dp[i][j] = dp[i - 1][j];		
				if(j - A[i] >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - A[i]] + V[i]);
    		}
    	}
    	int res = 0;
    	for(int j = 0; j <= m; j++) res = max(res, dp[n-1][j]);
    	return res;
    }
};
