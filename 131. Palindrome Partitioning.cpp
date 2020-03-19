// should repeat




//!!!! sol2, from gy3, backtracking + dp, O(2^(n-1)), O(2^(n-1)*n)
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool> (n, false));
        
        for(int end = 0; end < n; end++){
            for(int start = 0; start <= end; start++){
                if(s[start] == s[end] && ( end - start <= 2 || isPalindrome[start+1][end-1]) ) {
                    isPalindrome[start][end] = true;                
                }
            }
        }
        
        backtrack(s, 0, out, res, isPalindrome);
        return res;
    }
    void backtrack(string& s, int start, vector<string>& out, vector<vector<string>>& res, vector<vector<bool>>& isPalindrome){
        if(start == s.size()){
            res.push_back(out);
            return;
        }
        for(int end = start; end < s.size(); end++){
            if(isPalindrome[start][end]){
                out.push_back(s.substr(start, end - start + 1));
                backtrack(s, end+1, out, res, isPalindrome);
                out.pop_back();
            }
        }
    }
    
};


//!! sol1, from gy1, backtracking, O(2^(n-1)*n), O(2^(n-1)*n)
// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> res;
//         vector<string> out;
//         backtrack(s, 0, out, res);
//         return res;
//     }
    
//     void backtrack(string& s, int start, vector<string>& out, vector<vector<string>>& res){
//         if(start == s.size()){
//             res.push_back(out);
//             return;
//         }
//         for(int end = start; end < s.size(); end++){
//             string cur = s.substr(start, end - start + 1);
//             if(isPalindrome(cur)){
//                 out.push_back(cur);
//                 backtrack(s, end+1, out, res);
//                 out.pop_back();
//             }
//         }    
//     }
    
//     bool isPalindrome(string& s){
//         int i = 0, j = s.size()-1;
//         while(i < j){
//             if(s[i++] != s[j--]) return false;
//         }
//         return true;
//     }
    
// };

