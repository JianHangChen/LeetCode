

//!!! sol2, from gy, hashmap + presum, O(n), O(n)
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return 0;
        
        vector<int> presum(n);
        unordered_map<int, int> m;
        
        int s = 0;
        for(int i = 0; i < n; i++){
            s += nums[i];
            presum[i] = s;
            if(m.count(s) == 0) m[s] = i;
        }
        
        int res = 0;
        for(int i = n - 1; i >= 0; i--){
            if(presum[i] == k) res = max(res, i + 1);
            else if(m.count( presum[i] - k ) > 0){
                res = max(res, i - m[presum[i] - k]);
            }
        }        
        return res;
    }
};


// sol1, my brute force, O(n^2)
// class Solution {
// public:
//     int maxSubArrayLen(vector<int>& nums, int k) {
//         int n = nums.size();
//         int res = 0;
//         for(int i = 0; i < n; i++){
//             int s = 0;
//             for(int j = i; j < n; j++){
//                 s += nums[j];
//                 if(s == k) res = max(res, j - i + 1);
//             }
//         }
//         return res;
//     }
// };
