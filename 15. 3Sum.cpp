
//!!! sol1, O(n^2), O(n^2) from gy1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() == 0 || nums[0] > 0 || nums.back() < 0) return res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = nums.size() - 1, target = 0 - nums[i];
            while(j < k){
                if(nums[j] + nums[k] == target){
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++; k--;
                }
                else if(nums[j] + nums[k] > target) k--;
                else j++;
            }
        }
        return res;       
    }
};
