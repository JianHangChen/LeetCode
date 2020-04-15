// sol1, my stack, O(n), O(n)

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(auto c:s){
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else{
                if(st.empty()) return false;
                char t = st.top(); st.pop();
                if(c == ')' && t != '(') return false;
                else if(c == ']' && t != '[') return false;
                else if(c == '}' && t != '{') return false;
            }
        }
        return st.empty();
    }
};







class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s == '':
            return True
        
        complement = {'(':')','[':']','{':'}'}
        i = 0
        stack = []
        while i < len(s):
            if s[i] in complement.keys(): #s[i] == '(' or s[i] == '[' or s[i] == '{':
                stack.append(s[i])
            else:
                if stack == [] or complement[stack.pop()] != s[i]:
                    return False
            i += 1
        return stack ==[]
        # if q:
        #     return False
        # else:
        #     return True
            
            
        #     if s[i] == '(':
        #         flag1 += 1
        #     elif s[i] == '[':
        #         flag2 += 1
        #     elif s[i] == '{':
        #         flag3 += 1
        #     elif s[i] == ')':
        #         if flag2 or flag3:
        #             return False
        #         flag1 -= 1
        #     elif s[i] == ']':
        #         if flag1 or flag3:
        #             return False
        #         flag2 -= 1
        #     elif s[i] == '}':
        #         if flag1 or flag2:
        #             return False
        #         flag3 -= 1
        #     if flag1 < 0 or flag2 < 0 or flag3 < 0:
        #         return False
        #     i += 1
        # if flag1 == 0 and flag2 == 0 and flag3 == 0:
        #     return True
        # else:
        #     return False
            
            
            
#             if flag1:
#                 if s[i] != ')':
#                     return False
#             if flag2:
#                 if s[i] != ']':
#                     return False
#             if flag3:
#                 if s[i] != '}':
#                     return False
            
