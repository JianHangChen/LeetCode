


// !!! sol3, dp, O(n),O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp0 = 0, dp1 = 0;
        for(int i = 1; i <= n; i++){
            int dp2 = max(dp0+nums[i-1], dp1);
            dp0 = dp1;
            dp1 = dp2;
        }
        return dp1;
    }
};

//! sol2, my, dp, O(n), O(n)
// [1,2,3,1]
// 4
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);  
        // dp[i] means with [0, ..., i-1] houses, the maximum amount can rob
        // case1 with current i - 1, case2 without i-1
        // base case
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= n; i++){
            dp[i] = max(dp[i-2] + nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
};


!!! sol1, my dfs with memo, O(n), O(n)
class Solution {
public:
    unordered_map<int, int> memo;
    int rob(vector<int>& nums) {
        
        return helper(nums, 0);
    }
    int helper(vector<int>& nums, int start){
        
        int n = nums.size();
        if(start >= n) return 0;
        if(memo.count(start) > 0) return memo[start];
        
        int res = 0;
        
        // take the start house:
        res = max(res, nums[start] + helper(nums, start + 2));
        // not take this house
        res = max(res, helper(nums, start + 1));
        memo[start] = res;
        return res;
    }
};







// [1,2,3,1]
// [2,5,9,1]
// [2,5,1,7]
// [2,5,1,3]

//!!! about follow up, 2d house robber
// https://www.1point3acres.com/bbs/thread-743843-1-1.html
class Solution{
public:
    int m, n;
    int rob(vector<vector<int>> mat){
        m = mat.size(); n = mat[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        // dp[i][j] the maximum amount we can rob when we reach (i, j) 
        // case 1: rob current (i, j)
        // case 2: not taking (i, j)
        // dp[0][0] = mat[0][0];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
//                 (i,j-2), ( i-1, j-2), (i-2, j-1), (i-2, j) + m[i][j]
// (i-1, j), (i-1,j-1),(i,j-1)
                
                // additional case
                if(isvalid(i-2, j+2)) dp[i][j] = max(dp[i][j], dp[i-2][j+2] + mat[i][j]);
                else dp[i][j] = max(dp[i][j], mat[i][j]);
                if(isvalid(i-2, j+1)) dp[i][j] = max(dp[i][j], dp[i-2][j+1] + mat[i][j]);
                else dp[i][j] = max(dp[i][j], mat[i][j]);
                
                if(isvalid(i-1, j+1)) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);                
                //
                
                if(isvalid(i-2, j)) dp[i][j] = max(dp[i][j], dp[i-2][j] + mat[i][j]);
                else dp[i][j] = max(dp[i][j], mat[i][j]);
                if(isvalid(i-2, j-1)) dp[i][j] = max(dp[i][j], dp[i-2][j-1] + mat[i][j]);
                else dp[i][j] = max(dp[i][j], mat[i][j]);
                if(isvalid(i-1, j-2)) dp[i][j] = max(dp[i][j], dp[i-1][j-2] + mat[i][j]);
                else dp[i][j] = max(dp[i][j], mat[i][j]);
                if(isvalid(i, j-2)) dp[i][j] = max(dp[i][j], dp[i][j-2] + mat[i][j]);
                else dp[i][j] = max(dp[i][j], mat[i][j]);
                
                if(isvalid(i-1, j)) dp[i][j] = max(dp[i][j], dp[i-1][j]);
                if(isvalid(i-1, j-1)) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);                
                if(isvalid(i, j-1)) dp[i][j] = max(dp[i][j], dp[i][j-1]);
                
            }
        }
        cout << dp[m-1][n-1] <<endl;
        cout << dp[0][0] << endl;
        return dp[m-1][n-1];
    }
    int isvalid(int i, int j){
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }
};

int main() {
    vector<vector<int>> mat1 = {
     {1,2,3,1},
     {2,5,9,1},
     {2,5,1,7},
     {2,5,1,3}};
    Solution sol;
    sol.rob(mat1);
    std::cout << "Hello World!\n";
}


