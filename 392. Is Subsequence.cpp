// !!! folloup, 
// time: pre process O(t), check O(slogt)    vs t = 1e5, s = 1e3  (s+t)=1e5 vs (slogt)=5*1e3
// space: O(t)
class Solution {
public:
    unordered_map<char, vector<int>> m;
    void Preprocess(string& t){
        for(int i = 0; i < t.size(); i++){
            m[t[i]].push_back(i);
        }
    }
    // 2 3 4 5
    bool isSubsequence(string s, string t) {
        Preprocess(t);
        int j = 0; // j is the position in t
        for(int i = 0; i < s.size(); i++){
            auto lb = lower_bound(m[s[i]].begin(), m[s[i]].end(), j);
            
            if(lb == m[s[i]].end()) return false;
            
            j = *lb + 1;
        }
        
        return true;
    }
};


//followup, my, very bad, O(2^n)
// s = "axc"
// t = "ahbgdc"
// preprocess
// class Solution {
// public:
//     unordered_set<string> dict;
//     void Process(string& t){
//         string cur = "";
//         DFS(t, 0, cur);
//     }
//     void DFS(string& t, int start, string& cur){
//         if(start == t.size()){
//             dict.insert(cur); return;
//         }
//         for(int i = start; i <t.size(); i++){
//             cur.push_back(t[i]);
//             DFS(t, i+1, cur);
//             cur.pop_back();
//         }
//     }
    
//     bool isSubsequence(string s, string t) {
//         Process(t);
//         if(dict.count(s) > 0) return true;
//         return false;
//     }
// };

//!!! sol1, my O(s+t), O(1), two pointer
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.size(), n = t.size();
        int i = 0, j = 0;
        while(i < m && j < n){
            if(s[i] == t[j]){
                i++; j++;
            }
            else{
                j++;
            }
        }
        return i == m;
    }
};
