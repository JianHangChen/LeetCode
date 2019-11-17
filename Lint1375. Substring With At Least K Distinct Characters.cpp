class Solution {
public:
    /**
     * @param s: a string
     * @param k: an integer
     * @return: the number of substrings there are that contain at least k distinct characters
     */
    long long kDistinctCharacters(string &s, int k) {
        int n = s.size();
        unordered_map<char, int> m;
        
        long long res = 0;
        int i = 0, j = 0;
        int count = 0;
        
        
        while(j <= n && i < n){
            
            if(count < k){
                if(j == n) break; // the corner case about j is to add the 
                if(m.count(s[j]) == 0 || m[s[j]] == 0) count++; // !!! m[s[j]] == 0 means the val is 0, m.count(s[j]) == 0 means s[j] hasn't shown before
                m[s[j]]++;
                j++;
            }
            else{
                res += (n - j + 1);
                m[s[i]]--;
                if(m[s[i]] == 0){
                    count--; 
                }
                i++;
            }
        }

        
        return res;
        
    }
};
