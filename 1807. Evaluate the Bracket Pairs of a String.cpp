class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> m;
        for(vector<string> k:knowledge){
            m[k[0]] = k[1];
        }
        string res = "";
        int i = 0, n = s.length();
        while(i < n){
            if(s[i] != '('){ // isalpha(s[i])
                res += s[i++];
            }
            else{
                string key;
                int j;
                for( j = i + 1; j < n && s[j] != ')'; j++){
                    // key.push_back(s[j]);
                    key += s[j];
                }
                
                if(m.count(key) > 0){
                    res.append(m[key]); //  res = res + m[key] // c++ += append
                }
                else{
                    res += "?";
                }
                i = j + 1;                
            }
        }
        return res;
    }
};
