
// // sol1, my bfs, O(mn), O(1)

class Solution {
private:
    vector<vector<int>> directions  = {{0,1}, {0,-1}, {1,0}, {-1,0}};
public:
    int theMazeIV(vector<vector<char>> &maps) {
        int m = maps.size(), n = maps[0].size();
        vector<int> start, dest;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(maps[i][j] == 'S') start = {i,j};
                else if(maps[i][j] == 'T') dest = {i,j};
            }
        }
        queue<vector<int>> q({start});
        int res = 0;
        while(!q.empty()){
            res++;
            for(int i = q.size(); i > 0 ; i--){
                auto t = q.front(); q.pop();
                for(auto& dir:directions){
                    int x = t[0] + dir[0], y = t[1] + dir[1];
                    if(x == dest[0] && y == dest[1]) return res;

                    if(x >= 0 && y >= 0 && x < m && y < n && maps[x][y] == '.'){
                        maps[x][y] = 'v';
                        q.push({x,y});
                    }
                }
            }
        }
        return -1;
    }
};
