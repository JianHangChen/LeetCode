
// sol1,my recursion, O(N*2^N), O(N*2^N)
class Solution {
public:
    vector<string> letterCasePermutation(string &S) {
        vector<string> ans;
        letterCasePermutation(S, ans, 0);
        return ans;
    }
    
    void letterCasePermutation(string &S, vector<string>& ans, int i){
        int n = S.size();
        if(i == n){
            ans.push_back(S);
            return;
        }
        char temp = S[i];
        
        letterCasePermutation(S, ans, i+1);
        
        if('a' <= temp && temp <= 'z'){
            S[i] = temp - 'a' + 'A';
            letterCasePermutation(S, ans, i+1);
            S[i] = temp;
        }
        else if('A' <= temp && temp <= 'Z'){
            S[i] = temp - 'A' + 'a';
            letterCasePermutation(S, ans, i+1);
            S[i] = temp;
        }
        
    }
};
