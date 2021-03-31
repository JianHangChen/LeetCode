

//! sol2.1, DP, jump, doesn't need hash, from happygirl, O(n^3), O(n)

class Solution {
public:
    int l = 0;
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), hi;
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int lo = 0; lo < n; lo++){ // O(n)
            if(!dp[lo]) continue;
            for(auto& word:wordDict){ // O(n)
                hi = lo + word.size();
                if(hi > n || dp[hi]) continue;
                if(word == s.substr(lo, word.size())) dp[hi] = true; // O(n)
            }            
        }
        
        return dp[n];
    }

};


// //! sol2, DP, from happygirl

class Solution {
public:
    int l = 0;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int lo = 0; lo < n; lo++){
            if(!dp[lo]) continue;
            for(int hi = lo + 1; hi <= n; hi++){
                if(dp[hi]) continue;
                string word = s.substr(lo, hi - lo);
                if(wordset.count(word) > 0){
                    dp[hi] = true;
                }
            }
        }
        return dp[n];
    }
};


// //!!!!! sol1.2, dfs with memorization, O(n^3), O(n)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> memo(n, -1);
        return wordBreak(s, wordDict, memo, 0);
    }    
    
    bool wordBreak(string& s, vector<string>& wordDict, vector<int>& memo, int start) {
        int n = s.size();
        if(start == n) return true;
        else if(memo[start] != -1) return memo[start];
        
        for(string& word:wordDict){
            if(s.substr(start, word.size()) == word && wordBreak(s, wordDict, memo, start + word.size())){
                return memo[start] = true;
            } 
        }
        return memo[start] = false;
    }
};



// !! sol3, memo dfs, O(n^3), O(n+wrodDictsize*wordlength), see video from sol
class Solution {
public:
    unordered_map<int, bool> memo;
    unordered_set<string> dict;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto& word:wordDict) dict.insert(word);
        
        return wordBreak(0, s);
    }
    
    bool wordBreak(int start, string s) {
        if(memo.count(start) > 0) return memo[start];
        
        if(start == s.size()) return true;
        
        for(int i = start; i < s.size(); i++){
            if(dict.count( s.substr(start, i - start + 1) ) > 0){
                bool res = wordBreak(i+1, s);
                if(res){
                    return memo[start] = true;
                }
            }
        }
        return memo[start] = false;
    }

    
};


//my sol1.1, use dfs + hashset, TLE
class Solution {
public:
    int l = 0;
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        for(auto& word:wordDict) l = max(l, (int)word.size());
        return wordBreak(s, wordset, 0);
    }
    
    bool wordBreak(const string& s, unordered_set<string>& wordset, int start){
        if(start == s.size()) return true;
        for(int end = start; end < start + l && end < s.size(); end++){
            string candidate = s.substr(start, end - start + 1);
            if(wordset.count(candidate) > 0){
               if(wordBreak(s, wordset, end+1)){
                   return true;
               }
            }            
        }
        return false;
    }
};


my sol1, LTE, dfs, O(k^n), O(n)
k is the length of worddict, n is len(s)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty()) return true;
        for(string& word:wordDict){
            if(s.substr(0, word.size()) == word){
                if(wordBreak(s.substr(word.size()), wordDict)) return true;
            } 
        }
        return false;
    }
};
