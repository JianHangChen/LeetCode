// sol2, my, 从上往下, O(mn^2), O(mn^2)
// 从下往上相对简单一些
class Solution {
public:
    int m, n;
    vector<int> dirs = {-1, 0, 1};
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();

        // dp[y][x1][x2] is the maximum cherry can pick from the robot1(0, 0), robot2(0, n-1)
        // base dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        // dp[0][x1][x2] = INT_MIN   not valid when x1 != 0 ||  x2 != n-1
        
        // [x1+d1][x2+d1] should be valid 1. within bound 2. should not be INT_MIN status
        // curpick = x1 == x2 ? grid[y][x1] : grid[y][x1] + grid[y][x2];
        // dp[y][x1][x2] = max of dp[y-1][x1+d1][x2+d1] + curpick;
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (n, INT_MIN)));
        int res = 0;
        dp[0][0][n-1] = grid[0][0] + grid[0][n-1];
        for(int y = 1; y < m; y++){
            for(int x1 = 0; x1 < n; x1++){
                for(int x2 = 0; x2 < n; x2++){
                    for(int d1:dirs){
                        for(int d2:dirs){                            
                            if(Valid(x1+d1) && Valid(x2+d2) && dp[y-1][x1+d1][x2+d2] != INT_MIN){
                                int curpick = (x1 == x2) ? grid[y][x1] : grid[y][x1] + grid[y][x2];
                                dp[y][x1][x2] = max(dp[y-1][x1+d1][x2+d2] + curpick, dp[y][x1][x2]);
                                if(y == m-1) res = max(res, dp[y][x1][x2]);
                            }
                        }
                    }
                    
                }
            }
        }
        return res;
    }
    bool Valid(int x){
        if(x < 0 || x >= n) return false;
        return true;
    }
};

// !!! sol1.1, dp, O(mn^2), O(n^2)
// 从下往上
// https://www.youtube.com/watch?v=Et-7IP5-6wA
class Solution {
public:
    int m, n;
    vector<int> dirs = {-1, 0, 1};
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        
        // dp[y][x1][x2] // from bottom to current status with row = y, robot1 in (x1, y), robot2 in (x2, y)
        // the maximum cherry we can pick
        
        // base case
        // dp[m][x1][x2] = 0
        
        // return dp[0][0][n-1]
        // transition funciton:
        // dp[y][x1][x2] = max(dp[y][x1+d1][x2+d2]) + x1 == x2 ? grid[x1][y] : grid[x1][y] + grid[x2][y]
        
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int y = m - 1; y >= 0; y--){
            vector<vector<int>> dp2(n, vector<int> (n, 0));
        
            for(int x1 = 0; x1 < n; x1++){
                for(int x2 = 0; x2 < n; x2++){
                    for(int d1:dirs){
                        for(int d2:dirs){
                            if(Valid(x1+d1) && Valid(x2+d2)){
                                int curPick =  x1 == x2 ? grid[y][x1] : grid[y][x1] + grid[y][x2];
                                dp2[x1][x2] = max(dp[x1+d1][x2+d2] + curPick, dp2[x1][x2]);
                            }
                        }
                    }
                }
            }
            dp = dp2;
        }
        return dp[0][n-1];
    }
    bool Valid(int x){
        if(x < 0 || x >= n) return false;
        return true;
    }
};


// !!! sol1, dp, O(mn^2), O(mn^2)
// 从下往上
// https://www.youtube.com/watch?v=Et-7IP5-6wA
class Solution {
public:
    int m, n;
    vector<int> dirs = {-1, 0, 1};
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        
        // dp[y][x1][x2] // from bottom to current status with row = y, robot1 in (x1, y), robot2 in (x2, y)
        // the maximum cherry we can pick
        
        // base case
        // dp[m][x1][x2] = 0
        
        // return dp[0][0][n-1]
        // transition funciton:
        // dp[y][x1][x2] = max(dp[y][x1+d1][x2+d2]) + x1 == x2 ? grid[x1][y] : grid[x1][y] + grid[x2][y]
        
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>> (n, vector<int> (n, 0)));
        
        for(int y = m - 1; y >= 0; y--){
            for(int x1 = 0; x1 < n; x1++){
                for(int x2 = 0; x2 < n; x2++){
                    for(int d1:dirs){
                        for(int d2:dirs){
                            if(Valid(x1+d1) && Valid(x2+d2)){
                                int curPick =  x1 == x2 ? grid[y][x1] : grid[y][x1] + grid[y][x2];
                                dp[y][x1][x2] = max(dp[y+1][x1+d1][x2+d2] + curPick, dp[y][x1][x2]);                                
                            }
                        }
                    }
                }
            }
        }
        return dp[0][0][n-1];
    }
    bool Valid(int x){
        if(x < 0 || x >= n) return false;
        return true;
    }
};
