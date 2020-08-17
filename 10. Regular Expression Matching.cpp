

//!!!! sol2.1 from sol2, bottom-up, O(mn), O(mn), sol2 is enough
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<int> dp(n+1, 0); // dp[i][j]: ismatch for s[i:], p[j:]
        // dp[i][j] = 
        // 1. p[j+1] is not *:  s[i] and p[j] should match and then look for dp[i+1][j+1] 
        // 2. p[j+1] is *:
        //    2.1.  * is nothing, dp[i][j+2]
        //    2.2.  * is replication, s[i] and p[j] should match and then look for dp[i+1][j+2] 
        
        for(int i = m; i >= 0; i--){
            vector<int> dp2(n+1,0);
            if(i == m) dp2[n] = 1;  // s[m:] == p[n:] == ""
            for(int j = n - 1; j >= 0; j--){
                bool firstmatch = (i < m) &&  (s[i] == p[j] || p[j] == '.');
                if(j+1 >= n || p[j+1] != '*'){
                    dp2[j] = firstmatch && dp[j+1]; 
                }
                else{ // j < n - 1 && p[j+1] == '*'
                    dp2[j] = dp2[j+2] || (firstmatch && dp[j]);
                }
            }
            dp = dp2;
        }
        return dp[0];
    }
};




//!!!! sol2 from sol2, bottom-up, O(mn), O(mn), use this
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0)); // is match for s[i:], p[j:]
        dp[m][n] = 1; // s[m:] == p[n:] == ""
        // dp[i][j] = 
        // 1. p[j+1] is not *:  s[i] and p[j] should match and then look for dp[i+1][j+1] 
        // 2. p[j+1] is *:
        //    2.1.  * is nothing, dp[i][j+2]
        //    2.2.  * is replication, s[i] and p[j] should match and then look for dp[i+1][j+2] 
        
        for(int i = m; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                bool firstmatch = (i < m) &&  (s[i] == p[j] || p[j] == '.');
                if(j+1 >= n || p[j+1] != '*'){
                    dp[i][j] = firstmatch && dp[i+1][j+1]; 
                }
                else{ // j < n - 1 && p[j+1] == '*'
                    dp[i][j] = dp[i][j+2] || firstmatch && dp[i+1][j];
                }
            }
        }
        
        return dp[0][0];
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
