//!!! sol1, my, dp, most significant bit, O(n), O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1, 0);
        for(int t = 1; t <= num; t *= 2){
            for(int i = t; i < t * 2 && i <= num; i++){
                res[i] = res[i - t] + 1;                
            }
        }
        return res;
    }
};

