
// sol3, dijkstra, O(mnlogmn), O(mn)
struct Point{
    int x, y, d;
    string path;
    Point(int i, int j, int dist, string p):x(i), y(j), d(dist), path(p){
    }
};

struct CMP{
    bool operator()(Point& a, Point& b){
        if(a.d == b.d) return a.path > b.path;
        return a.d > b.d;
    }
};

class Solution {
private:
    int m, n;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string dirc = "rldu";
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        m = maze.size(); n = maze[0].size();
        
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        priority_queue<Point, vector<Point>, CMP> pq;
        
        auto pball = Point(ball[0], ball[1], 0, "");
        pq.push(pball);
        
        while(!pq.empty()){
            Point cur = pq.top(); pq.pop();
            if(visited[cur.x][cur.y]) continue;
            visited[cur.x][cur.y] = true;            
            if(cur.x == hole[0] && cur.y == hole[1]) return cur.path;
            
            for(int i = 0; i < 4; i++){
                int x = cur.x, y = cur.y, d = cur.d;
                string path = cur.path + dirc[i];
                char dx = dirs[i][0], dy = dirs[i][1];
                
                while(valid( x + dx, y + dy, maze)){
                    x += dx; y += dy;
                    d++;
                    if(x == hole[0] && y == hole[1]) break;
                }
                pq.push(Point(x, y, d, path));
            }
        }
        return "impossible";

    }
    bool valid(int x, int y, vector<vector<int>>& maze){
        if(x < 0 || x >= m || y < 0 || y >= n || maze[x][y] == 1) return false;
        return true;
    }
};

// !!! sol2, bfs, O(mn* max(m,n)), O(mn)

class Solution{
private:
    vector<vector<int>> directions{{0,1}, {0,-1}, {1,0},{-1,0}};
    vector<char> dirs = {'r', 'l', 'd', 'u'};
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
        vector<vector<string>> paths(m, vector<string> (n));
        distance[ball[0]][ball[1]] = 0;
        queue<vector<int>> q({ball});
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int x = cur[0], y = cur[1];
            
            for(int i = 0; i < 4; i++){
                auto dir = directions[i];
                int x_ = x, y_ = y, dist = distance[x][y];
                string path = paths[x][y] + dirs[i];
                while(valid(x_ + dir[0], y_ + dir[1], maze)){
                    x_ = x_ + dir[0];
                    y_ = y_ + dir[1];
                    dist++;
                    if(x_ == hole[0] && y_ == hole[1]) break;
                }
                if(x_ == x && y_ == y) continue;
                
                if(distance[x_][y_] > dist){
                    distance[x_][y_] = dist;
                    paths[x_][y_] = path;
                    if(!(x_==hole[0] && y_==hole[1])) q.push({x_,y_});
                }
                else if(distance[x_][y_] == dist){ 
                    if(path < paths[x_][y_]){ // should update path even if dist == distance[x_][y_], use a better path
                        paths[x_][y_] = path; 
                        if(!(x_==hole[0] && y_==hole[1])) q.push({x_,y_});
                    }
                }
            }
        }
        
        return paths[hole[0]][hole[1]] == "" ? "impossible" : paths[hole[0]][hole[1]];
    }
    bool valid(int x, int y, vector<vector<int>>& maze){
        int m = maze.size(), n = maze[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || maze[x][y] == 1) return false;
        return true;
    }
};

// sol1, my, dfs, O(mn * max(m,n)), O(mn)
// class Solution {
// private:
//     vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0},{-1,0}};
//     vector<char> dirs = {'r', 'l', 'd', 'u'};
// public:
//     string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
//         string res, path;
//         int m = maze.size(), n = maze[0].size();
//         vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
//         distance[ball[0]][ball[1]] = 0;
//         dfs(maze, ball, hole, path, res, distance);
        
//         return res == "" ? "impossible" : res;
//     }
    
//     void dfs(vector<vector<int>>& maze, vector<int> ball, vector<int>& hole, string path, string& res, vector<vector<int>>& distance){
        
//         for(int i = 0; i < 4; i++){
//             auto dir = directions[i];
//             char c = dirs[i];
//             string new_path = path + c;
//             int x = ball[0], y = ball[1], dist = distance[x][y];
//             while(valid(maze, x + dir[0], y + dir[1])){
//                 x = x + dir[0];
//                 y = y + dir[1];
//                 dist++;
//                 if(x == hole[0] && y == hole[1]) break;
//             }
//             if(x == ball[0] && y == ball[1]) continue;
            
//             if(x == hole[0] && y == hole[1]){
//                 if(dist < distance[x][y]){
//                     distance[x][y] = dist;
//                     res = new_path;
//                 }
//                 else if(dist == distance[x][y]) res = min(res, new_path);            
//             }
//             else{
//                 if(dist <= distance[x][y]){
//                     distance[x][y] = dist;
//                     dfs(maze, {x,y}, hole, new_path, res, distance);
//                 }
//             }
            
//         }
        
//     }
//     bool valid(vector<vector<int>>& maze, int x, int y){
//         if(x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size() || maze[x][y] == 1) return false;
        
//         return true;
//     }
    
// };


// // sol1, my, dijkstra
// class Solution {
// private:
//     vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0},{-1,0}};
// public:
//     string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
//         string res;
//         int m = maze.size(), n = maze[0].size();
//         vector<vector<int>> distance(m, vector<int> (n, INT_MAX));
//         set<vector<int>> s;
//         distance[ball[0]][ball[1]] = 0;
//         s.insert({0,ball[0], ball[1]});
        
//         while(!s.empty()){
//             auto t = *(s.begin()); s.erase(t);
//             for(auto dir:directions){
                
//             }
            
//         }
        
        
        
        
//     }
// };
