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

    
