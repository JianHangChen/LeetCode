

//!!!! sol2, from sol2, dp, O(n), O(1)

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int profit1 = 0, profit2 = 0;
        int cost1 = INT_MAX, cost2 = INT_MAX;
        
        for(auto price:prices){
            cost1 = min(cost1, price);
            profit1 = max(profit1, price - cost1);
            
            cost2 = min(cost2, price - profit1);
            profit2 = max(profit2, price - cost2);
        }
        return profit2;
        
    }    
};


// ! sol1, from sol1, dp, O(n), O(n), seperate the problem to two subproblem: divide and conquer
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> leftprofit(n+1, 0), rightprofit = leftprofit;
        int leftmin = prices[0];
        for(int i = 2; i <= n; i++){
            if(prices[i-1] < leftmin) leftmin = prices[i-1];
            leftprofit[i] = max(leftprofit[i-1], prices[i-1] - leftmin);
        }
        int rightmax = prices[n-1];
        // [3, 3 ,5,0,0,3,1,4]  n =8
        // 0  1  2 3 4 5 6 7  8
        for(int i = n - 2; i >= 0; i--){
            if(prices[i] > rightmax) rightmax = prices[i];
            rightprofit[i] = max(rightprofit[i+1], rightmax - prices[i]);
        }
        int profit = 0;
        for(int i = 0; i <= n; i++){
            profit = max(profit, leftprofit[i] + rightprofit[i]);
        }
        
        return profit;
    }
};
