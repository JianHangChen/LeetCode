// sol3, from gy2, double map by vector, O(mn), O(mn)
// class Solution{
// public:
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern){
//         vector<string> ans;
        
//         for(auto& word:words){
//             vector<int> w(26,0), p(26,0);
//             if(word.size() != pattern.size()) continue;
//             int i = 0;
//             for(; i < word.size(); i++){
//                 if( w[word[i] - 'a'] != p[pattern[i] - 'a']) break;
//                 w[word[i] - 'a'] = p[pattern[i] - 'a'] = i + 1;
//             }
//             if(i == word.size()) ans.push_back(word);
//         }
//         return ans;
//     }
// };

//!!! sol2, from gy1, double map, O(mn), O(mn)

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(string& w:words){
            if(match(w, pattern)){
                res.push_back(w);
            }
        }
        return res;
    }
    bool match(string& w, string& p){
        if(w.size() != p.size()) return false;
        unordered_map<char, char> m1, m2; // m1: w->p   m2: p->w
        for(int i = 0; i < w.size(); i++){
            if(m1.count(w[i]) == 0) m1[w[i]] = p[i];
            if(m2.count(p[i]) == 0) m2[p[i]] = w[i];
            if(m1[w[i]] != p[i] || m2[p[i]] != w[i]) return false;
            
        }
        return true;
    }
};


//!!! sol1, my projection, O(nm), O(mn), same as gy3
// n is the length of words, m is the largest length of word.
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        string proj_pattern = project(pattern);
        for(auto& word:words){
            if(proj_pattern == project(word)){
                res.push_back(word);                
            }
        }
        return res;        
    }
    
    string project(string& s){
        string ans = s;
        
        unordered_map<char, char> m;
        int proj_idx = 0;
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(m.count(c) > 0) ans[i] = m[c];
            else{
                ans[i] = 'a' + proj_idx;
                m[c] = ans[i];
                proj_idx++;
            }
            
        }
        
        return ans;
        
    }
};
