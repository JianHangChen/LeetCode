// O(2^n), O(n)
class Solution {
public:
    vector<vector<char>> patterns = {{'(', ')'}, {')', '('}};
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        dfs(s, 0, 0, patterns[0], res);
        return res;
    }
    void dfs(string s, int start, int last_parentheses, vector<char> pattern, vector<string>& res){
        int n = s.size();
        int cnt = 0;
        for(int i = start; i < n; i++){
            if(s[i] == pattern[0]) cnt++;
            if(s[i] == pattern[1]) cnt--;
            if(cnt < 0){
                for(int j = last_parentheses; j <= i; j++){
                    if(s[j] == pattern[1] && (j == last_parentheses || s[j] != s[j-1])){
                        dfs(s.substr(0, j) + s.substr(j+1), i, j, pattern, res);                        
                    }
                }
                return; // !!! important to return, since cnt < 0, so all the valid strings are new_string
            }
        }
        reverse(s.begin(), s.end());
        
        if(pattern[0] == '('){
            dfs(s, 0, 0, patterns[1], res);            
        }
        else{
            res.push_back(s);        
        }
        
        
    }
};
