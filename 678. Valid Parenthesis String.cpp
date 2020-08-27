

sol2, !!!, run twice, use count to track the element, O(n), O(1) Valid Parenthesis String
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
    
    

// my, sol2, brute force, O(3^n*n), O(n)
// class Solution {
// public:
//     bool checkValidString(string s) {
//         return checkValid(s, 0, 0);
//     }
//     bool checkValid(string& s, int i, int score){
//         if(i == s.size()) return score == 0;
//         if(s[i] == '(') return checkValid(s, i+1, score+1);
//         else if(s[i] == ')'){
//             score--;
//             if(score < 0) return false;
//             return checkValid(s, i+1, score);
//         }
//         else{
//             if(checkValid(s, i+1, score)) return true;
//             if(checkValid(s, i+1, score+1)) return true;
//             if(score - 1 >= 0 && checkValid(s, i+1, score-1)) return true;
//             return false;
//         }
        
//     }
    
// };


// my, sol1,brute force, TLE, O(3^n), O(n)
// class Solution {
// public:
//     bool checkValidString(string s) {
//         stack<char> st;
        
//         return checkValid(s, 0, st) && st.empty();
        
//     }
//     bool checkValid(string& s, int i ,  stack<char>& st){
//         if(i == s.size()) return st.empty();
//         if(s[i] == '('){
//             st.push('(');
//             bool result = checkValid(s, i+1, st);
//             st.pop();
//             return result;
//         }
//         else if(s[i] == ')'){
//             if(st.empty()) return false;
//             else{
//                 st.pop();
//                 if(checkValid(s, i+1, st)){
//                     st.push('(');
//                     return true;
//                 }
//                 else{
//                     st.push('(');
//                     return false;
//                 }
//             }
//         }
//         else{
//             st.push('(');
//             bool result = checkValid(s, i+1, st);
//             st.pop();
//             if(result){
//                 return true;
//             }
//             if(checkValid(s, i+1, st)) return true;
            
//             if(st.empty()) return false;
//             else{
//                 st.pop();
//                 if(checkValid(s, i+1, st)){
//                     st.push('(');
//                     return true;
//                 }
//                 else{
//                     st.push('(');
//                     return false;
//                 }
//             }
//         }   
//     }
// };
