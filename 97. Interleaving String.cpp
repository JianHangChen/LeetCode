// !!! sol3, my, 1 d dp, O(mn), O(n)
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(s1.size() + s2.size() != s3.size()) return false;
        
        vector<bool> cur(n+1, false), pre = cur;
        
        for(int i = 0; i <= m ; i++){
            for(int j = 0; j <= n ;j++){
                if(i == 0 && j == 0){
                    cur[j] = true;
                }
                else if(i == 0 && j != 0){
                    cur[j] = cur[j-1] && s2[j-1] == s3[i+j-1];
                }
                else if(j == 0 && i != 0){
                    cur[j] = pre[j] && s1[i-1] == s3[i+j-1];
                }
                else{
                    cur[j] = cur[j-1] && s2[j-1] == s3[i+j-1] || pre[j] && s1[i-1] == s3[i+j-1];
                }
            }
            pre = cur;
        }
        return cur[n];
        
    }
};



!sol2, my, dp, O(mn), O(mn)

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        
        for(int i = 0; i <= m ; i++){
            for(int j = 0; j <= n ;j++){
                if(i == 0 && j == 0){
                    dp[i][j] = true;
                }
                else if(i == 0 && j != 0){
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1];
                }
                else if(j == 0 && i != 0){
                    dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1];
                }
                else{
                    dp[i][j] = dp[i][j-1] && s2[j-1] == s3[i+j-1] || dp[i-1][j] && s1[i-1] == s3[i+j-1];
                }
            }
        }
        return dp[m][n];
        
    }
};

sol1, my, dfs with memorization O(mn), O(mn) 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> cache(m + 1, vector<int> (n + 1, -1));
        return isInterleave(0,0,0,s1, s2, s3, cache);
    }

    bool isInterleave(int i, int j, int k, string& s1, string& s2, string& s3, vector<vector<int>>& cache) {
        if(cache[i][j] != -1) return cache[i][j];
        
        if(i < s1.size() && s3[k] == s1[i]){
            if(isInterleave(i+1, j, k + 1, s1, s2, s3, cache)){
                cache[i][j] = 1;
                return true;
            }
        }
        if(j < s2.size() && s3[k] == s2[j]){
            if(isInterleave(i, j+1, k + 1, s1, s2, s3, cache)){
                cache[i][j] = 1;
                return true;
            }
        }
        if(i == s1.size() && j == s2.size() && k == s3.size()){
            cache[i][j] = 1;
            return true;
        }
        cache[i][j] = 0;
        return false;
    }
};
