//!!!sol1,  bfs O(mn), O(mn)
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; 
    int numDistinctIslands(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        unordered_set<string> shapes;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ;j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = -1;
                    
                    string shape;
                    while(!q.empty()){
                        vector<int> cur = q.front(); q.pop();
                        shape += to_string(cur[0] - i) + "_" + to_string(cur[1] - j) + "_";
                        for(auto& dir:dirs){
                            int x = cur[0] + dir[0], y = cur[1] + dir[1];
                            if( x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                                q.push({x, y});
                                grid[x][y] = -1;
                            }
                        }
                    }
                    shapes.insert(shape);
                }
            }
        }
        return shapes.size();
    }
};
