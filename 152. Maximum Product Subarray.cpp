// !!!!! sol2, from sol2,  keep max_so_far and min_so_far, O(n), O(1)


//  [2,3,-2,4]
//   2 6 -12 -48
//  [-2 0 -1]
//  [5 -1 4 -2 0 -1 4 -2 -2]
//  5  -5 -20 40 0 -1 -4 8 -16

// _____nums[i] has 3 cases:

// __{[positive], nums[i]} // [positive product include i - 1]
// _{[negative ], nums[i]}// [negative product include i - 1]
// ______________ {nums[i]}// start again from nums[i]
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int max_so_far = nums[0], min_so_far = nums[0];
        
        for(int i = 1; i < n ; i++){
            int max_so_far_= max_so_far;
            max_so_far = max(nums[i], max(max_so_far * nums[i], min_so_far * nums[i]));
            min_so_far = min(nums[i], min(max_so_far_ * nums[i], min_so_far * nums[i]));
            
            res = max(res, max_so_far);
        }
        return res;            
    }
};

// class Solution:
    
//     # so1, my, brute force. TEL
//     def maxProduct(self, nums: List[int]) -> int:
//         m = -float("inf")
//         n = len(nums)
//         for i in range(n):
//             cur = nums[i]
//             if cur > m:
//                 m = cur
//             for j in range(i+1, n):
//                 cur = cur * nums[j]
//                 if cur > m:
//                     m = cur
//         return m
    
//     # !! sol2, dp, KEEP imax and imin
//     # O(n), O(1)
//     # https://leetcode.com/problems/maximum-product-subarray/discuss/48230/Possibly-simplest-solution-with-O(n)-time-complexity
//     def maxProduct(self, nums: List[int]) -> int:
//         n = len(nums)
//         if n == 0:
//             return
//         res = nums[0]
//         imin = imax = res  # the min, max prefix product containing nums[i]
        
//         for i in range(1, n):
//             if nums[i] < 0:
//                 imin, imax = imax, imin
            
//             imax = max(nums[i], nums[i] * imax)
//             imin = min(nums[i], nums[i] * imin)
            
//             if res < imax:
//                 res = imax
//         return res
        
            
//     # !! sol2, dp, KEEP imax and imin
//     # O(n), O(n)
//     def maxProduct(self, nums: List[int]) -> int:
//         rev = nums[::-1]
//         for i in range(1,len(nums)):
//             if nums[i - 1] != 0:
//                 nums[i] *= nums[i-1]
//             if rev[i - 1] != 0:
//                 rev[i] *= rev[i-1]
        
//         return max(rev+nums)
