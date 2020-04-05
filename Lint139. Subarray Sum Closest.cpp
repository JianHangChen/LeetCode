
Lint 139. Subarray Sum Closest 0 用sort后的两个相邻presum的差值看他们是否离0很近。
很近说明这两个presum[i+1].idx和presum[i].idx之间的那段array就是我们要的subarray

// !!! sol2, O(nlogn), O(n)
//from https://www.geeksforgeeks.org/find-sub-array-sum-closest-0/
// https://rafal.io/posts/subsequence-closest-to-t.html
class Solution {
public:
    struct prefix{
        int s;
        int idx;
    };
    
    struct CMP{
        bool operator()(const prefix& a, const prefix& b){
            return a.s < b.s;
        }
    } cmp;
     
    vector<int> subarraySumClosest(vector<int> &nums) {
       int n = nums.size();
       if(n == 0) return {};
       vector<prefix> presum(n+1);
       presum[0].s = 0; presum[0].idx = 0;
       for(int i = 0; i < n; i++){
           presum[i+1].s = presum[i].s + nums[i];
           presum[i+1].idx = i + 1;
       }
       
       sort(presum.begin(), presum.end(), cmp);
       int min_diff = INT_MAX;
       int start = 0, end = 0;
       for(int i = 0; i < n; i++){
           if(abs(presum[i+1].s - presum[i].s) < min_diff){
               min_diff = abs(presum[i+1].s - presum[i].s);
               start = min( presum[i+1].idx, presum[i].idx);
               end = max( presum[i+1].idx, presum[i].idx) - 1;
           }
       }
       return {start, end};
    }
};

// my sol1, O(n^2), O(n)
// class Solution {
// public:
//     /*
//      * @param nums: A list of integers
//      * @return: A list of integers includes the index of the first number and the index of the last number
//      */
//     vector<int> subarraySumClosest(vector<int> &nums) {
//       int n = nums.size();
//       if(n == 0) return {};
//       vector<int> presum(n+1);
//       for(int i = 0; i < n; i++){
//           presum[i+1] = presum[i] + nums[i];
//       }
//       vector<int> res = {0,0};
//       int distance = INT_MAX;
//       for(int i = 0; i < n; i++){
//           for(int j = i; j < n; j++){
//               int s = abs(presum[j+1] - presum[i]);
//               if(s < distance){
//                   res = {i, j};
//                   distance = s;
//               }
//           }
//       }
//       return res;
       
//     }
// };
