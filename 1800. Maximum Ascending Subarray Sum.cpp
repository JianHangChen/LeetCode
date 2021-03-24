class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = 0;
        int tempsum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i == 0 || nums[i] > nums[i-1]){
                tempsum += nums[i];
                
            }
            else{
                tempsum = nums[i]; 
            }
            res = max(tempsum, res);
        }
        return res;
    }
};
