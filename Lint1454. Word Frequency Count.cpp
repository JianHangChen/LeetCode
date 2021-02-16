class Solution {
public:
    /**
     * @param s: The string s
     * @param excludeList: The excludeList
     * @return: Return the most frequent words
     */
    vector<string> getWords(string &s, vector<string> &excludeList) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(isalpha(s[i])){
                if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
            }
            else{
                s[i] = ' ';
            }
        }
        
        stringstream ss(s);
        string cur;
        unordered_set<string> excludeSet(excludeList.begin(), excludeList.end());
        unordered_map<string, int> m;
        
        int highest_count = 0;
        while(ss >> cur){
            if(excludeSet.count(cur) == 0){
                m[cur]++;
                highest_count = max(highest_count, m[cur]);
                
            }
        }
        vector<string> res;
        for(auto& item:m){
            if(item.second == highest_count){
                res.push_back(item.first);
            }
        }
        return res;
        
    }
};

class Solution {
public:
    /**
     * @param s: The string s
     * @param excludeList: The excludeList
     * @return: Return the most frequent words
     */
    vector<string> getWords(string &s, vector<string> &excludeList) {
        int n = s.size();
        unordered_set<string> exset;
        unordered_map<string, int> m;
        for(auto& word:excludeList)  exset.insert(to_lowercase(word));
        int highest_count = 0;
        
        string cur = "";
        for(int i = 0; i <= n; i++){
            if( (i == n || !isalpha(s[i]) ) && cur.size() > 0){
                
                if(exset.count(cur) == 0){
                    cur = to_lowercase(cur);
                    m[cur]++;
                    highest_count = max(highest_count, m[cur]);
                }
                cur = "";
            }
            else {
                cur.push_back(s[i]); // cur+s[i]
            }
            
        }
        vector<string> res;
        for(auto& item:m){
            if(item.second == highest_count) res.push_back(item.first); 
        }
        return res;
    }


    string to_lowercase(string s){
        for(int i = 0; i < s.size(); i++){
             if(s[i] <= 'Z' && s[i] >= 'A') s[i] = s[i] - 'A' + 'a';
        }
        return s;
    }
};
