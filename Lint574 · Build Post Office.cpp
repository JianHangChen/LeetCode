
// !!! sol2, O(mn), O(n+m)
// from  Yummy Corgi https://www.jiuzhang.com/solution/build-post-office/

// [0,1,0,0]
// [1,0,1,1]
// [0,1,0,0]]


// [0,1,0]
// [1,0,1]
// [0,1,0]]
class Solution {
private:
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    vector<int> getDistance(vector<int>& count){
        int sz = count.size();
        vector<int> dist(sz, 0);
        for(int i = 0; i < sz; i++){
            for(int j = 0; j < sz; j++){
                dist[i] += count[j] * abs(j-i);
            }
        }
        return dist;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return -1;
        m = grid.size(); n = grid[0].size();
        vector<int> countRow(m, 0), countCol(n, 0); // count how many houses in current row and col
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    countRow[i]++;
                    countCol[j]++;
                }
            }
        }
        auto rowDistance = getDistance(countRow);
        auto colDistance = getDistance(countCol);
        int shortest = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    shortest = min(shortest, rowDistance[i] + colDistance[j]);
                }
            }
        }
        return shortest == INT_MAX ? -1:shortest;
    }

};


// sol1, O(mn*h), O(mn), tle
// h is the total number of houses, can be as large as mn
class Solution {
private:
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return -1;
        m = grid.size(); n = grid[0].size();
        vector<vector<int>> distanceSum(m, vector<int> (n, 0));

        vector<vector<int>> houses;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) houses.push_back({i, j});
            }
        }
        
        for(auto& house:houses){
            queue<vector<int>> q;
            vector<vector<int>> distance(m, vector<int> (n, 1e6));
            vector<vector<bool>> visited(m, vector<bool> (n, false));
            q.push(house);            
            distance[house[0]][house[1]] = 0;
            visited[house[0]][house[1]] = true;
            while(!q.empty()){
                auto cur = q.front(); q.pop();
                int i = cur[0], j = cur[1];
                for(auto& dir:dirs){
                    int x = i + dir[0], y = j + dir[1];
                    if(IsValid(x, y, visited)){ // 1. inbound 2. not visited
                        q.push({x, y});
                        visited[x][y] = true;
                        distance[x][y] = distance[i][j] + 1;
                    }
                }
            }
            AddDistanceToSum(distanceSum, distance);
        }

        int shortest = INT_MAX;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0) shortest = min(shortest, distanceSum[i][j]);
            }
        }
        return shortest == INT_MAX ? -1:shortest;
    }
    bool IsValid(int x, int y, vector<vector<bool>>& visited){
        if(x < 0 || x >= m || y < 0 || y >= n || visited[x][y] ) return false;
        return true;
    }

    void AddDistanceToSum(vector<vector<int>>& distanceSum, vector<vector<int>>& distance){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                distanceSum[i][j] += distance[i][j];
            }
        }
    }

};
