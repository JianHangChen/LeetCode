

//sol1, greedy, two pass left right match O(n), O(n)
// from, https://www.bilibili.com/video/BV1W64y1c7h8

// *1011*
// 11011
// 10111

// *()*)*
// (())
// 0011
// ()()
// 0101

class Solution {
public:
    string minimumParenthesesMatching(string &s) {
        queue<int> staridx;
        int n = s.size();
        int left = 0, right = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                left++;
            }
            else if(s[i] == ')'){
                right++;
            }
            else staridx.push(i);
            if(left < right){
                if(staridx.empty()) return "No solution!";
                else{
                    s[staridx.front()] = '('; staridx.pop();
                    left++;
                }
            }
        }
        left = 0; right = 0;
        staridx = queue<int> ();
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '(') left++;
            else if(s[i] == ')') right++;
            else staridx.push(i);
            if(left > right){
                if(staridx.empty()) return "No solution!";
                else{
                    s[staridx.front()] = ')'; staridx.pop();
                    right++;
                }
            }
        }
        string res;
        for(char c:s){
            if(c != '*') res.push_back(c);
        }
        return res;
    }
    

};



