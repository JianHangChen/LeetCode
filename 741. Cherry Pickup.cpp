// sol1, O(n^3), O(n^3)
// https://www.youtube.com/watch?v=vvPSWORCKow
// 很棒的一个code版本，下次研究：
// http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-741-cherry-pickup/
class Solution {
public:
    int n;
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n, -1)));
        // dp[x1][y1][x2] means both two points starting from (n-1, n-1), the maximum amount cherry pick to (x1, y1), (x2, y2)
        // base case:
        dp[n-1][n-1][n-1] = grid[n-1][n-1]; // pick up grid[n-1][n-1]
        
        for(int x1 = n - 1; x1 >= 0; x1--){
            for(int y1 = n-1; y1 >= 0; y1--){
                for(int x2 = n - 1; x2 >= 0; x2--){
                    // point x1, y1, x2, y2
                    int y2 = x1+y1-x2;
                    if(Valid(x2, y2) && grid[x1][y1] != -1 && grid[x2][y2] != -1){
                        int curpick = x1 == x2 ? grid[x1][y1] : grid[x1][y1] + grid[x2][y2];

                        if(Valid(x1+1, y1, x2, dp)){
                            dp[x1][y1][x2] = max(dp[x1][y1][x2], dp[x1+1][y1][x2]  + curpick);                            
                        }
                        if(Valid(x1, y1+1, x2, dp)){
                            dp[x1][y1][x2] = max(dp[x1][y1][x2], dp[x1][y1+1][x2] + curpick);
                        }
                        if(Valid(x1+1, y1, x2+1, dp)){
                            dp[x1][y1][x2] = max(dp[x1][y1][x2], dp[x1+1][y1][x2+1]+ curpick);
                        }
                        if(Valid(x1, y1+1, x2+1, dp)){
                            dp[x1][y1][x2] = max(dp[x1][y1][x2], dp[x1][y1+1][x2+1]+ curpick);
                        }
                    }                    
                }
            }
        }
        return dp[0][0][0] == -1 ? 0 : dp[0][0][0];
        
    }
    bool Valid(int x, int y){
        if(x < 0 || y < 0||x >= n || y >= n) return false;
        return true;
    }
    bool Valid(int x1, int y1, int x2, vector<vector<vector<int>>>& dp){
        int y2 = x1 + y1 - x2;
        if(!Valid(x1, y1)) return false;
        if(!Valid(x2, y2)) return false;
        if(dp[x1][y1][x2] == -1) return false;
        return true;
    }
};
