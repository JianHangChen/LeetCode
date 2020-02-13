class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){
        int n = nums.size();
        int first, first_count = 0, second, second_count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == first){
                first_count++;
            }
            else if(nums[i] == second){
                second_count++;
            }
            else if(first_count == 0){
                first = nums[i]; first_count = 1;
            }
            else if(second_count == 0){
                second = nums[i]; second_count = 1;
            }
            else{
                first_count--;
                second_count--;
            }    
        }
        vector<int> res;
        first_count = second_count = 0;
        for(int i = 0; i < n; i++){
            if( nums[i] == first) first_count++;
            else if(nums[i] == second) second_count++;
        }
        if(first_count > n / 3) res.push_back(first);
        if(second_count > n / 3) res.push_back(second);
        return res;
    }

};
