// !!! sol2.1, O(mn), O(n)
class Solution{
public:
    bool isMatch(string s, string p){
        int m = s.size(), n = p.size();
        vector<bool> pre(n+1, false);
        for(int i = 0; i <= m; i++){
            vector<bool> cur(n+1, false); 
            if(i == 0) cur[0] = true;
            for(int j = 1; j <= n; j++){
                if(p[j - 1] != '*'){
                    if(i >= 1 && ( s[i-1] == p[j-1] || p[j-1] == '.')){
                        cur[j] = pre[j-1];
                    }
                }
                else{ // p[j-1] is *
                    if(j == 1) continue;
                    if(cur[j-2]){
                        cur[j] = true;
                    }
                    else{
                        if(i >= 1 && (s[i-1] == p[j-2] || p[j-2]=='.') ){
                            cur[j] = pre[j];
                        }
                    }
                }
            }
            pre = cur; 
        }
        return pre[n];
   }        
};


// // ! sol2, dp, O(mn), O(mn)
class Solution{
public:
    bool isMatch(string s, string p){
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(p[j - 1] != '*'){
                    if(i >= 1 && ( s[i-1] == p[j-1] || p[j-1] == '.')){
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
                else{ // p[j-1] is *
                    if(j == 1) continue;
                    if( dp[i][j-2]){
                        dp[i][j] = true;
                    }
                    else{
                        if(i >= 1 && (s[i-1] == p[j-2]|| p[j-2] == '.')){
                            dp[i][j] = dp[i-1][j];
                        }
                    }
                }
            }
        }
        return dp[m][n];
   }        
};


//!!! sol1.1, from sol2, top down, O(mn), O(mn)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m+1, vector<int> (n+1, -1));
        return isMatch(0, 0, s, p, memo);
    }
    bool isMatch(int i, int j, string& s, string& p, vector<vector<int>>& memo){
        if(memo[i][j] != -1) return memo[i][j];
        
        if(j == p.size()){
            memo[i][j] = (i == s.size());
        }
        else{
            bool firstmatch = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
            if(j + 1 < p.size() && p[j+1] == '*'){
                memo[i][j] = isMatch(i, j+2, s, p, memo) || firstmatch && isMatch(i+1, j, s, p, memo);
            }
            else{
                memo[i][j] = firstmatch && isMatch(i+1, j+1, s, p, memo);
            }
        }
        return memo[i][j];
    }
    
};


// // sol1, recursion, cache, O(mn), O(mn)
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> memo(m + 1, vector<int> (n + 1, -1));
        return isMatch(0, 0, s, p, memo);
    }
    bool isMatch(int i, int j, string& s, string& p, vector<vector<int>>& memo) {
        if(memo[i][j] != -1) return memo[i][j];
        
        if(j == p.size()){
            memo[i][j] = (i == s.size());
            return memo[i][j];
        }
        else{ // p is not empty
            if(i == s.size()){
                if(p.size() - j >=  2 && p[j + 1] == '*'){
                    return isMatch(i, j + 2, s, p, memo);
                }
                else{
                    memo[i][j] = false;
                    return false;
                }
            }
            else{ // s is not empty
                if(p.size() - j >= 2 && p[j + 1] == '*'){
                    if(isMatch(i, j + 2, s, p, memo)){
                        memo[i][j] = true;
                        return true;
                    }
                    if(s[i] == p[j] || p[j] == '.'){
                        return isMatch(i + 1, j, s, p, memo);
                    }
                    else{
                        memo[i][j] = false;
                        return false;
                    }
                }
                else{
                    if(s[i] == p[j] || p[j] == '.'){
                        return isMatch(i+1, j+1, s, p, memo);
                    }
                    else{
                        return false;
                    }
                }
                
            }                
        }
        return true;
        
    }    
};


