// sol1, O(n), O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1) count++;
            else count = 0;
            res = max(res, count);
        }
        return res;
    }
};
