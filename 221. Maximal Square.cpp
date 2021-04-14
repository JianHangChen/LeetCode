

//! sol2.1, dp, from sol2, O(mn),O(n)
class Solution {
public:
    int m, n;
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n+1, 0); //!!! carefull of the index
        int res = 0;
 
        // dp[j] means the maximum square we have from [0, 0] to [i-1][j-1]
        for(int i = 1; i <= m; i++){
            vector<int> newdp(n+1, 0);
            for(int j = 1; j <= n; j++){
                if(matrix[i-1][j-1] == '1') newdp[j] = min(newdp[j-1], min(dp[j-1], dp[j])) + 1;
                res = max(res, newdp[j]);
            }
            dp = newdp;
        }
        return res * res;
    }
};

// [["0","1"]
//  ["1","0"]]

//!!! sol2, dp, from sol2, O(mn),O(mn)
class Solution {
public:
    int m, n;
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0)); //!!! carefull of the index
        int res = 0;
 
        // dp[i][j] means the maximum square we have from [0, 0] to [i-1][j-1]
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(matrix[i-1][j-1] == '1') dp[i][j] = min(dp[i][j-1], min(dp[i-1][j-1], dp[i-1][j])) + 1;
                res = max(res, dp[i][j]);
            }
        }
        return res * res;
    }
};

sol1, my, O(n^3), O(mn)
class Solution {
public:
    int m, n;
    int maximalSquare(vector<vector<char>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        int res = 0;
        // presum, the rectangle from [0, 0] to [i, j], on the upper left side of i, j , no included
        vector<vector<int>> presum(m+1, vector<int> (n+1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                presum[i][j] = presum[i-1][j] + presum[i][j-1] - presum[i-1][j-1] + (matrix[i-1][j-1] - '0');
            }
        };
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                // check if  square for [i, j] to [i+k, j+k] (included) is valid
                // if yes, res = max(res, area), check [i+k+1, j+k+1];
                // if no, move to next i, j
                for(int k = 0; i + k < m && j + k < n; k++){ // size is (k+1)^2
                    int area = presum[i+k+1][j+k+1] + presum[i][j] - presum[i+k+1][j] - presum[i][j+k+1];
                    if(area == (k+1)*(k+1)){
                        res = max(res, area);
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return res;
    }
};
