class Solution {
public:

    vector<vector<int>> dirs = {{}, {}, {1, 0}, {-1,0}, {0,1}, {0, -1}};
    vector<vector<int>> shortestPath(vector<vector<int>> &grid) {
        int m = grid.size(); if(m == 0) return {}; int n = grid[0].size(); if(n == 0) return {};
        vector<vector<int>> levels(m, vector<int> (n, INT_MAX));
        
        queue<vector<int>> q;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) q.push({i, j});
            }
        }
        int layer = 0;
        while(!q.empty()){
            int l = q.size();
            layer++;
            for(int t = 0; t < l; t++){
                int i = q.front()[0], j = q.front()[1]; q.pop();
                for(int k = 2; k <= 5; k++){
                    int x = i + dirs[k][0], y = j + dirs[k][1];
                    if(x >= 0 && y >= 0 && x < m && y < n){
                        if(grid[x][y] == 0){
                            grid[x][y] = k;
                            levels[x][y] = layer;
                            q.push({x,y});
                        }
                        else if(grid[x][y] >= 2 && layer == levels[x][y]){
                            if(grid[x][y] > k){
                                grid[x][y] = k;
                            }
                        }
                        
                    }
                    
                }
                
            }
        }
        return grid;
    }
};
