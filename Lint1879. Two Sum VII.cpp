
// !!!! sol1, from ch9, very hard, O(n), O(1)
// find small and big
class Solution {
public:

    int next_small(vector<int>& nums, int small){
        int n = nums.size();
        if(nums[small] < 0){
            for(int i = small - 1; i >= 0; i--){
                if(nums[i] < 0) return i;
            }
            for(int i = 0; i < n; i++){
                if(nums[i] >= 0) return i;
            }
        }
        else{ // nums[small] >= 0, on the right side
            for(int i = small + 1; i < n; i++){
                if(nums[i] >= 0) return i;
            }
        }
        return -1;
    }
    
    int next_big(vector<int>& nums, int big){
        int n = nums.size();
        if(nums[big] >= 0){
            for(int i = big - 1; i >= 0; i--){
                if(nums[i] >= 0) return i;
            }
            for(int i = 0; i < n; i++){
                if(nums[i] < 0) return i;
            }
        }
        else{
            for(int i = big + 1; i < n; i++){
                if(nums[i] < 0) return i;
            }
        }
        return -1;
    }

    vector<vector<int>> twoSumVII(vector<int> &nums, int target) {
        vector<vector<int>> res;
        int small = 0, big = 0, n = nums.size();
        if(n <= 1) return res;
        for(int i = 0; i < n; i++){
            if(nums[i] < nums[small]) small = i;
            if(nums[i] > nums[big]) big = i;
        }
        while(nums[small] < nums[big]){
            if(nums[small] + nums[big] > target){
                big = next_big(nums, big);
                if(big == -1) break;
            }
            else if(nums[small] + nums[big] < target){
                small = next_small(nums, small);
                if(small == -1) break;
            }
            else{ // == target
                if(small  < big){
                    res.push_back({small,big});
                }
                else{
                    res.push_back({big, small});
                }
                small = next_small(nums, small);
                if(small == -1) break;
            }
        }
        return res;
    }
};
