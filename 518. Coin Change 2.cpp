



// wrong answer  because of duplication
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1
        for(int price = 1; price <= amount; price++){
            for(int coin:coins){
                if(price - coin >= 0) dp[price] += dp[price-coin];
            }
        }
        return dp[amount];
    }
};

// duplicate
// 3:
// 1 1 1 
// 1 2
// 2 1 wrong 

// 0 1 2 3 4 5
// 1 1 1     1
// 1 1 x x   x



//!!!! sol2, dp, from sol, O(amount * n), O(amount)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //dp[i][j] means how many ways we have in position i if we use first j (0..j-1) coins
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int coin:coins){
            for(int i = 1; i <= amount; i++){
                if(i - coin >= 0){
                    dp[i] += dp[i - coin];
                }
            }
        }
        return dp[amount];
    }
};
// 5:
// 11111
// 1112
// 122
// 0 1 2 3 4 5
// 1 1 1 1 1 1
// 1 1 2 2 3 3





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
