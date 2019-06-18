class Solution {
public:
    /**
     * @param n: 
     * @param nums: 
     * @return: return the sum of maximum OR sum, minimum OR sum, maximum AND sum, minimum AND sum.
     */
    long long getSum(int n, vector<int> &nums) {
        // write your code here
        int max_or_sum=nums[0], min_or_sum=nums[0];
        int max_and_sum = nums[0], min_and_sum = nums[0];
        
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            
            max_or_sum |= num;
            min_or_sum = min(min_or_sum, num);
            max_and_sum = max(max_and_sum, num);
            min_and_sum &= num;
        }
        return (long long)max_or_sum+min_or_sum+max_and_sum+min_and_sum;
    }
};
