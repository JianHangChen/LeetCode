// !!! sol2, from wp
// https://github.com/wisdompeak/LintCode/tree/master/DP/324.Regular-Expression-Search
class Solution {
public:
    vector<bool> isMatch(string &formatString, vector<string> &queryStrings) {
        vector<bool> res;
        for(auto& query:queryStrings){
            int m = query.size(), n = formatString.size();
            if(n > 0 && formatString.back() == '$'){
                res.push_back( regex_mat(query, formatString.substr(0, n-1)) );
            }
            else{
                bool found = false;
                for(int l = 0; l <= m; l++){
                    if(regex_mat(query.substr(0, l), formatString)){
                        found = true;
                        break;
                    }
                }
                res.push_back(found);
            }
        }
        return res;
    }
    
    bool regex_mat(const string& query, const string& f){
        cout << f << endl;
        int m = query.size(), n = f.size();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        // query[i:]  f[j:]
        dp[m][n] = true;
        for(int i = m; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                bool firstmatch = (i < m) && (f[j] == '.' || query[i] == f[j]);
                
                if(j < n - 1 && f[j+1] == '*'){
                    dp[i][j] = dp[i][j+2] || firstmatch && dp[i+1][j];
                }
                else if(j < n - 1 && f[j+1] == '?'){
                    dp[i][j] = dp[i][j+2] || firstmatch && dp[i+1][j+2];
                }
                else if(j < n - 1 && f[j+1] == '+'){
                    dp[i][j] = firstmatch && (dp[i+1][j+2] || dp[i+1][j]);
                }
                else{ // j == n - 1 || f[j+1] != '*' +  ? 
                    if(f[j] == '^') dp[i][j] = i == 0 && dp[i][j+1];
                    else dp[i][j] = firstmatch && dp[i+1][j+1];
                }
                
                if(j == 0 && dp[i][j]) return true;
            }
        }
        
        
        return dp[0][0];
    }
    
};







// #include <regex>
// class Solution {
// public:
//     /**
//      * @param formatString: the format string
//      * @param queryStrings: the query strings
//      * @return: judge isMatch
//      */
//     vector<bool> isMatch(string &formatString, vector<string> &queryStrings) {
//         vector<bool> res;
//         regex f(formatString);
//         for(auto& queryString:queryStrings){
//             cout << queryString;
//             res.push_back(regex_match(queryString, f));
//         }
//         return res;
//     }
// };
