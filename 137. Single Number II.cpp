// sol1, hash, O(n), O(n)
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> m;
//         for(auto num:nums){
//             m[num]++;
//         }
//         for(auto ele:m){
//             if(ele.second == 1) return ele.first;
//         }
//         return -1;
//     }
// };
