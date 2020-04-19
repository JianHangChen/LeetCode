

//!!! my, sol2, in place, dp, O(mn), O(1)
class Solution{
public:
    vector<vector<int>> dirs = {{1,0}, {0,1}};
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); if(m == 0) return 0; int n = grid[0].size(); if(n == 0) return 0;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i - 1 >= 0 && j - 1 >= 0) grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
                else if(i - 1 < 0 && j - 1 >= 0) grid[i][j] += grid[i][j-1];
                else if(i - 1 >= 0 && j - 1 < 0) grid[i][j] += grid[i-1][j];
            }
        }
        return grid[m-1][n-1];
    }
    
};


// sol1, my, TLE, O(2^(n+m)), O(n+m)
// class Solution {
// public:
//     int res = INT_MAX;
//     vector<vector<int>> dirs = {{1,0}, {0,1}};
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size(); if(m == 0) return 0; int n = grid[0].size(); if(n == 0) return 0;
//         dfs(grid, 0, 0, 0);
//         return res;       
//     }
//     void dfs(vector<vector<int>>& grid, int i, int j, int l){
//         if(l >= res) return;
//         if(i == grid.size() - 1 && j == grid[0].size() - 1){
//             res = min(res, grid[i][j] + l);
//             return;
//         }
        
//         for(auto& dir:dirs){
//             int x = i + dir[0], y = j + dir[1];
//             if(x < grid.size() && y < grid[0].size()){
//                 dfs(grid, x, y, grid[i][j] + l);            
//             }
//         }
        
        
//     }
    
// };
