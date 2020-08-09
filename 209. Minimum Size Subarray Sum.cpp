
//!!! sol4.1 same as sol4, two loop, sliding window, O(n), O(1)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int i = 0, j = 0;
        int res = INT_MAX, s_ij = 0;
        
        while(j < n){
            s_ij += nums[j];
            if(s_ij >= s){
                while(s_ij >= s && i <= j){
                    res = min(res, j - i + 1);
                    s_ij -= nums[i++];
                }                
            }
            j++;
        }
        return res == INT_MAX ? 0 : res;        
    }
};



//sol4.0,  sliding window, O(n), O(1)
// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int n = nums.size();
//         if(n == 0) return 0;
//         int i = 0, j = 0;
//         int res = INT_MAX, s_ij = nums[0];
//         while(j < n){
//             if(i <= j && s_ij >= s){
//                 int l = j - i + 1;
//                 if(l < res) res = l;
//                 s_ij -= nums[i++];
//             }
//             else{
//                 j++;
//                 if(j < n) s_ij += nums[j];
//             }
//         }
//         return res == INT_MAX ? 0 : res;
        
//     }
// };


//sol1,  sliding window with presum, O(n), O(n)
// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int n = nums.size();
//         vector<int> presum(n+1,0);
//         for(int i = 0; i < n; i++) presum[i+1] = presum[i] + nums[i];
        
//         int i = 0, j = 0;
//         int res = INT_MAX, s_ij = 0;
//         while(j < n){
//             if(i > j){
//                 j++;
//                 continue;
//             }
            
//             s_ij = presum[j+1] - presum[i];
//             if(s_ij >= s){
//                 int l = j - i + 1;
//                 if(l < res) res = l;
//                 i++;
//             }
//             else{
//                 j++;
//             }
//         }
//         return res == INT_MAX ? 0 : res;
        
//     }
// };
