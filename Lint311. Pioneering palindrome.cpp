class Solution {
public:

    bool isPalindrome(string &s) {
        int n = s.size();
        vector<int> count(128, 0);
        for(int i = 0; i < n; i++){
            count[s[i]]++;
        }
        bool odd = n % 2;
        for(int i = 0; i < 128; i++){
            if(count[i] % 2 != 0){
                if(odd) odd = false;
                else return false;
            }
        }
        return true;
        

    }
};
