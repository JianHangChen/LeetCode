class Solution {
public:

    vector<int> previousPermuation(vector<int> &nums) {
       int n = nums.size(), i , j;
       for(i = n - 2; i >= 0; i--){
           if(nums[i] > nums[i+1]){
               break;
           }
       }
        if(i >= 0){
            for(j = n - 1; j > i; j--){
                if(nums[i] > nums[j]){
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }
       
       reverse(nums.begin() + i + 1, nums.end());
       return nums;
    }
};
