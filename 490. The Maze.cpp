// !!! my sol2, bfs, O(mn), O(1)

class Solution{
private:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        int m  = maze.size(), n = maze[0].size();
        queue<vector<int>> q;
        q.push(start);
        maze[start[0]][start[1]] = 2;
        
        while(!q.empty()){
            int a = (q.front())[0], b = (q.front())[1]; q.pop();
                
            for(auto dir:directions){
                int x = a, y = b;
                while(valid(x + dir[0],y + dir[1], maze,m,n)){
                    x = x + dir[0]; y = y + dir[1];
                }
                if(x == destination[0] && y == destination[1]) return true;
                if(maze[x][y] == 0){
                    maze[x][y] = 2;
                    q.push({x,y});
                }
            }
        }
        return false;
    }
    bool valid(int x, int y, vector<vector<int>>& maze, int m, int n){
        if(x < 0 || x >= m || y < 0 || y >= n){
            return false;
        }
        if(maze[x][y] == 1) return false;
        return true;
    }
    
};

//! my sol1.1, dfs, O(mn), O(1) not using visited
class Solution {
    
private:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        
        maze[start[0]][start[1]] = 2;
        
        return dfs(maze, start, destination);
    }
    
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
        for(auto dir:directions){
            int x = start[0], y = start[1];
            while(valid(x + dir[0], y + dir[1],maze)){
                x = x + dir[0];
                y = y + dir[1];
            }
            if(x == destination[0] && y == destination[1]) return true;
            if(maze[x][y] == 0){
                maze[x][y] = 2;
                vector<int> st = {x,y};
                if(dfs(maze, st, destination)) return true;     
            }
        }
        return false;
    }
    bool valid(int x, int y, vector<vector<int>>& maze){
        int m = maze.size(), n = maze[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        if(maze[x][y] == 1) return false;
        return true;
    }
    
    
};


my sol1, dfs, O(mn), O(mn)
class Solution {
    
private:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        
        visited[start[0]][start[1]] = true;;
        
        return dfs(maze, start, destination, visited);
    }
    
    bool dfs(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination, vector<vector<bool>>& visited){
        for(auto dir:directions){
            int x = start[0], y = start[1];
            while(valid(x + dir[0], y + dir[1],maze)){
                x = x + dir[0];
                y = y + dir[1];
            }
            if(x == destination[0] && y == destination[1]) return true;
            if(!visited[x][y]){
                visited[x][y] = true;
                vector<int> st = {x,y};
                if(dfs(maze, st, destination, visited)) return true;     
            }
        }
        return false;
    }
    bool valid(int x, int y, vector<vector<int>>& maze){
        int m = maze.size(), n = maze[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n) return false;
        if(maze[x][y] == 1) return false;
        return true;
    }
    
    
};


class Solution {
public:
    vector<int> di = {0,0,1,-1}, dj = {1,-1,0,0};

    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int m = maze.size(), n = maze[0].size();
        queue<vector<int>> q({start});
        maze[start[0]][start[1]] = -1;
        while(!q.empty()){
            vector<int> cur = q.front(); q.pop();

            for(int p = 0; p < 4; p++){
                int i = cur[0], j = cur[1];
                while( i + di[p] >= 0 && i + di[p] < m && j + dj[p] >=0 && j + dj[p] < n && maze[i+di[p]][j+dj[p]] != 1){
                    i = i + di[p]; j = j + dj[p];
                }
                if(maze[i][j] == -1) continue;
                if(i == destination[0] && j == destination[1]) return true; //find dest
                q.push({i,j}); maze[i][j] = -1;
            }
            
        }
        return false;
    }
};
