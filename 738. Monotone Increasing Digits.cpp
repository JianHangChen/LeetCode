// my sol1, same as gy, O(logN), O(logN)
class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int mark = s.size();
        for(int i = s.size() - 1; i > 0; i--){
            if(s[i-1] > s[i]){
                mark = i;
                s[i-1]--;
            }            
        }
        for(int i = mark; i < s.size(); i++) s[i] = '9';
        return stoi(s);
    }
};
