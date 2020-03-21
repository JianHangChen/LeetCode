//!!! sol3, dp, form gy3, O(n^2), O(n)
class Solution{
public:
    int minCut(string s){
        int n = s.size();
        if(n == 0) return 0;
        vector<int> dp(n + 1); //dp[i] means from [0, i-1] the minimum cuts
        for(int i = 0; i <= n; i++) dp[i] = i-1;
        
        for(int i = 0; i <= n; i++){
            for(int len = 0; i - len >= 0 && i + len < n && s[i-len] == s[i+len]; len++){
                dp[i+len+1] = min(dp[i+len+1], 1 + dp[i-len]);
            }
            for(int len = 0; i - len >= 0 && i + len + 1 < n && s[i-len] == s[i+len+1]; len++){
                dp[i+len+2] = min(dp[i+len+2], 1 + dp[i-len]);
            }            
        }
        return dp[n];
    }
};

// !! sol2, dp, from gy1, O(n^2), O(n^2)
// class Solution {
// public:
//     int minCut(string s) {
//         int n = s.size();
//         vector<int> dp(n);        
//         vector<vector<bool>> isPalindrome(n, vector<bool> (n, false));
//         for(int end = 0; end < n; end++){
//             dp[end] = end;
//             for(int start = 0; start <= end; start++){
//                 if(s[start] == s[end] && (end - start <= 2 || isPalindrome[start+1][end-1])){
//                     isPalindrome[start][end] = true;
//                 }
//             }
//         }
        
//         // [0, i] -> [0,j-1], [j, i]
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j <= i; j++){
//                 if(isPalindrome[j][i]){
//                     if(j == 0) dp[i] = 0;
//                     else dp[i] = min(dp[i], dp[j-1] + 1);                
//                 }
//             }
//         }
//         return dp[n-1];        
//     }
// };

// sol1, my, tle, O(2^(n-1))
// class Solution {
// public:
//     int minCut(string s) {
//         int n = s.size(), res = n - 1;
//         vector<vector<bool>> isPalindrome(n, vector<bool> (n, false));
//         for(int end = 0; end < n; end++){
//             for(int start = 0; start <= end; start++){
//                 if(s[start] == s[end] && (end - start <= 2 || isPalindrome[start+1][end-1])){
//                     isPalindrome[start][end] = true;
//                 }
//             }
//         }
        
//         backtrack(s, 0, 0, res, isPalindrome);
//         return res;
        
//     }
//     void backtrack(string& s, int start, int cuts, int& res, vector<vector<bool>>& isPalindrome){
//         if(start == s.size()){
//             res = min(res, cuts - 1);
//             return;
//         }
//         for(int end = start; end < s.size(); end++){
//             if(isPalindrome[start][end]){
//                 backtrack(s, end+1, cuts+1, res, isPalindrome);
//             }
//         }
        
//     }
    
// };
