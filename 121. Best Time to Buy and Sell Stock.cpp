
// sol2, my O(n), O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        int cur_min = INT_MAX;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(prices[i] < cur_min) cur_min = prices[i];
            res = max(res, prices[i] - cur_min);
        }
        return res;
        
    }
};


//my sol1, O(n), O(n)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> left(n-1), right(n-1);
        left[0] = prices[0];
        for(int i = 1; i < n - 1; i++){
            left[i] = min(prices[i], left[i-1]);
        }
        right[n-2] = prices[n-1];
        for(int i = n-3; i >= 0; i--){
            right[i] = max(right[i+1], prices[i+1]);
        }
        int res = 0;
        for(int i = 0; i < n-1; i++){
            res = max(res, right[i] - left[i]);
        }
        
        return res;
    }
};




class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        # sol1, my, O(n^2), too slow
        # profit = 0
        # i = 0
        # while i < len(prices):
        #     j = i + 1
        #     while j < len(prices):
        #         p = prices[j] -  prices[i]
        #         if p > profit:
        #             profit = p
        #         j += 1
        #     i += 1
        # return profit
        
        # sol2, from sol
        # O(n), space O(1)
        
        low = float('inf')
        profit = 0
        for i in prices:
            if i < low:
                low = i
            elif i - low > profit:
                profit = i - low
        return profit
        
        
