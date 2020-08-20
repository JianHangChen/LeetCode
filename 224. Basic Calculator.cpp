// !!! sol2, queue, template could be used in q1, q2, q3
// O(n), O(n)
// https://www.youtube.com/watch?v=ICfk--XA02E

class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        for(char c:s){
            if(c!=' ') q.push(c);
        }
        q.push(' '); // !!! 3+3 add extra ' ' to execute last +
        return calculate(q); 
    }
    int calculate(queue<char>& q){
        int res = 0,  prev = 0, cur = 0;  // res maintain result, prev maintain operand1, cur maintain operand2
        char op = '+';
        while(!q.empty()){
            char c = q.front(); q.pop();
            if(c == '(') cur = calculate(q);
            else if(isdigit(c)){
                cur = 10 * cur + (c - '0');
            }
            else{
                switch(op){
                    case '+': res += prev; prev = +cur; break;
                    case '-': res += prev; prev = -cur; break;
                }
                if(c == ')') break;
                cur = 0;
                op = c;
            }
        }
        return res + prev; //!!!! remember to execute last one
    }
};


// ! sol1, from ch9 or sol2, O(n), O(n)

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int> st;
        int res = 0, number = 0, sign = 1;
        for(int i = 0; i <= n; i++){
            if(i == n) res += sign * number;
            else{ // i < n
                if(s[i] == ' ') continue;
                if(s[i] == '('){
                    st.push(res);
                    st.push(sign);
                    res = 0;
                    number = 0;
                    sign = 1;
                }
                else if(isdigit(s[i])){
                    number = number * 10 + (s[i] - '0');                        
                }
                else if(s[i] == '-' || s[i] == '+'){
                    res += sign * number;
                    number = 0;
                    sign = (s[i] == '-') ? -1 : 1;
                }
                else if(s[i] == ')'){
                    res += sign * number;
                    number = 0;
                    sign = st.top(); st.pop();
                    res = res * sign + st.top(); st.pop();
                }
            }
        }
        return res;
    }
};


// // sol1, from sol1, reverse stack, fail to write
// class Solution {
// public:
//     int calculate(string s) {
//         reverse(s.begin(), s.end());
//         istringstream i(s);
//         int val;
//         while(i >> val){
            
            
//         }
        
//         stack<int> st;
//         for(int i = s.size() - 1; i >= 0; i--){
//             if(s[i] == ' ') continue;
//             if(s[i] != '('){
//                 if(s[i] == ')') st.push(s[i]);
//                 else if(isdigit(s[i])){
//                     int cur = 0;
//                     int n = 0;
//                     while(i >= 0 && isdigit(s[i])){
//                         cur += pow(10, n) * (s[i--] - '0');
//                     }
//                     st.push(cur);                    
//                 }
//                 else{
//                     if(s[i] == '-') st.top() = -st.top();
//                 }
//             }
//             else{
//                 excute(st);
                
//             }
            
            
//             if(s[i] != '(') st.push(s[i]);
//             else{
//                 int res = 0, cur = 0;
//                 char op = '+';
//                 while(st.top() != ')'){
//                     while(isdigit(st.top())){
//                         cur = cur * 10 + st.top() - '0'; st.pop();                    
//                     }
//                     if(op == '+') res += cur;
//                     else if(op == '-') res -= cur;
//                     cur = 0;
//                     if(st.top() == '+' || st.top() == '-'){
//                         op = st.top(); st.pop();
//                     }
//                 }
//                 st.pop();
//                 st.push(int);
//             }
//         }
        
//         int res = 0; 
        
        
//         return calculate(i, 0);
//     }
// };
