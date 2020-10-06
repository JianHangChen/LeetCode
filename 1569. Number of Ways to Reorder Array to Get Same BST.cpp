// sol1, using Pascal Triangle for combination, O(n^2), O(n^2)
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/discuss/819369/C%2B%2B-Just-using-recursion-very-Clean-and-Easy-to-understand-O(n2)
class Solution {
public:
    int MOD = 1e9 + 7;
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        // build Yanhui/Pascal Triangle        
        // dp[i][j]  is C (i) (j)
        vector<vector<long long>> dp(n+1, vector<long long> (n+1, 1));
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
            }
        }        
        return (int)helpler(nums, dp) - 1;
        
    }
    
    long long helpler(vector<int>& nums, vector<vector<long long>>& dp){
        int n = nums.size();
        if(n <= 2) return 1;             
        vector<int> left, right;
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        int s = left.size(), t = right.size();
        return helpler(left, dp) * helpler(right, dp) % MOD * dp[s+t][s] % MOD;
    }    
    // https://www.khanacademy.org/math/precalculus/x9e81a4f98389efdf:polynomials/x9e81a4f98389efdf:binomial/v/binomial-theorem-intuition

};
