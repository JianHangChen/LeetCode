

// !! sol4, dp, top-down, from sol2, O(S*n), O(n)
class Solution{
public:
    unordered_map<int, int> m;
    
    int coinChange(vector<int>& coins, int amount){
        
        if(amount == 0) return 0;
        if(amount < 0) return -1;
        
        if(m.count(amount) > 0) return m[amount];
        
        int res = INT_MAX;
        for(int coin:coins){
            if(amount >= coin){
                int c = coinChange(coins, amount - coin);
                if(c != -1){
                    res = min(res, c+1);
                }                
            }
        }
        
        return m[amount] = (res == INT_MAX ? -1 : res);
        
    }
};


// !!! sol3, dp, from sol3 or gy1, bottom-up,  O(S*n), O(n)
class Solution{
public:
    int coinChange(vector<int>& coins, int amount){
        vector<int> coins_needed(amount+1, INT_MAX);
        coins_needed[0] = 0;
        for(int price = 1; price <= amount; price++){
            for(int coin:coins){
                
                if(price - coin >= 0){
                    if(coins_needed[price - coin] == INT_MAX) continue;
                    coins_needed[price] = min(coins_needed[price], coins_needed[price - coin] + 1);           
                }
            }
        }
        return coins_needed[amount] == INT_MAX ? -1 : coins_needed[amount];        
    }
};


// sol2, from ch9 video, dfs, tle, O(S^n), O(c), TLE
// class Solution{
// public:
//     int res = INT_MAX;
//     int coinChange(vector<int>& coins, int amount){
//         sort(coins.begin(), coins.end());
//         dfs(coins, amount, 0, 0);
//         if(res == INT_MAX) return -1;
//         else return res;
//     }    
//     void dfs(vector<int>& coins, int amount, int i, int num){
//         if(num >= res) return;
//         if(amount == 0){
//             res = num;
//             return;
//         }
//         if(i >= coins.size()) return;
        
//         if(coins[i] == 0){
//             dfs(coins, amount, i+1, num);
//             return;
//         }
        
//         for(int k = 0; k <= amount / coins[i]; k++){ // carefully of amount / coins[i] when coins[i] is 0
//             dfs(coins, amount - k * coins[i], i+1, num + k);
//         }
        
//     }
// };


// sol1, dfs, tle, my, O(S^n), O(c)
// note: greedy is wrong
// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(), coins.end());
//         int res = helpler(coins, amount, coins.size() - 1);    
//         if(res != -1) return res;
//         return -1;
        
//     }
//     int helpler(vector<int>& coins, int amount, int start){
//         if(amount == 0) return 0;
//         if(amount < 0) return -1;
        
//         int ans = INT_MAX;
//         for(int i = start; i >= 0; i--){
//             int res = helpler(coins, amount - coins[i], i);
//             if(res != -1){
//                 ans = min(ans, res + 1);
//             }
//         }
//         if(ans == INT_MAX) return -1;
//         else return ans;        
//     }
// };
