
//!!! from gy2, O(n), O(1)
class Solution{
public:
    int calculate(string s){
        int n = s.size();
        long res = 0, pre = 0, cur = 0;
        char op = '+';
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                cur = cur * 10 + s[i] - '0';
            }
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == n - 1){
                if(op == '+') pre += cur;
                else if(op == '-') pre -= cur;
                else if(op == '*') pre *= cur;
                else if(op == '/') pre /= cur;
                if(s[i] == '+' || s[i] == '-'){
                    res += pre;
                    if(i == n) break;
                    pre = 0;
                }
                op = s[i];
                cur = 0;                
            }

        }
        return res;
        
    }
    
};
