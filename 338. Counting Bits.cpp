//!!! sol1, my, dp, most significant bit, O(n), O(n)
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        int base = pow(2, 0);
        
        for(int i = 0; base <= num; i++){
            for(int j = base; j < base * 2 && j <= num; j++){
                res[j] = res[j - base] + 1;
            }
            base *= 2;
        }
        return res;
    }
};
