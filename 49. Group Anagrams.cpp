// !!!sol2 from sol2, by count, O(NK), O(NK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        
        for(auto& str:strs){
            string code = coding(str);
            
            m[code].push_back(str);
        }
        
        for(auto& ele:m){
            ans.push_back(ele.second);
        }
        return ans;
    }
    string coding(string& s){
        string code;
        vector<int> count(26,0);
        
        for(char c:s){
            count[c - 'a']++;
        }
        
        for(int i = 0; i < 26; i++){
            if(count[i]!=0){
                code +=  to_string(count[i]) + string(1,'a' + i);
            }
        }
        return code;
        
    }
};

// // sol1, from sol1, by sort, O(NKlogK), O(NK)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        
        for(auto& str:strs){
            string s = str;
            sort(str.begin(), str.end());
            m[str].push_back(s);
        }
        
        for(auto& ele:m){
            ans.push_back(ele.second);
        }
        return ans;
    }
};
