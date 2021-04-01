// sol1, my, bfs, O(mn), O(mn)
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void wallsAndGates(vector<vector<int>>& rooms) {
        m = rooms.size(); n = rooms[0].size();
        queue<vector<int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(rooms[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()){
            for(int t = q.size(); t > 0; t--){
                auto cur = q.front(); q.pop();
                int a = cur[0], b = cur[1];
                for(auto& dir:dirs){
                    int x = a + dir[0], y = b + dir[1];
                    if(isvalid(x, y) && rooms[x][y] > rooms[a][b] + 1){
                        rooms[x][y] = rooms[a][b] + 1;
                        q.push({x, y});
                    }
                }
            }
        }

    }
    bool isvalid(int x, int y){
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        return true;
    }
};
