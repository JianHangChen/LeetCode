

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
origin [1 5 2 7 8 3]
left   [0 4 4 6 7 7]
right  [7 3 6 0 0 0]

class Solution{
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        if(n <= 1) return 0;
        vector<int> left(n), right(n+1); // i included
        int min_val = prices[0], max_val = prices[n-1];
        for(int i = 1; i < n; i++){
            min_val = min(min_val, prices[i]);
            int profit = prices[i] - min_val;
            left[i] = max(profit, left[i-1]);
        }
        for(int i = n -2; i >= 0; i--){
            max_val = max(max_val, prices[i]);
            int profit = max_val - prices[i];
            right[i] = max(profit, right[i+1]);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++){
            res = max(res, left[i] + right[i+1]);
        }
        return res;
    }    
};
