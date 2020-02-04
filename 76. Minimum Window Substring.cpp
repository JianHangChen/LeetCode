
//! sol1, from gy1, O(s+t), O(s+t)

class Solution {
public:
    string minWindow(string s, string t) {
        
        int minLen = INT_MAX, start = -1;
        unordered_map<char, int> m;
        for(auto c:t){
            m[c]++;
        }

        int len = 0, l = 0;
        for(int r = 0; r < s.size(); r++){
            if(--m[s[r]] >= 0) len++;
            

            while(len == t.size()){
                if(minLen > r - l + 1){
                    minLen = r - l + 1;
                    start = l;
                }
                if(++m[s[l]] > 0) len--;
                l++;
            }

        }
        if(minLen == INT_MAX) return "";
        else return s.substr(start, minLen);

    }
};





