// sol1, my O(mn), O(mn)
class Solution {
public:
    int m, n;
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(); n = matrix[0].size();
        int res = 0;
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res = max(res, dfs(i, j, visited, matrix));
            }
            
        }
        return res;
        
    }
    int dfs(int i, int j, vector<vector<int>>& visited, vector<vector<int>>& matrix){
        if(visited[i][j] > 0) return visited[i][j];
        
        int max_res = 0;
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j]){
                max_res = max(max_res, dfs(x, y, visited, matrix));
            }
        }
        
        
        visited[i][j] = max_res + 1;    
        return visited[i][j];
    }
    
};
