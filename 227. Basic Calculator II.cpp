// !!! sol3, queue, template could be used in q1, q2, q3
// O(n), O(n)
// https://www.youtube.com/watch?v=ICfk--XA02E
class Solution{
public:
    int calculate(string s){
        queue<char> q;
        for(char c:s){
            if(c !=' ') q.push(c);
        }
        q.push(' ');
        return cal(q);        
    }
    int cal(queue<char>& q){
        int res = 0, prev = 0, cur = 0;
        char op = '+';
        while(!q.empty()){
            char c = q.front(); q.pop();
            if(isdigit(c)){
                cur = cur * 10 + (c - '0');
            }
            else{
                switch(op){
                    case '+': res += prev; prev = +cur; break;
                    case '-': res += prev; prev = -cur; break;
                    case '*': prev *= cur; break;
                    case '/': prev /= cur; break;
                }
                cur = 0;
                op = c;
            }            
        }
        return res + prev;
    }
};

!!sol2,  use istringstream
O(n), O(n)
/ from https://www.jiuzhang.com/solution/basic-calculator-ii/#tag-other-lang-cpp
class Solution{
public:
    int calculate(string s){
        istringstream i(s);
        vector<long> nums;
        char op = '+';
        long val;
        while(i>>val){
            if(op == '+') nums.push_back(val);
            if(op == '-') nums.push_back(-val);
            if(op == '*') nums.back() *= val;
            if(op == '/') nums.back() /= val;
            i >> op;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

//!sol1.1 from gy2, O(n), O(m), m is the total number
class Solution{
public:
    int calculate(string s){
        int n = s.size();
        vector<long> nums;
        char op = '+';
        for(int i = 0; i < n; i++){
            while(i < n && s[i] == ' ') i++; //remove space
            long cur = 0;
            while(i < n && isdigit(s[i])){
                cur = cur * 10 + s[i++] - '0'; // get the currrent value
            }
            // append current value to the array(+-), or execute the operator to the last value
            if(op == '+') nums.push_back(cur);
            if(op == '-') nums.push_back(-cur);
            if(op == '*') nums.back() *= cur;
            if(op == '/') nums.back() /= cur;
            
            while(i < n && s[i] == ' ') i++; // remove space
            if(i < n) op = s[i];            // get the operator for next computation
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};



//!sol1, from gy2, O(n), O(1)
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
                
                if(i == n-1 || s[i] == '+' || s[i] == '-'){
                    res += pre;
                    pre = 0;
                }
                op = s[i];
                cur = 0;                
            }
        }
        return res;
    }
};
