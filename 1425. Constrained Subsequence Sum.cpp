
// sol1, O(n), O(k)
// monodeque
// from https://leetcode.com/problems/constrained-subsequence-sum/discuss/597751/JavaC%2B%2BPython-O(N)-Decreasing-Deque
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
       // dp[i], from [0, i], i included, the maximum subsequence sum
        
        int res = INT_MIN;
        for(int i = 0; i < n; i++){
            if(!dq.empty() && nums[dq.front()] > 0){
                nums[i] = nums[i] + nums[dq.front()];
            }
            res = max(res, nums[i]);
            
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() == i - k) dq.pop_front();
        }
        
        
        return res;
    }
    
};
