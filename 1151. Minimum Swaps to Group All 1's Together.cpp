//sol1,  O(n), O(1)
// same as sol1
// from https://www.youtube.com/watch?v=LyAIdcaWneo
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n  = nums.size();
        int totalOnes = 0;
        for(int num:nums){
            totalOnes += num;
        }
        int ones = 0;
        for(int j = 0; j < totalOnes; j++){
            ones += nums[j];
        }
        
        int maxOnes = ones;
        
        for(int j = totalOnes; j < n; j++){
            ones += nums[j];
            ones -= nums[j - totalOnes];
            maxOnes = max(ones, maxOnes);            
        }
        return totalOnes - maxOnes;
    }
};
