
// sol2, my upper lower bound not using default funciton

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
        int n = nums.size();
        vector<int> res = {-1, -1};
        int left = 0, right = n, mid;
        while(left < right){
            mid  = left + (right - left) / 2;
            if( nums[mid] < target){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        if( left >= n || nums[left] != target) return res;
        res[0] = left;
        right = n;
        while(left < right){
            mid = left + (right - left) / 2;
            if(nums[mid] <= target) left = mid + 1;
            else right = mid;
        }
        res[1] = left - 1;
        return res;
    }
};


//!!! sol1, my upper, lower bound , O(logn), O(1)
#include <stdc++.h>
#include <algorithm>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
          int n = nums.size();
          auto lb = lower_bound(nums.begin(), nums.end(), target);
          if(lb == nums.end() || *lb != target) return {-1, -1};

          auto ub = upper_bound(nums.begin(), nums.end(), target);
          return {lb - nums.begin(), ub - nums.begin() - 1};
    }
};

