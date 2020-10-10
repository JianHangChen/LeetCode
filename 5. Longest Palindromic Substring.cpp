// !!! sol2, expanding, O(n^2), O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= 1; j++){
                int start = i, end = start + j; 
                while(start >= 0 && end < n){
                    if(s[start] != s[end]) break;
                    if(end - start + 1 > ans.size()){
                        ans = s.substr(start, end - start + 1);
                    }
                    start--; end++;
                }
   
            }
        }
        return ans;
    }
};

// sol1, brute force, O(n^3)
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         for(int l = n; l > 0; l--){
//             for(int i = 0; i + l - 1 < n; i++){
//                 if(isPalindrome(s, i, i+l-1)) return s.substr(i, l);   
//             }
//         }
//         return "";        
//     }
//     bool isPalindrome(string& s, int i, int j){
//         while(i < j){
//             if(s[i++] != s[j--]) return false;
//         }
//         return true;
//     }
    
// };


// class Solution:
//     #sol1, my, O(n^3), very slow
//     def longestPalindrome(self, s: str) -> str:
//         def isPalindrome(string):
//             return string == string[::-1]
//         substring = ""
//         maxl = 0
//         for i in range(len(s)):
//             for j in range(i, len(s)):
//                 if j + 1 - i > maxl:
//                     if isPalindrome(s[i:j+1]):
//                         maxl = j + 1 - i
//                         substring = s[i:j+1]
//         return substring
    
//     #sol2, my, O(n^2), O(1), after hint
//     def longestPalindrome(self, s: str) -> str:        
//         def expend(i,j):
//             while i >= 0 and j < len(s):
//                 if s[i] == s[j]:
//                     i -= 1
//                     j += 1
//                 else:
//                     break
//             l = j - i - 1
//             return i + 1, j - 1, l
        
//         maxl = maxi = maxj = 0
                
//         for i in range(len(s)):
//             ii, jj, l = expend(i,i)
//             if l > maxl:
//                 maxi = ii; maxj = jj; maxl = l;
                
//             ii, jj, l = expend(i,i+1)
//             if l > maxl:
//                 maxi = ii; maxj = jj; maxl = l;
                
//         return s[maxi:maxj + 1]
            
            
