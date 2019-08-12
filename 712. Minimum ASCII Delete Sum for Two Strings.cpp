
// sol2, !!!!from granyang sol2, O(mn), O(n)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> dp1(n2+1, 0);
        vector<int> dp2 = dp1;
        for(int j = 1; j <= n2; j++) dp1[j] = dp1[j-1] + s2[j-1];
        for(int i = 1; i <= n1; i++){
            dp2[0] = dp1[0] + s1[i-1];
            for(int j = 1;j <= n2; j++){
                if(s1[i-1] == s2[j-1]) dp2[j] = dp1[j-1];
                else dp2[j] = min(dp2[j-1] + s2[j-1], dp1[j] + s1[i-1]);
            }
            dp1 = dp2;
        }
        return dp1[n2];
    }
};


sol1, !! from grandyang sol1, O(mn), O(mn)
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int> (n2+1,0));
        for(int i = 1; i <= n1; i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        for(int j = 1; j <= n2; j++) dp[0][j] = dp[0][j-1] + s2[j-1];
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i][j-1] + s2[j-1], dp[i-1][j] + s1[i-1]);
            }
        }
        
        return dp[n1][n2];
        
    }
};

sol3, from gy, get biggest equal string
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        
        vector<vector<int>> dp(n1+1, vector<int> (n2+1, 0));
        
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + s1[i-1];
                else dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
        
        int acc = 0;
        for(int i = 0; i < n1; i++) acc += s1[i];
        for(int j = 0; j < n2; j++) acc += s2[j];
        
        return acc - 2 * dp[n1][n2]; 
        
    }
};

