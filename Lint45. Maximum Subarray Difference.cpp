// sol1, my, O(n), O(n) same as ch9
class Solution {
public:
    int maxDiffSubArrays(vector<int>& nums){
        int n = nums.size();
        vector<int> presum(n+1, 0);
        vector<int> leftmax(n, INT_MIN), rightmax = leftmax, leftmin(n, INT_MAX), rightmin = leftmin;
        for(int i = 1; i <= n; i++){
            presum[i] = presum[i-1] + nums[i-1];
        }
    
        leftmax[0] = nums[0]; leftmin[0] = nums[0];
        int left_valley = 0, left_peak = 0; 
        for(int i = 1; i < n; i++){
            left_valley = min(left_valley, presum[i]);
            left_peak = max(left_peak, presum[i]);
            leftmax[i] = max(leftmax[i-1], presum[i+1] - left_valley);
            leftmin[i] = min(leftmin[i-1], presum[i+1] - left_peak);
        }
    
        rightmax[n-1]= nums[n-1]; rightmin[n-1] = nums[n-1];
        int right_valley = 0, right_peak = 0;
        for(int i = n - 2; i >= 0; i--){
            right_valley = min(right_valley, presum[n] - presum[i+1]);
            right_peak = max(right_peak, presum[n] - presum[i+1]);
            rightmax[i] = max(rightmax[i+1], presum[n] - presum[i] - right_valley);
            rightmin[i] = min(rightmin[i+1], presum[n] - presum[i] - right_peak);
        }
    
        int res = 0;
        for(int i = 1; i < n; i++){
            res = max(res, abs(leftmax[i-1] - rightmin[i]) );
            res = max(res, abs(leftmin[i-1] - rightmax[i]) );
        }
        return res;
    }
};
