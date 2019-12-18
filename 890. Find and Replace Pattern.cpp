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

// sol2, from gy1, double map, O(mn), O(mn)

// class Solution{
// public:
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern){
//         vector<string> ans;
        
//         for(auto& word:words){
//             unordered_map<char, char> m1, m2;
//             if(word.size() != pattern.size()) continue;
            
//             int i = 0; 
//             while(i < word.size()){
//                 if(m1.count(word[i]) > 0){
//                     if(m1[word[i]] != pattern[i]){
//                         break;
//                     }
//                 }
//                 else{
//                     m1[word[i]] = pattern[i];
//                 }
                
//                 if(m2.count(pattern[i]) > 0){
//                     if(m2[pattern[i]] != word[i]){
//                         break;
//                     }
//                 }
//                 else{
//                     m2[pattern[i]] = word[i];
//                 }                
//                 i++;
//             }
//             if(i == word.size()) ans.push_back(word);
//         }
//         return ans;
//     }
// };


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
