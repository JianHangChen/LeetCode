
//!!! sol1.1 similar, from gy2, more concise
class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.empty() || strs[0].size() == 0) return "";
        for(int j = 0; j < strs[0].size(); j++){
            for(int i = 0; i < strs.size(); i++){
                if(strs[i].size() <= j || strs[i][j] != strs[0][j]) return strs[i].substr(0, j);
            }
        }
        return strs[0];
    }
};


// sol1, my, O(mn), O(mn)
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         string res;
//         if(strs.empty()) return res;
//         int j = 0;
//         char c;
//         while(true){
//             for(int i = 0; i < strs.size(); i++){
//                 if(j >= strs[i].size() ) return res;

//                 if(i == 0) c = strs[i][j];
//                 else{
//                     if(c != strs[i][j]) return res;
//                 }

//             }
//             res += c;
//             j++;

//         }
//         return res;

//     }
// };


// class Solution:
//     def longestCommonPrefix(self, strs):
//         """
//         :type strs: List[str]
//         :rtype: str
//         """
//         minlen = 0
//         if strs:
//             minlen = len(strs[0])
//         for i in strs:
//             if minlen > len(i):
//                 minlen = len(i)
//         j = 0
//         prefix = ""
//         while(j<minlen):
//             for i in range(1, len(strs)):
//                 if strs[0][j] != strs[i][j]:
//                     return prefix
//             prefix += strs[0][j] 
//             j += 1
//         return prefix
            
//         # test: 1. "radca", "racecar", "rar"
