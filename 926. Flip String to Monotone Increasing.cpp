// sol2.1, one loop dp, from ch9, O(n), O(1)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size(), presum = 0, res = INT_MAX;
        
        for(int i = 0; i <= n; i++){
            res = min(res, presum + (n - i)  + presum);
            if(i < n && S[i] == '1') presum++;
        }
        
        // presum[i] leftone, (n-i)-(presum[n]-presum[i]) rightzero
        return min(res, 2*presum) - presum;
        
    }
};

//!!! sol2,dp, from ch9, O(n), O(1)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size(),presum_n = 0;
        
        for(int i = 0; i < n; i++){
            if(S[i] == '1') presum_n++;
        }
        int res = presum_n, presum = 0;
        
        for(int i = 0; i < n; i++){
            res = min(res, presum + (n - i) - (presum_n - presum));
            if(S[i] == '1') presum++;
        }
        
        // presum[i] leftone, (n-i)-(presum[n]-presum[i]) rightzero
        return res;
        
    }
};


//! sol1,dp, from sol1, O(n), O(n)
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> presum(n+1,0);
        for(int i = 1; i <= n; i++){
            if(S[i-1] == '1'){
                presum[i] = presum[i-1] + 1;            
            }
            else{
                presum[i] = presum[i-1];
            }
        }
        int res = INT_MAX;
        for(int i = 0; i <= n; i++){
            res = min(res, presum[i] + (n - i) - (presum[n] - presum[i]));
        }
        
        // presum[i] leftone, (n-i)-(presum[n]-presum[i]) rightzero
        return res;
        
    }
};
