// sol1, form gy, bfs O(mnlog(mn)), O(mn)
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int numDistinctIslands2(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        unordered_set<string> s;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                queue<vector<int>> q;
                if(grid[i][j] == 1){
                    q.push({i, j});
                    grid[i][j] = -1;
                    vector<vector<int>> shape;
                    while(!q.empty()){
                        vector<int> cur = q.front(); q.pop();
                        shape.push_back({cur[0], cur[1]});
                        
                        for(auto& dir:dirs){
                            int x = cur[0] + dir[0], y = cur[1] + dir[1];
                            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1){
                                q.push({x, y});
                                grid[x][y] = -1;
                            }                            
                        }
                    }
                    s.insert(normalize(shape));
                    
                }
            }
        }
        return s.size();        
    }
    string normalize( vector<vector<int>>& shape){
        int l = shape.size();
        
        vector<vector<vector<int>>> shapes(8);
        for(int j = 0; j < l; j++){
            int x = shape[j][0], y = shape[j][1];
            shapes[0].push_back({x, y});
            shapes[1].push_back({x, -y});
            shapes[2].push_back({-x, y});
            shapes[3].push_back({-x, -y});
            shapes[4].push_back({y, x});
            shapes[5].push_back({y, -x});
            shapes[6].push_back({-y, x});
            shapes[7].push_back({-y, -x});
        }
        
        
        for(int i = 0; i < 8; i++){
            sort(shapes[i].begin(), shapes[i].end());

            int x = shapes[i][0][0], y = shapes[i][0][1];
            for(int j = 0; j < l; j++){
                shapes[i][j][0] = shapes[i][j][0] - x;
                shapes[i][j][1] = shapes[i][j][1] - y;
            }
        }
        sort(shapes.begin(), shapes.end());
        
        string res;
        for(int j = 0; j < l; j++){
            res += to_string(shapes[0][j][0]) + "_" + to_string(shapes[0][j][1]) + "_";
        }
        return res;
    }
};
