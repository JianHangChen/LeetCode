// my, sol2, dfs+memo, O(n), O(n)
class Solution {
public:
    vector<int> memo;
    int n;
    int numDecodings(string s) {
        n = s.size();
        memo.resize(n, -1);
        return dfs(s, 0);
    }
    
    
    int dfs(string& s, int i){
        if(i == n) return 1;
        else if(i > n) return 0;
        
        if(memo[i] != -1) return memo[i];
        
        int res = 0;        
        if(s[i] != '0'){
            // one digit
            res += dfs(s, i+1);

            // two digit
            if(stoi(s.substr(i, 2)) <= 26) res += dfs(s, i+2);            
        }
        return memo[i] = res;
    }
};

//!! sol1.1, my dp, O(n), O(1)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(2, 0);
        // dp[i][0] means from [0, i], [0] means i not connected to i - 1
        if(s[0] != '0'){
            dp[0] = 1;
        }
        
        for(int i = 1; i < n; i++){
            vector<int> dp2(2, 0);
            
            // calculate dp[i][0] (not connected to i-1)
            if(s[i] != '0'){
                dp2[0] = dp[0] + dp[1]; 
            }
            
            // calculate dp[i][1] (connected to i-1)
            if(s[i-1] != '0' && stoi(s.substr(i-1, 2)) <= 26){
                dp2[1] = dp[0];                
            } 
            dp = dp2;
        }
        return dp[0] + dp[1];
    }
};


// !!! sol1, my dp, O(n), O(n)
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (2, 0));
        // dp[i][0] means from [0, i], [0] means i not connected to i - 1
        if(s[0] != '0'){
            dp[0][0] = 1;
        }
        
        for(int i = 1; i < n; i++){
            // calculate dp[i][0] (not connected to i-1)
            if(s[i] != '0'){
                dp[i][0] = dp[i-1][0] + dp[i-1][1]; 
            }
            
            // calculate dp[i][1] (connected to i-1)
            if(s[i-1] != '0' && stoi(s.substr(i-1, 2)) <= 26){
                dp[i][1] = dp[i-1][0];                
            } 

        }
        return dp[n-1][0] + dp[n-1][1];
    }
};
