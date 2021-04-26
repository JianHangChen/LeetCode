// !!! sol1.1, O(nlogn), O(1)
// https://leetcode.com/problems/frequency-of-the-most-frequent-element/discuss/1175090/JavaC%2B%2BPython-Sliding-Window
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        long long sum = 0;
        int res = 0;
        for(int j = 0, i = 0; j < n; j++){
            sum += nums[j];
            while(i < n && nums[j] * ((long long)j - i + 1) - sum > k){
                sum -= nums[i++];
            }
            res = max(j - i + 1, res);
            
        }
        return res;
    }
};


// sol1, my, O(nlogn), O(n)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> presum(n+1, 0);
        for(int i = 0; i < n; i++){
            presum[i+1] = presum[i] + nums[i];
        }
        
        int res = 0;
        int i = 0, j = 0;
        while(j < n){
            long long sum = presum[j+1] - presum[i];
            long long needed = nums[j] * ((long long)j - i + 1);
            if(needed - sum <= k){
                res = max(j - i + 1, res);
                j++;
            }
            else{
                i++;
            }
        }
        return res;
        
    }
};

// 1 2 4
    
// left
// sum - sum <= k
