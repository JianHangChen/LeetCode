// sol2, since we know that after number, there is always a [] pair, and do recursion inside the bracket
// O(nk), , repeat x length
// O(n), maximum recursive call
class Solution {
public:
    int i = 0;
    string decodeString(string s) {
        return dfs(s);
    }
    string dfs(string& s){
        string res = "", cur = "";
        while(i < s.size()){
            if(isdigit(s[i])){
                int repeat = 0;
                while(i < s.size() && isdigit(s[i])){
                    repeat = repeat * 10 + (s[i++] - '0');
                }
                i++; // skip [
                cur = dfs(s);                
                for(int k = 0; k < repeat; k++) res += cur;
                cur = "";
            }
            else if(isalpha(s[i])){
                res += s[i++];
            }
            else{
                i++; // skip ]
                break;
            }
        }
        return res;
    }
    
};

// sol1, my, good solution to deal with 3a4b instead of 3[a]4[b], recall of calculator iii
// O(nk), , repeat x length
// O(n), maximum recursive call
class Solution {
public:
    int i = 0;
    string decodeString(string s) {
        return dfs(s);
    }
    string dfs(string s){
        int repeat = 1;
        string res = "", cur = "";
        while(i < s.size()){
            if(s[i] == '['){
                i++;
                cur = dfs(s);
                
                res += repeatStr(repeat, cur);
                cur = "";
                repeat = 1;
            }
            else if(isdigit(s[i])){
                res += repeatStr(repeat, cur);

                repeat = 0;
                while(i < s.size() && isdigit(s[i])){
                    repeat = repeat * 10 + (s[i++] - '0');
                }
            }
            else if(isalpha(s[i])){
                cur += s[i++];
            }
            else{ // ] 
                i++;
                break;
            }
        }
        res += repeatStr(repeat, cur);
        return res;
    }
    
    string repeatStr(int r, string s){
        string res = "";
        for(int i = 0; i < r; i++) res += s;
        return res;
    }
    
};
                    
def decodeString(self, s: str) -> str:
    stack = [["", 1]]
    num = ""
    for c in s:
        if c.isdigit():
            num += c
        elif c == "[":
            stack.append(["", int(num)])
            num = ""
        elif c == "]":
            string, count = stack.pop()
            stack[-1][0] += string * count
        else:
            stack[-1][0] += c

    return stack[-1][0]


