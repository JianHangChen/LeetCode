class Solution {
public:

    vector<int> splitString(string &s) {
        if(s.size() == 0) return {};
        unordered_map<char, int> max_idx;
        for(int i = 0; i < s.size(); i++){
            max_idx[s[i]] = i;
        }
        vector<int> res;
        int start = 0, max_j = -1;
        for(int i = 0; i < s.size(); i++){
            int j = max_idx[s[i]];
            if(j > max_j) max_j = j;
            
            if(i == max_j){
                int len = max_j - start + 1;
                res.push_back(len);
                start = i + 1;
            }
            
        }

        return res;
        
    }
};

//QAAABCD

// "ABCDEFGHIJKLMN"

// []
// "GKHJDFGVREKHJWGHKRLEWGWRFKKJRWHTGLKTEROPEQWRTQWVFDMZX"
// Output
// [50]
// Expect
// [50,1,1,1]
