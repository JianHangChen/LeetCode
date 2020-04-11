
//sol1, my, O(n), O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int profit = 0;
        int smallest = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] > smallest){
                profit += prices[i] - smallest;
            }
            smallest = prices[i];
        }
        return profit;
        
        
    }
};






// class Solution:
//     def maxProfit(self, prices):
//         """
//         :type prices: List[int]
//         :rtype: int
//         """
//         l = len(prices)
//         if l <= 0:
//             return 0
//         profit = 0
//         local_max_profit = 0
        
//         low_price = prices[0]
        
//         for i in range(l-1):
//             if prices[i] > prices[i+1]:
//                 low_price = prices[i+1]
//                 profit += local_max_profit
//                 local_max_profit = 0
//             else:
//                 if local_max_profit < prices[i+1] - low_price:
//                     local_max_profit = prices[i+1] - low_price
//         profit += local_max_profit
//         return profit
//         # for i in prices:
//         #     if i <= low_price:
//         #         low_price = i
//         #         profit += local_max_profit
//         #         local_max_profit = 0
//         #     else:
//         #         if local_max_profit < i - low_price:
//         #             local_max_profit = i - low_price
