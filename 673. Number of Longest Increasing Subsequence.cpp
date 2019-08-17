


// sol 1, dp O(n^2), O(n), from gy
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max_len = 1, res = 1;
        if(n < 2) return n;
        vector<int> longest(n,1), lnumber(n,1);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(longest[i] < longest[j] + 1){
                        longest[i] = longest[j]+1;
                        lnumber[i] = lnumber[j];
                    }
                    else if(longest[i] == longest[j]+1){
                        lnumber[i] += lnumber[j];
                    }
                }
            }
            if(max_len < longest[i]){
                max_len = longest[i];
                res = lnumber[i];
            }
            else if(max_len == longest[i]){
                res += lnumber[i];
            }
        }
        return res;
    }
};
