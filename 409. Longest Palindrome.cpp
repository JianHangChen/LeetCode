// O(N), O(1)
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> count(70, 0);
        for(char c:s){
            count[c-'A']++;
        }
        
        int res = 0, odd = 0;
        for(int i = 0 ; i < count.size(); i++){
            if(count[i] % 2 == 0) res += count[i];
            else{
                odd = 1;
                res += count[i] - 1;
            }
        }
        return res + odd;
    }
};
