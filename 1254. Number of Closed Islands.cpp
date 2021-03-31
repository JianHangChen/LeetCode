// sol1, my dfs, O(mn), O(mn)
class Solution {
public:
    int m, n;
    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        if(m <= 1 || n <= 1) return 0;
        
        for(int j = 0; j < n; j++){
            if(grid[0][j] == 0) dfs(0, j, grid);
            if(grid[m-1][j] == 0) dfs(m-1, j, grid);
        }
        
        
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 0) dfs(i, 0, grid);
            if(grid[i][n-1] == 0) dfs(i, n-1, grid);
        }
        
        int count = 0;
        
        for(int i = 1; i < m - 1; i++){
            for(int j = 1; j < n - 1; j++){
                if(grid[i][j] == 0){
                    dfs(i, j, grid); // change to 1
                    count++;
                }
                
            }
        }
        return count;
    }
    
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int i, int j, vector<vector<int>>& grid){
        grid[i][j] = 1; // 0->1
        
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 0){
                dfs(x, y, grid);
            }
        }
    }
    
};
