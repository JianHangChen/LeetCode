// !!!sol2 from sol2, by count, O(NK)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        
        unordered_map<string, vector<string> > table;
        for(auto str:strs){
            vector<int> count(26,0);
            for(auto c:str){
                count[c - 'a']++;
            }
            string count_string = "";
            for(auto i:count){
                count_string += to_string(i);
            }
            
            table[count_string].push_back(str);
        }
        for(auto ele:table){
            res.push_back( ele.second );
        }
        return res;
        
    }
};


// sol1, from sol1, by sort, O(NKlogK)
class Solution{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs){
        vector<vector<string>> res;

        unordered_map<string, vector<string>> table;
        for(auto str:strs){
            string t = str;
            sort(t.begin(), t.end());
            table[t].push_back(str);
        }
        
        for(auto a:table){
            res.push_back(a.second);
        }
        return res;
    }
};
