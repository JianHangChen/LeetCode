// [0,1,0,0,0]
// [1,0,0,2,1]
// [0,1,0,0,0]

class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int shortestDistance(vector<vector<int>> &grid) {
        if(grid.empty() || grid[0].empty()) return -1;
        m = grid.size(); n = grid[0].size();
        vector<vector<int>> houses;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) houses.push_back({i, j});
            }
        }
        vector<vector<int>> distSum(m, vector<int> (n, 0));
        
        for(auto& house:houses){
            vector<vector<bool>> visited(m, vector<bool> (n, false));            
            vector<vector<int>> dist(m, vector<int> (n, INT_MAX));
            queue<vector<int>> q;
            q.push(house);
            visited[house[0]][house[1]] = true;
            dist[house[0]][house[1]] = 0;
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                int i = cur[0], j = cur[1];
                for(auto& dir:dirs){
                    int x = i + dir[0], y = j + dir[1];
                    if(IsValid(x, y, grid, visited)){ // inbound, should be empty() == 0, not visited
                        visited[x][y] = true;
                        dist[x][y] = dist[i][j] + 1;
                        q.push({x,y});
                    }
                }
            }
            AddToSum(dist, distSum);
        }

        int minDist = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    minDist = min(distSum[i][j], minDist); 
                }
            }
        }       
        return minDist == INT_MAX ? -1 : minDist;
    }
    bool IsValid(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited){
        if(x < 0 || x >= m || y <  0 || y >= n || grid[x][y] != 0 || visited[x][y]) return false;
        return true;
    }
    void AddToSum(vector<vector<int>>& dist, vector<vector<int>>& distSum){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] == INT_MAX || distSum[i][j]  == INT_MAX) distSum[i][j] = INT_MAX; // carefull of the unreachble case
                else distSum[i][j] += dist[i][j];
            }
        }          
    }
};
