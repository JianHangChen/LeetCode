class Solution {
public:
    vector<vector<char>> patterns = {{'(', ')'}, {')', '('}};
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<string> res;
        dfs(s, 0, 0, patterns[0], res);
        
        return res;
    }
    void dfs(string s, int start, int lastRemove, vector<char> pattern, vector<string>& res){
        int n = s.size();
        int cnt = 0;
        for(int i = start; i < n; i++){
            if(s[i] == pattern[0]) cnt++;
            if(s[i] == pattern[1]) cnt--;
            
            if(cnt < 0){
                for(int j = lastRemove; j <= i; j++){
                    if(s[j] == pattern[1] && (j == lastRemove || s[j] != s[j-1])){
                        dfs(s.substr(0, j) + s.substr(j + 1), i, j, pattern, res);                 
                    }
                }
                return;
            }
        }
        reverse(s.begin(), s.end());
        
        if(pattern[0] == ')'){    
            res.push_back(s);
        }
        else{
            dfs(s, 0, 0, patterns[1], res);
        }
        
    }
};
