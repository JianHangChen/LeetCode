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
