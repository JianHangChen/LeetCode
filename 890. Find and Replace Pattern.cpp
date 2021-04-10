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
        string pProj = project(pattern);
        
        for(string& w:words){
            if(project(w) == pProj){
                res.push_back(w);
            }
        }
        return res;
    }
    
    string project(string& w){
        char base = 'a';
        string ans = w;
        unordered_map<char, char> m;
        for(int i = 0; i < w.size(); i++){
            if(m.count(w[i]) == 0){
                m[w[i]] = base++;
            }
            ans[i] = m[w[i]];
        }
        return ans;
    }
    
};
