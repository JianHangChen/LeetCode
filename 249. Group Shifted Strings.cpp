// !!! my, O(n), O(n)
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for(string& str:strings){
            m[get_str(str)].push_back(str);
        }
        
        for(auto& item:m){
            res.push_back(item.second);
        }
        return res;
        
    }
    string get_str(string& str){
        if(str.empty() || str[0] == 'a') return str;
        int offset = str[0] - 'a';
        string res = str;
        for(int i = 0; i < res.size(); i++){
            res[i] -= offset;
            if(res[i] < 'a') res[i] += 26;
        }
        return res;
    }
    
};
