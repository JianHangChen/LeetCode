class NumMatrix {

private:
    vector<vector<int>> bit;
    vector<vector<int>> data;
    int m,n;
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty() ){
            cout << "empty";
            return;
        }
        m = matrix.size(); n = matrix[0].size();
        
        data.resize(m,vector<int> (n, 0));
        
        // binary indexed tree
        bit.resize(m + 1, vector<int>(n + 1, 0)); // 0 is dummy point


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                update(i, j, matrix[i][j]);
            }
        }        
        
    }
    
    void update(int row, int col, int val) {
        int offset = val - data[row][col];
        data[row][col] = val;
        for(int idx = row + 1; idx <= m; idx += idx&(-idx)){
            for(int jdx = col + 1; jdx <= n; jdx += jdx&(-jdx)){
                bit[idx][jdx] += offset;
            }
        }
    }
    
    int getsum(int i, int j){
        int s = 0;
        for(int idx = i + 1;idx > 0; idx -= idx&(-idx)){
            for(int jdx = j + 1;jdx > 0; jdx -= jdx&(-jdx)){
                s += bit[idx][jdx];
            }
        }
        return s;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        return getsum(row2, col2) - getsum(row2, col1 - 1) - getsum(row1 - 1, col2) + getsum(row1 - 1, col1 - 1);
    }
};
