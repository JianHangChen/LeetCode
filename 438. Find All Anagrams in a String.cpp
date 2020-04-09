//!!! sol2, sliding window, form sol2,  O(n+k), O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        
        vector<int> count_p(26,0), count_s = count_p;
        for(char c:p) count_p[c-'a']++;
        for(int i = 0; i < k && i < n; i++) count_s[s[i] - 'a']++;
        vector<int> res;
        
        
        for(int i = 0; i + k <= n; i++){
            if(i != 0){
                count_s[s[i-1] - 'a']--;
                count_s[s[i+k-1] - 'a']++;
            }
            int j = 0;
            for(; j < 26; j++){
                if(count_s[j] != count_p[j]) break;
            }
            if(j == 26) res.push_back(i);
        }
        return res;
        
        
    }
};


// sol1, presum, O(n), O(n)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), k = p.size();
        
        vector<int> count_p(26,0);
        for(char c:p) count_p[c-'a']++;
        
        vector<vector<int>> presum(n+1, vector<int> (26,0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 26; j++){
                presum[i+1][j] = presum[i][j];
            }
            presum[i+1][s[i]-'a']++;
        }
        vector<int> res;
        
        for(int i = 0; i + k <= n; i++){
            int j = 0;
            for(; j < 26; j++){
                if( presum[i+k][j] - presum[i][j] != count_p[j]) break;
            }
            if(j == 26) res.push_back(i);
        }
        return res;
        
        
    }
};
