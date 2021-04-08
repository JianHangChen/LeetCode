
//!!! sol2, from sol3, rolling hash, ROBIN KARP, O(m), O(1)


class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int m = haystack.size(), n = needle.size();
        if(m < n) return -1;
        long long MOD = 2e9+1; //it's a safe number for () * 26, still < LONG LONG_MAX
        long long hHash = 0, nHash = 0;//  USE LONG LONG FOR HASH
        for(int i = 0; i < n; i++){
            hHash = (hHash * 26 % MOD + haystack[i] - 'a')%MOD;
            nHash = (nHash * 26 % MOD + needle[i] - 'a')%MOD;
        }
        // h = h * 26 + c
        // h2 = c *26
        // FOR n = 2-> c^1
        // FOR n = N, c^(N-1)
        long long pow26 = 1;
        for(int i = 1; i < n; i++) pow26 = pow26 * 26 % MOD;        
        
        for(int i = 0; i + n <= m; i++){
            if(hHash == nHash){
                if(haystack.substr(i, n) == needle) return i;
            }
            if(i + n == m) break;
            hHash = ((hHash - (haystack[i] - 'a') * pow26 + MOD) % MOD * 26 +  haystack[i+n] - 'a') % MOD; // CAREFULLY use "+ MOD) % MOD"
        }
        return -1;
        
    }
};



//! sol1, my, brute force, O(mn), O(1)
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         if(needle.empty()) return 0;
//         int m = haystack.size(), n = needle.size();
//         for(int i = 0; i < m; i++){
//             if(haystack.substr(i, n) == needle) return i;
//         }
//         return -1;
        
        
//     }
// };


class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """       

        # # sol1: my O(n*h)
        if needle == "":
            return 0
        hay_len = len(haystack)
        n_len = len(needle)
        for i in range(hay_len):
            for j in range(n_len):
                if i + j >= hay_len:
                    return -1
                if haystack[i+j] != needle[j]:
                    break
                if j == n_len-1:
                    return i
        return -1
        
        # sol2: using string list implementation, elegant. still O(n*h)
        
        for i in range(len(haystack)-len(needle)+1):
            if haystack[i:i+len(needle)] == needle:
                return i
        return -1

 # sol3, KMP
# from http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
# https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    def strStr(self, haystack, needle):
        hay_len = len(haystack)
        n_len = len(needle)
        
        if (n_len == 0):
            return 0
        
        table = self.get_needle_match_table(needle)        
        
        i = 0
        j = 0
        while i < (hay_len - n_len + 1):
            
            while j < n_len:
                if haystack[i+j] == needle[j]:
                    j += 1
                    if j == n_len:
                        return i                    
                else:
                    break
                
            if j == 0:
                i += 1
            else:
                i = i + j - table[j-1]
                j = table[j-1]
        return -1
    
    def get_needle_match_table(self,needle):
        l = 0
        n = len(needle)
        i = 1
        table = [0]
        while i < n:
            if needle[i] == needle[l]:
                l += 1
                i += 1
                table.append(l)
            else:
                if l == 0:
                    table.append(l)
                    i += 1
                else: #here is the tricky part the same as the search part
                    l = table[l-1]
        return table
