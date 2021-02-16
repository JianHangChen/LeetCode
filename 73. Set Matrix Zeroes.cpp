// O(n), O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstColHas0 = false, firstRowHas0 = false;
        for(int i = 0; i < m ;i++){
            for(int j = 0; j < n ; j++){
                if(matrix[i][j] == 0){
                    if(i == 0) firstRowHas0 = true;
                    if(j == 0) firstColHas0 = true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j = 1; j < n; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }
        
        
        if(firstRowHas0){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }
        
        if(firstColHas0){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }
        
    }
};
