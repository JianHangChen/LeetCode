

// sol1.1, O(nk)  or O(n), O(k)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        if(k == 0 || n == 0) return 0;
        
        if(k >= n / 2){   // if k > n/2  ->  O(n)
            int profit = 0;
            for(int i = 0; i < n - 1; i++){
                if(prices[i+1] - prices[i] > 0) profit += prices[i+1] - prices[i];
            }
            return profit;
        }
        
        vector<int> profit(k, 0), cost(k, INT_MAX);
        for(int price:prices){   // if k < n / 2 ->  O(nk) 
            cost[0] = min(cost[0], price);
            profit[0] = max( profit[0], price - cost[0] );
            
            for(int i = 1; i < k ; i++){
                cost[i] = min(cost[i], price - profit[i-1]);
                profit[i] = max(profit[i], price - cost[i]);
            }
        }
        return profit[k - 1];
        
    }
};


//my sol1, O(nk), O(k), tle beacause O(nk) is too big
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) {
//         if(k == 0) return 0;
//         vector<int> profit(k, 0), cost(k, INT_MAX);
//         for(int price:prices){
//             cost[0] = min(cost[0], price);
//             profit[0] = max( profit[0], price - cost[0] );
            
//             for(int i = 1; i < k ; i++){
//                 cost[i] = min(cost[i], price - profit[i-1]);
//                 profit[i] = max(profit[i], price - cost[i]);
//             }
//         }
//         return profit[k-1];
        
//     }
// };
