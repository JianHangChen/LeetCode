
// !!! sol2, dp, from ch9, O(n), O(n)
class Solution {
public:
    int maxTwoSubArrays(std::vector<int>& nums){
        int n = nums.size(), res = INT_MIN;
        vector<int> presum(n+1, 0), maxleft(n, 0), maxright = maxleft;

        for(int i = 1; i <= n; i++) presum[i] = presum[i-1] + nums[i-1];


        maxleft[0] = nums[0];
        for(int i = 1, minleft = 0; i < n; i++){
            minleft = min(minleft, presum[i]);
            maxleft[i] = max(maxleft[i-1], presum[i+1] - minleft);
        }

        maxright[n-1] = nums[n-1];
        for(int i = n - 2, minright = 0; i >= 0; i--){
            minright = min(minright, presum[n] - presum[i+1]);
            maxright[i] = max(maxright[i + 1], presum[n] - presum[i] - minright);
        }

        for(int i = 1; i < n; i++){
            res = max(res, maxleft[i-1] + maxright[i]);
        }
        return res;
    }
};


// my sol1, brute force, o(N^4)
class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> &nums) {
        int n = nums.size(), res = INT_MIN;
        vector<int> presum(n+1, 0);
        for(int i = 1; i <= n; i++){
            presum[i] = presum[i-1] + nums[i-1];
        }
    
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                for(int k = j + 1 ; k < n; k++){
                    for(int h = k ; h < n; h++){
                        res = max(res, presum[h + 1] - presum[k] + presum[j+1] - presum[i]);
    
                    }
                }
            }
        }
        return res;
    }
};

