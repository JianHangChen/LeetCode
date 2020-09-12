
// sol1, O(n^3), O(n^2)
// tusimple hard
// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/780880/DP-with-picture-(Burst-Balloons)
class Solution {
public:
    

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int s = cuts.size();
        vector<vector<int>> dp(s, vector<int> (s, INT_MAX));
        
        return dfs(cuts, 0, cuts.size()-1, dp);
    }

    int dfs(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(j - i <= 1) return 0;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        for(int k = i + 1; k < j; k++){
            dp[i][j] = min(dp[i][j],
                          cuts[j] - cuts[i] + dfs(cuts, i, k, dp) + 
                          dfs(cuts, k, j, dp) );
        }
        return dp[i][j];        
    }
    
};
