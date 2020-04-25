

// [7 8 9 10 11]
// numOdds = 2

// oddIdx -> 0, 1, 3, 5, 6

// i = 1, i + numOdds = 3


// left_case: (1-0)
// right_case: (5-3)

// 1 * (5-3) = 2

// i = 2, i + numOdds = 4
// left_case: (3-1)
// right_case: (6-5)

// 2 * 1 =2


// 4


// sol3, by cowtony!!!!!, O(n), O(n)
class Solution{
public:
    int BeautifulSubarrays(vector<int>& nums, int numOdds){
        vector<int> oddIdx;
        oddIdx.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1){
                oddIdx.push_back(i+1);
            }
        }
        oddIdx.push_back(nums.size() + 1);
        if(oddIdx.size() - 1 < numOdds) return 0;
        
        int res = 0;
        for(int i = 1; i + numOdds < oddIdx.size(); i++){
            res += (oddIdx[i] - oddIdx[i-1]) * (oddIdx[i+numOdds] - oddIdx[i+numOdds-1]);
        }
        return res;
    }
};








// by cowtony
// class Solution {
// public:
//     int BeautifulSubarrays(vector<int> &nums, int numOdds) {
//         vector<int> odd_idx;
//         odd_idx.push_back(0);
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] % 2 == 1) {
//                 odd_idx.push_back(i + 1);
//             }
//         }
//         odd_idx.push_back(nums.size() + 1);
//         if (odd_idx.size() - 2 < numOdds) {
//             return 0;
//         }
        
//         int ret = 0;
//         for (int i = 1; i + numOdds < odd_idx.size(); i++) {
//             int x = (odd_idx[i] - odd_idx[i - 1]) * (odd_idx[i + numOdds] - odd_idx[i + numOdds - 1]);
//             ret += x;
//         }
//         return ret;
//     }
// };

// my sol2, truncated sol1, worst O(n^2), O(n)
// class Solution {
// public:
//     /**
//      * @param nums: an integer list
//      * @param numOdds: an integer
//      * @return: return the number of beautiful subarrays
//      */
//     int BeautifulSubarrays(vector<int> &nums, int numOdds) {
//         int n = nums.size(); if(n == 0 || numOdds > n) return 0;
//         vector<int> dp(n);
        
//         int res = 0;
//         for(int i = 0; i < n ; i++){
//             for(int j = i; j < n; j++){
//                 dp[i] = dp[i]  + (nums[j] % 2 == 1);
            
//                 if(dp[i] == numOdds) res++;
//                 else if(dp[i] > numOdds) break;
        
//             }
//         }

//         return res;
//     }
// };



// my, sol1, tle, O(n^2), O(n^2)
// class Solution {
// public:
//     /**
//      * @param nums: an integer list
//      * @param numOdds: an integer
//      * @return: return the number of beautiful subarrays
//      */
//     int BeautifulSubarrays(vector<int> &nums, int numOdds) {
//         int n = nums.size(); if(n == 0) return 0;
//         // vector<vector<int>> dp(n, vector<int> (n));
//         vector<int> dp(n);
        
//         int res = 0;
//         for(int length = 0; length < n; length++){
//             for(int i = 0; i < n && i + length < n; i++){
//                 int j = i + length;
//                 dp[i] = dp[i]  + (nums[j] % 2 == 1);
                
//                 if(dp[i] == numOdds) res++;
//             }
//         }
//         return res;
//     }
// };
