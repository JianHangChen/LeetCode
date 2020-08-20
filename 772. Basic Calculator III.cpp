// !!! sol1, queue, template could be used in q1, q2, q3
// O(n), O(n)
// https://www.youtube.com/watch?v=ICfk--XA02E

class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        for(char c:s){
            if(c!=' ') q.push(c);
        }
        q.push(' ');
        return cal(q);
    }
    
    int cal(queue<char>& q){
        
        long res = 0, prev = 0, cur = 0;
        char op = '+';
        while(!q.empty()){
            char c = q.front(); q.pop();
            if(c == '('){
                cur = cal(q);
            }
            else if(isdigit(c)){
                cur = cur * 10 + (c - '0');
            }
            else{ //  +-*/) and ' '
                switch(op){
                    case '+': res += prev; prev = +cur; break;
                    case '-': res += prev; prev = -cur; break;
                    case '*': prev *= cur; break;
                    case '/': prev /= cur; break;
                }
                if(c == ')') break;
                cur = 0;
                op = c;
            }
        }
        return res + prev;
    }
};
