class Solution {
public:
    
    sol1, my
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        
        for(string token : tokens){
            if (token == "+"){
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a+b);
            }
            else if (token == "-"){
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a-b);
            }
            else if (token == "*"){
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a*b);
            }
            else if (token == "/"){
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push(a/b);
            }
            else{
                
                s.push( stoi(token) );
                
//                 int start = 0, num = 0;
//                 int n = token.size();
//                 bool negative = false;
//                 if (token[0] == '-'){
//                     start = 1;
//                     negative = true;
//                 }
//                 while ( start < n){
//                     num = num*10+(token[start] - '0');
//                     start++;
//                 }
                
//                 if(negative){
//                     num = -num;
//                 }
                
//                 s.push(num);
            }
            
        }
        return s.top();
    }
    
    // sol2, use lambda expression
    unordered_map<string, function<int (int, int)> > map = {
        { "+", [](int a , int b){ return a + b;} },
        { "-", [](int a , int b){ return a - b;} },
        { "*", [](int a, int b){ return a * b;}},
        { "/", [](int a, int b){ return a / b;}}
    };
    
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string& token: tokens){
            if(map.count(token) == 0){
                s.push( stoi(token) );
            }
            else{
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                s.push( map[token](a, b) );
            }
        }
        return s.top();
    }
};



class Solution:
    # sol1
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        operators = set(["+", "-", "*", "/"])
        for i in tokens:
            if i in operators:
                b = stack.pop()
                a = stack.pop()
                if i == "+":
                    stack.append(a+b)
                elif i == "-":
                    stack.append(a-b)
                elif i == "*":
                    stack.append(a*b)
                else:
                    res = a//b
                    if res < 0 and a%b != 0:
                        stack.append(res + 1)
                    else:
                        stack.append(res)
                
            else:
                stack.append(int(i))
            #print(stack)
        return stack[-1]
    
    # sol2, using lambda function
    # modified from https://leetcode.com/problems/evaluate-reverse-polish-notation/discuss/47481/A-simple-Python-solution-O(n)-72ms
    # not using operator.truediv(x,y)
    def __init__(self):
        self.operators = {
            '+': lambda y, x: x + y,
            "-": lambda y, x: x - y,
            "*": lambda y, x: x * y,
            "/": lambda y, x: (x//y+1) if x//y < 0 and x%y!= 0 else x//y   # int(operator.truediv(x, y))
        }
    
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for i in tokens:
            if i in self.operators:
                stack.append(self.operators[i](stack.pop(), stack.pop()))
            else:
                stack.append(int(i))
                
        return stack[-1]

    
