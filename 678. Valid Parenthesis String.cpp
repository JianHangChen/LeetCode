


sol2, !!!, run twice, use count to track the element, O(n), O(1)
class Solution{
public:
    bool checkValidString(string s){
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')') left--;
            else left++;
            if(left < 0) return false;
        }
        if(left == 0) return true;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '(' ) right--;
            else right++;
            if(right < 0) return false;
        }
        return true;
    }
};


sol3, from sol3 and gy4
class Solution{
public:
    bool checkValidString(string s){
        
        // hi means the largest number of possible "(" left {treat * as left}
        // lo means the smallest number of possible "(" left {treat * as right }
        int lo = 0, hi = 0; 
        for(auto c:s){
            if(c == '(') lo++; else lo--;
            if(c == ')') hi--; else hi++;
            if(hi < 0) return false;
            lo = max(0, lo);
        }
        return lo == 0;
    }    
};



sol1, two stack, from gy, O(n), O(n)

class Solution {
private:
    stack<int> left;
    stack<int> star;
    
public:
    bool checkValidString(string s) {
        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(c == '*') star.push(i);
            else if( c == '(') left.push(i);
            else{
                if(left.empty()){
                    if(star.empty()) return false;
                    else star.pop();
                }
                else{
                    left.pop();
                }
            }
        }
        while(!left.empty() && !star.empty()){
            int i = left.top(); left.pop();
            int j = star.top(); star.pop();
            if(j < i) return false;
        }
        return left.empty();
    }
};


sol4, from gy3, brute force O(N*3^N), O(N)
class Solution{
public:
    bool checkValidString(string s){
        return helpler(s, 0, 0);
    }
    bool helpler(string& s, int cur, int cnt){
        if(cnt < 0) return false;
        if(cur >= s.size()) return cnt == 0;
        
        if(s[cur] == '(') return helpler(s, cur+1, cnt+1);
        if(s[cur] == ')') return helpler(s, cur+1, cnt-1);
        
        return (helpler(s, cur+1, cnt+1) || helpler(s, cur+1, cnt-1) || helpler(s, cur+1, cnt));
    }
};
