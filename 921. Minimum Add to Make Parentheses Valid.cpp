//!!! sol1, O(n), O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int i = 0;
        int countLeft = 0, res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                countLeft++;
            }
            else{
                if(countLeft > 0){
                    countLeft--;
                }
                else{
                    res++;
                }
            }
        }
        return res + countLeft;
    }
};

// sol2, O(N), O(N)

class Solution {
public:
    int minAddToMakeValid(string S) {
        int n = S.size(), res = 0;
        stack<char> s;
        for(int i = 0; i < n; i++){
            char c = S[i];
            if(c == '('){
                s.push(c);
            }
            else{ //c==')'
                if(s.empty() || s.top() == ')'){
                    res++;
                }
                else{
                    s.pop();
                }
            }
        }
        res += s.size();
        return res;
    }
};
