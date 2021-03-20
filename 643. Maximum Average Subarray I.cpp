class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        int n = nums.size();
        for(int i = 0; i < k; i++){
            avg += (double)nums[i] / k;
        }
        double res = avg;
        for(int i = k; i < n; i++){
            avg += ((double)nums[i] - (double)nums[i - k]) / k;
            res = max(res, avg);
        }
        return res;
        
    }
};
