
//!!!! sol2, dp, from sol, O(amount * n), O(amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(int coin:coins){
           for(int x = coin; x <= amount; x++){
               dp[x] += dp[x-coin];
           } 
        }
        return dp[amount];
        
    }
};
// my, sol1, TLE, O(S^n), O(n)
// class Solution {
// public:
//     int res = 0;
//     int change(int amount, vector<int>& coins) {
//         dfs(amount, coins, 0);
//         return res;
//     }
    
//     void dfs(int amount, vector<int>& coins, int k){
//         if(amount == 0) res++;
//         if(amount <= 0 || k == coins.size()) return;
        
//         for(int i = 0; i <= amount / coins[k]; i++){
//             dfs(amount - i * coins[k], coins, k+1);
//         }
        
//     }
// };
