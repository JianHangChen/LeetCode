
// !!! sol1, floyd warshall, O(n^3), O(n^2)

// [1, 0]  1-> 0

// queries [i][0] -> queries[i][1] ?
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<bool>> mat(n, vector<bool> (n, false));
        
        for(auto& pre:prerequisites){
            mat[pre[0]][pre[1]] = true;
        }
        
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    mat[i][j] = mat[i][j] || (mat[i][k] && mat[k][j]);
                }
            }
        }
        vector<bool> res;
        for(auto& q: queries){
            res.push_back(mat[q[0]][q[1]]);
        }
        return res;
    }    
};
