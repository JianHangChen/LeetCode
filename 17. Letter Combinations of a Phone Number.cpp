O(n^3*m*4)


sol1, store array and update
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> table = {
            {'2',"abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        
        if(digits.size() == 0) return {};
        
        vector<string> ans = {""};
        for(int i = 0; i < digits.size(); i++){
            helpler(ans, digits[i], table);
        }
        return ans;
    }
    
    void helpler(vector<string> &ans, char i, unordered_map<char, string> &table){
        vector<string> new_ans;
        for(auto s:ans){
            for(int j = 0; j < table[i].size(); j++){
                new_ans.push_back( s + table[i][j]);        
            }
        }
        ans = new_ans;
    }
};

// sol2, deep and add
class Solution{
public:
    vector<string> letterCombinations(string digits){
        if(digits.empty()){
            return {};
        }
        
        vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        
        vector<string> ans;
        
        dfs(digits, "", 0, ans, table);    
        return ans;
    }
    
    void dfs(string &digits, string output, int i, vector<string> &ans, vector<string> &table){
        if(i == digits.size()){
            ans.push_back(output);
            return;
        }
        
        string s = table[ digits[i]-'0' ];
        for(auto c:s){
            dfs(digits, output + c, i + 1, ans, table);
        }
    }
    
};




// sol3, iteratively

class Solution{
public:
    vector<string> letterCombinations(string digits){
        if(digits.empty()) return {};
        vector<string> res = {""};
        vector<string> table = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < digits.size(); i++){
            string str = table[digits[i] - '0'];
            
            vector<string> temp_res;
            for(auto output:res){
                for(int j = 0; j < str.size(); j++){
                    temp_res.push_back(output + str[j]);
                }
            }
            res = temp_res;
        }
        return res;
    }    
};

