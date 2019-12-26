
// // sol3, dfs, O(mn*max(m,n)), for all nodes mn, each node might be visited multiple times, 
//the maximum exploration in one direction is max(m,n), space O(mn) for distance matrix
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







//!!!!! sol2.1, my dijkstra, O(mn log(mn)), O(mn)
// struct CMP{
//     bool operator()(const vector<int>& a, const vector<int>& b) const{
//         if(a[0] < b[0]) return true;
//         if(a[0] > b[0]) return false;
//         if(a[1] < b[1]) return true;
//         if(a[1] > b[1]) return false;
//         return a[2] < b[2];
//     }
// };


class Solution{
private:    
    vector<vector<int>> directions = {{0,-1}, {0,1}, {1,0}, {-1,0}};
public:

    
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){

        int m = maze.size(), n = maze[0].size();
        
        // set<vector<int>, CMP> s;               
        set<vector<int>> s;
        
        vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
        s.insert({0, start[0], start[1]});
        distance[start[0]][start[1]] = 0;
        
        while(!s.empty()){
            auto t = *(s.begin()); s.erase(t);
            int dist = t[0], x = t[1], y = t[2];
            if(x == destination[0] && y == destination[1]) return dist;
            
            for(auto dir:directions){
                int dist_ = dist, x_ = x, y_ = y;
                while(valid(x_ + dir[0], y_ + dir[1], maze, m, n)){
                    x_ = x_ + dir[0]; y_ = y_ + dir[1];
                    dist_++;
                }
                if(dist_ >= distance[x_][y_]) continue;
                
                s.erase({distance[x_][y_],x_,y_}); // real dijkstra
                distance[x_][y_] = dist_;
                s.insert({dist_, x_, y_});
            }
        }
        if(distance[destination[0]][destination[1]] == INT_MAX){
            distance[destination[0]][destination[1]] = -1;
        }
        return distance[destination[0]][destination[1]];
    }
    
    bool valid(int x, int y, vector<vector<int>>& maze, int m, int n){
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        if(maze[x][y] == 1) return false;
        return true;
    }
};


// // sol2, dijstra
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


// !!! sol1.1, my, bfs, O(mn max(m,n)), O(mn)
// O(mn*max(m,n)), for all nodes, each node the maximum exploration in one direction is max(m,n) O(mn) for distance matrix
class Solution {
private:
    vector<vector<int>> directions = {{0,-1}, {0,1}, {1,0}, {-1,0}}; 
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        queue<vector<int>> q({start});
        
        vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
        distance[start[0]][start[1]] = 0;
        
        while(!q.empty()){
            auto t = q.front(); q.pop();
            
            for(auto dir:directions){
                int x = t[0], y = t[1], l = 0;
                while(valid( x + dir[0], y + dir[1], maze, m, n) ){
                    x = x + dir[0];
                    y = y + dir[1];
                    l++;
                }
                if( distance[t[0]][t[1]] + l < distance[x][y]){
                    distance[x][y] = distance[t[0]][t[1]] + l;
                    if(x == destination[0] && y == destination[1]){
                        continue;
                    }
                    q.push({x,y});
                }
            }
            
        }
        
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
    
    bool valid(int x, int y, vector<vector<int>>& maze, int m, int n){
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        if(maze[x][y] == 1) return false;
        return true;
    }
};


// sol1, bfs
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
