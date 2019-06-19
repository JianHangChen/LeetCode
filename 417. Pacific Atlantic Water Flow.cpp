// !!!sol2, bfs
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<vector<int>> res;
        int m = matrix.size(), n = matrix[0].size();
        
        
        vector<vector<bool>> toP(m, vector<bool>(n, false)), toA = toP;
        queue<vector<int>> qp, qa;
        
        for (int i = 0; i < m; ++i) {
            qp.push({i, 0});
            toP[i][0] = true;
            qa.push({i, n-1});
            toA[i][n-1] = true;
        }
        for (int j = 0; j < n; ++j) {
            qp.push({0,j});
            toP[0][j] = true;
            qa.push({m-1,j});
            toA[m-1][j] = true;
        }
        
        bfs(matrix, toP, qp);
        bfs(matrix, toA, qa);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (toP[i][j] && toA[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    
    vector<int> di = {0, 0, 1,-1};
    vector<int> dj = {1,-1, 0, 0};
    
    void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& t, queue<vector<int>>& q) {
        int m = matrix.size(), n = matrix[0].size();
        while(!q.empty()){
            vector<int> cord = q.front(); q.pop();
            int i = cord[0], j = cord[1], i_, j_;
            
            for(int s = 0; s < 4; s++){
                i_ = i + di[s]; j_ = j + dj[s];
                if(i_ >= 0 && i_ < m && j_ >=0 && j_ < n && !t[i_][j_] && matrix[i][j] <= matrix[i_][j_] ){
                    t[i_][j_] = true; //carefull!
                    q.push({i_, j_});
                }
            }
            
        }
    }
};


// sol1, DFS,  carefull about the depth of recursion

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int m = matrix.size(); 
        if(m == 0) return {};
        int n = matrix[0].size();   
        
        vector<vector<bool>> toP(m, vector<bool>(n,false));
        vector<vector<bool>> toA(m, vector<bool>(n,false));
        
        for(int j = 0; j < n; j++){
            dfs(matrix, toP, m, n, INT_MIN, 0, j);
            dfs(matrix, toA, m, n, INT_MIN, m-1, j);
        }
        
        for(int i = 0; i < m; i++){
            dfs(matrix, toP, m, n, INT_MIN, i, 0);
            dfs(matrix, toA, m, n, INT_MIN, i, n-1);
        }
        
        vector<vector<int>> res;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(toA[i][j] && toP[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
    
    vector<int> di = {0,  0, 1, -1};
    vector<int> dj = {1, -1, 0,  0};
    
    void dfs(vector<vector<int>>& matrix,vector<vector<bool>> &t, int m, int n, int pre, int i, int j){
        
        if(i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] < pre || t[i][j] == true) return;
        
        t[i][j] = true;
        for(int k = 0; k < 4; k++){
            dfs(matrix, t, m, n, matrix[i][j], i+di[k], j+dj[k]);
        }        
    }
    
};
