// !!! sol2.1, from gy3, O(n), O(1)
// similar to my sol2, but more concise
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int n = S.size(), m = T.size();
        int i = n - 1, j = m - 1;
        int skip_i = 0, skip_j = 0;
        
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(S[i] == '#'){ skip_i++; i--;}
                else if(skip_i > 0){ skip_i--;  i--;}
                else break;
            }
            while(j >= 0){
                if(T[j] == '#'){ skip_j++; j--;}
                else if(skip_j > 0){ skip_j--; j--;}
                else break;
            }
            if((i>=0) != (j>=0)) return false;
            if(i >= 0 && j >= 0){
                if(S[i] != T[j]) return false;
            }
            i--; j--;
        }
        return i == j;
    }
};

// ! my, sol2, two pointer, O(n), O(1)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int n = S.size(), m = T.size();
        int i = n - 1, j = m - 1;
        int skip_i = 0, skip_j = 0;
        while(i >= 0 || j >= 0){
            if(i >= 0){
                if(S[i] == '#'){
                    skip_i++;
                    i--;
                    continue;
                }
                else if(skip_i > 0){
                    skip_i--;
                    i--;
                    continue;
                }
            }
            if(j >= 0){
                if(T[j] == '#'){
                    skip_j++;
                    j--;
                    continue;
                }
                else if(skip_j > 0){
                    skip_j--;
                    j--;
                    continue;
                }
            }
            // S[i], T[j] != #, skip_i, skip_j = 0
            if(i < 0 && j >= 0 || i >= 0 && j < 0) return false;
    
            if(i >= 0 && j >= 0){
                if(S[i] != T[j]) return false;
                i--; j--;
            }
        }
        return i < 0 && j < 0;
        
    }
};

my sol1, stack, O(n+m), O(n+m)
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> qs, qt;
        for(char c:S){
            if(c == '#'){
                if(qs.empty()) continue;
                qs.pop();
            }
            else{
                qs.push(c);
            }
        }
        for(char c:T){
            if(c == '#'){
                if(qt.empty()) continue;
                qt.pop();
            }
            else{
                qt.push(c);
            }
        }
        
        while(!qs.empty() && !qt.empty()){
            if(qs.top() != qt.top()) return false;
            else{
                qs.pop(); qt.pop();
            }
        }
        return qs.empty() && qt.empty();
        
    }
};
