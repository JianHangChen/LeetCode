// sol1,  query O(1), precumpute O(mn), space O(mn)
class NumMatrix {
private:
    vector<vector<int>> s;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> temp(m, vector<int> (n,0)); s = temp;
        
        int a  = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                s[i][j] = matrix[i][j];
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 1; j < n; j++){
                s[i][j] += s[i][j-1];
            }
        }
        for(int j = 0; j < n; j++){
            for(int i = 1; i < m; i++){
                s[i][j] += s[i-1][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int block1 = col1 > 0 ? s[row2][col1-1] : 0;
        int block2 = row1 > 0 ? s[row1-1][col2] : 0;
        int block3 = col1 > 0 && row1 > 0 ? s[row1-1][col1-1] : 0;
        
        return s[row2][col2]-block1-block2+block3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
