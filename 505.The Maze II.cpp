// sol3, dfs
class Solution {
public:
    vector<int> di = {0,0,1,-1}, dj = {1,-1,0,0};
    
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        if(maze.empty() || maze[0].empty()) return -1;
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dists(m, vector<int> (n, INT_MAX));
        dists[start[0]][start[1]] = 0;
        
        dfs(maze, start, destination, dists);
        
        return dists[destination[0]][destination[1]] == INT_MAX ? -1 : dists[destination[0]][destination[1]];
    }
    void dfs(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination, vector<vector<int>> &dists){
        int m = maze.size(), n = maze[0].size();
        for(int p = 0; p < 4; p++){
            int i = start[0], j = start[1], dist = dists[i][j];
            while(i + di[p] >= 0 && i + di[p] < m && j + dj[p] >= 0 && j + dj[p] < n && maze[i+di[p]][j+dj[p]] == 0){
                i += di[p]; j += dj[p]; dist++;
            }
            if(dist < dists[i][j]){
                dists[i][j] = dist;
                vector<int> next = {i,j};
                dfs(maze, next, destination, dists);
            }
        }
        
    }
};


sol2, dijstra
class Solution {
public:
    vector<int> di = {0,0,1,-1}, dj = {1,-1,0,0};

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int m = maze.size(), n = maze[0].size();
        
        auto cmp = [&](vector<int> a, vector<int> b){
            return a[2]>b[2];
        };
        vector<vector<int>> dists(m, vector<int> (n, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);
        pq.push({start[0], start[1], 0});
        dists[start[0]][start[1]] = 0;
        
        while(!pq.empty()){
            vector<int> cur = pq.top(); pq.pop();
            int i = cur[0], j = cur[1], dist = cur[2];
            if(dists[i][j] < dist) continue;
            
            for(int p = 0; p < 4; p++){
                int i_ = i, j_ = j, dist_ = dist;
                while(i_ + di[p] >= 0 && i_ + di[p] < m && j_ + dj[p] >= 0 && j_ + dj[p] < n && maze[i_ + di[p]][j_ + dj[p]] == 0){
                    i_ = i_ + di[p]; j_ = j_ + dj[p]; dist_++;
                }
                if(dists[i_][j_] <= dist_) continue;
                dists[i_][j_] = dist_;
                if(i_ != destination[0] || j_ != destination[1]){
                    pq.push({i_, j_, dist_});
                }
            }
            
        }
        return (dists[destination[0]][destination[1]] == INT_MAX )? -1:dists[destination[0]][destination[1]];
    }
    

};


sol1, bfs
class Solution {
public:
    vector<int> di = {0,0,1,-1}, dj = {1,-1,0,0};

    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int m = maze.size(), n = maze[0].size();
        queue<vector<int>> q({start});
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[start[0]][start[1]] = 0;
        
        while(!q.empty()){
            vector<int> cur = q.front(); q.pop();

            for(int p = 0; p < 4; p++){
                int i = cur[0], j = cur[1];
                int new_dist = dist[i][j];
                while( i + di[p] >= 0 && i + di[p] < m && j + dj[p] >=0 && j + dj[p] < n && maze[i+di[p]][j+dj[p]] != 1){
                    new_dist++;
                    i = i + di[p]; j = j + dj[p];
                }
                if(dist[i][j] <= new_dist) continue;
                dist[i][j] = new_dist;
                if(i != destination[0] || j != destination[1]) q.push({i,j}); // not rolling anymore if it is the destination 
            }
            
        }
        return (dist[destination[0]][destination[1]] == INT_MAX) ? -1 : dist[destination[0]][destination[1]];
    }
};
