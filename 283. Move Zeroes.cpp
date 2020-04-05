
//!!! sol2, from gy1, O(n), O(1)
class Solution{
public:
    void moveZeroes(vector<int>& nums){
        for(int i = 0, j = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                swap(nums[i], nums[j++]);   
            }
        }
    }  
    
};

// my, sol1, O(n), O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return;
        int i = 0, j = 0;
        while(j < n){
            if(i == j){
                j++;
                continue;
            }
            
            if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i++], nums[j++]);
            }
            else if(nums[i] == 0 && nums[j] == 0){
                j++;
            }
            else{ // nums[i] != 0
                i++;
                if(nums[j] == 0) j++;
            }
        }
        
    }
};
