//!!! sol2, memorized dfs, from gy1, 
// O(w*d + 2^n + n^3), O(wd + 2^n*n)
// n: s.size,   w: wordDict.size, d: longest word length

class Solution {
public:
    unordered_map<int, vector<string>> memo;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return wordBreak(0, s, wordDict);
    }
    vector<string> wordBreak(int start, string& s, vector<string>& wordDict) {
        if(start == s.size()) return {""};
        if(memo.count(start) > 0) return memo[start];
        
        vector<string> res;
        for(auto& word:wordDict){
            if(s.substr(start, word.size()) == word){
                auto rem = wordBreak(start + word.size(), s, wordDict);
                for(auto& path:rem){
                    res.push_back(word + (path.size() == 0 ? "" : " ") + path);
                }
            }
        }
        return memo[start] = res;
        
    }
};

   
// sol1, my, trie
// O(w*d + 2^n), O(wd)
// n: s.size,   w: wordDict.size, d: longest word length
class Solution {
public:
    struct trieNode{
        int val;
        trieNode* next[26];
        trieNode(int x):val(x){
            for(int i = 0; i < 26; i++) next[i] = NULL;
        }
    };
    
    void addString(string& str, trieNode* root){
        trieNode* cur = root;
        
        for(char c:str){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new trieNode(-1);
            }
            cur = cur->next[c-'a'];
        }
        cur->val = 1; // 1 is end
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        trieNode* root = new trieNode(-1);
        
        for(string& str:wordDict){
            addString(str, root);
        }
        vector<string> res;
        dfs(0, s, root, "", res);
        return res;
    }
    
    void dfs(int start, string& s, trieNode* root, string path, vector<string>& res){
        if(start == s.size()){
            path.pop_back();
            res.push_back(path);
            return;
        }
        trieNode* cur = root;
        for(int i = start; i < s.size(); i++){
            if(cur->next[ s[i] - 'a'] == NULL) return;
            cur = cur->next[s[i] - 'a'];
            if(cur->val == 1){
                dfs(i+1, s, root, path + s.substr(start, i - start + 1) + " ", res);
            }
        }
        return;
        
    }
    
};
