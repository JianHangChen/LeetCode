

// !!!!!!! sol4, O(ln), O(l)
class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int S){
        unordered_map<int, int> m1;
        m1[0] = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            unordered_map<int, int> m2;
            for(auto m:m1){
                int sum = m.first, count = m.second;
                m2[sum + nums[i]] += count;
                m2[sum - nums[i]] += count;
            }
            m1 = m2;
        }
        return m1[S];        
    }
};

// !!! sol3, dp, O(ln), O(ln)
// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int S){
//         int n = nums.size();
//         vector<unordered_map<int, int>> dp(n + 1);
//         dp[0][0] = 1;
        
//         for(int i = 1; i <= n; i++){
//             for(auto m:dp[i-1]){
//                 int sum = m.first, count = m.second;
//                 dp[i][sum + nums[i-1]] += count;
//                 dp[i][sum - nums[i-1]] += count;
//             }
//         }
//         return dp[n][S];        
//     }
// };


// my sol2, memorization, O(ln), O(ln), l is the max value of sum, n is the array size

// class Solution {
// private:
//   unordered_map<string, int> m;
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//       return helpler(nums, 0, 0, S);  
//     }

//     int helpler(std::vector<int> nums, int i, int pre_sum, int S){

//       string key = to_string(i)+','+ to_string(pre_sum);
//       if(m.count(key)) return m[key];

//       int count = 0;
//       if(i == nums.size()){
//         if(pre_sum == S) count = 1;
//       }
//       else count = helpler(nums, i + 1, pre_sum + nums[i], S) + helpler(nums, i + 1, pre_sum - nums[i], S);

//       m[key] = count;
//       return count;

//     }
// };


class Solution:
    # sol1, memorization
    # O(l*n), O(l*n), 472ms
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        def findTarget(i, sum, memo):
            if i == len(nums):
                if sum == S:
                    return 1
                else:
                    return 0
            else:
                if memo[i][sum+1000] == -float("inf"):
                    add = findTarget(i+1, sum + nums[i], memo)
                    sub = findTarget(i+1, sum - nums[i], memo)
                    memo[i][sum+1000] = add + sub
                return memo[i][sum+1000]
                
            
        #memo = [[-float('inf')]*2001]*len(nums) # wrong! careful about repeated reference in python
        memo = [[-float("inf")]*2001 for _ in range(len(nums))]
        
        return findTarget(0, 0, memo)
    
    # sol2, 2D DP, O(l*n), O(l*n) 476ms  
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if S < -1000 or S > 1000:
            return 0
        dp = [ [0]*2001 for _ in range(len(nums)) ]
        dp[0][nums[0]] += 1
        dp[0][-nums[0]] += 1
        
        for i in range(1, len(nums)):
            for sum in range(-1000, 1001):
                if dp[i-1][sum] > 0:
                    dp[i][sum + nums[i]] += dp[i-1][sum]
                    dp[i][sum - nums[i]] += dp[i-1][sum]
        return dp[len(nums)-1][S]
    
    # !!! sol4, 1D DP, O(l*n), O(n)
    # 348ms
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if S < -1000 or S > 1000:
            return 0
        dp = [0]*2001
        dp[nums[0]] += 1
        dp[-nums[0]] += 1
        
        for i in range(1, len(nums)):
            new = [0] * 2001
            for sum in range(-1000, 1001):
                if dp[sum] > 0:
                    new[sum + nums[i]] += dp[sum]
                    new[sum - nums[i]] += dp[sum]
            dp = new
        return dp[S]

        
            
