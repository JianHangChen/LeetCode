// sol1, my, O(A(N, L) or 26^L * L), O(NL), L is the length of string
// words are the same? reuse the same word
class Solution {
public:
    struct tNode{
        tNode* next[26] = {NULL};
        string word = "";
    };
    
    void insert(string& s){
        tNode* cur = root;
        for(char c:s){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new tNode();
            }
            cur = cur->next[c-'a'];
        }
        cur->word = s;
    }
    tNode* root;

    vector<vector<string>> res;
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words[0].size();
        // build trie
        root = new tNode();
        for(auto& word:words) insert(word);
        
        
        // get answer
        vector<string> ans(n, string(n, ' '));
        dfs(n, 0, ans);
        return res;    
    }
    
    void dfs(int n, int start, vector<string>& ans){
        if(start == n){
            res.push_back(ans);
            return; // remember to return!!!
        }
        
        string prefix = ans[start].substr(0, start);
        for(auto& w:wordWithPrefix(prefix)){
            ans[start] = w; // fill horizontal with w
            for(int i = start + 1; i < n; i++) ans[i][start] = w[i]; // fill vertical with w
            dfs(n, start + 1, ans);
        }
    }
    
    vector<string> wordWithPrefix(string& prefix){
        vector<string> v;
        tNode* cur = root;
        for(char c:prefix){
            if(cur->next[c-'a'] == NULL) return {};
            cur = cur->next[c-'a'];
        }
        findAllWord(v, cur);
        return v;
    }
    
    void findAllWord(vector<string>& v, tNode* cur){
        if(cur->word.size() > 0) v.push_back(cur->word);
        for(int i = 0; i < 26; i++){
            if(cur->next[i] != NULL){
                findAllWord(v, cur->next[i]);
            }
        }
    }
    
};
