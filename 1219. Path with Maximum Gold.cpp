// sol1, my, backtracking, O(3^k), O(k)
class Solution {
public:
    int res = 0;
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    dfs(i, j, 0, grid);
                }
            }            
        }
        return res;    
    }
    void dfs(int i, int j, int s,vector<vector<int>>& grid){
        int val = grid[i][j];
        s += grid[i][j];
        res = max(res, s);
        grid[i][j] = 0;
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] > 0){
                dfs(x, y, s, grid);
            }
        }
        grid[i][j] = val;
    }
};
