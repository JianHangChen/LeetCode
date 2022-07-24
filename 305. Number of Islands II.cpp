/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
 //!!!!! sol2 union find, O(r), O(mn)
class Solution {
public:
    vector<int> res;
    int r, c, currentIsland;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    unordered_map<int, int> parent;
    vector<int> numIslands2(int m, int n, vector<Point> &operators) {
        r = m; c = n;
        currentIsland = 0;
        vector<vector<int>> mat(m, vector<int> (n, 0));

        for(auto& op:operators){
            if(mat[op.x][op.y] == 1){
                res.push_back(currentIsland);
                continue;
            }
            mat[op.x][op.y] = 1;
            currentIsland++;
            int idx = getIndex(op.x, op.y);
            parent[idx] = idx;
            for(auto& dir:dirs){
                int x = op.x + dir[0], y = op.y + dir[1];
                if(isValidLand(x, y, mat)){
                    uni(idx, getIndex(x, y));
                }
            }
            res.push_back(currentIsland);
        }
        return res;
    }
    bool isValidLand(int x, int y, vector<vector<int>>& mat){
        if(x < 0 || x >= r || y < 0 || y >= c) return false;
        return mat[x][y] == 1;
    }

    int find(int i){
        if(parent[i] == i) return i;
        parent[i] = find(parent[i]);
        return parent[i];
    }
    void uni(int i, int j){
        int ri = find(i), rj = find(j);
        if(ri == rj) return;
        parent[ri] = rj;
        currentIsland--;
    }
    int getIndex(int i, int j){
        return i * c + j;
    }
};


// sol1, offline, brute force, O(o * mn)
class Solution {
public:
    vector<int> res;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<int> numIslands2(int m, int n, vector<Point> &operators) {
        vector<vector<int>> mat(m, vector<int> (n, 0));
        for(auto& op:operators){
            mat[op.x][op.y] = 1;
            res.push_back(countIslands(mat, m, n));
        }
        return res;
    }
    int countIslands(vector<vector<int>> mat, int m, int n){
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 1){
                    res++;
                    mat[i][j] == -1;
                    // bfs
                    queue<Point> q({Point(i, j)});
                    while(!q.empty()){
                        Point p = q.front(); q.pop();
                        for(auto& dir:dirs){
                            int x = p.x + dir[0], y = p.y + dir[1];
                            if(isValidLand(x, y, mat, m, n)){
                                q.push(Point(x, y));
                                mat[x][y] = -1;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
    bool isValidLand(int x, int y, vector<vector<int>>& mat, int m, int n){
        if(x < 0 || x >= m || y < 0 || y >= n) return false;
        return mat[x][y] == 1;
    }
};
