// !!! sol2, my, linear scan O(n), O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(), i = 0;
        int res = 0;
        
        int prelen = 0, len = 0;
        while(i < n){
            int j = i;
            while(j < n){
                if(s[j] == s[i]) j++;
                else break;
            }
            len = j - i;
            
            res += min(prelen, len);
            prelen = len;
            
            i = j;
        }

        return res;
        
    }
};

// sol1, my, O(n), O(n)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size(), i = 0;
        int res = 0;
        
        vector<int> consecutive;
        while(i < n){
            int j = i;
            while(j < n){
                if(s[j] == s[i]) j++;
                else break;
            }
            int len = j - i;
            consecutive.push_back(len); //          
            i = j;
        }
        for(int k  = 0; k < consecutive.size() - 1; k++){
            res += min(consecutive[k], consecutive[k+1]);
        }
        return res;
        
    }
};
