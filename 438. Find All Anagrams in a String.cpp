//!!! sol2, sliding window, form sol2,  O(n+k), O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int ns = s.size(), np = p.size();
        if(np > ns) return res;
        int i = 0;
        vector<int> count_s(26, 0), count_p = count_s;
        for(int i = 0; i < np; i++){
            count_s[s[i] - 'a']++;
            count_p[p[i] - 'a']++;
        }
        
        while(i + np - 1 < ns){
            if(matches(count_s, count_p)) res.push_back(i);
            i++;
            if(i + np - 1 < ns){
                count_s[s[i-1] - 'a']--;
                count_s[s[i + np - 1] - 'a']++;
            }
        }
        return res;
    }
    
    bool matches(vector<int>& count_s, vector<int>& count_p){
        for(int i = 0; i < 26; i++){
            if(count_p[i] != count_s[i]) return false;
        }
        return true;
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
