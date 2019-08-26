// sol2, !!! from grandyang, O(m+n)

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        
        int i = m - 1, j = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] == target) return true;
            if(matrix[i][j] > target) i--;
            else j++;

        }
        
        return false;
        
    }
    
};

// sol1, my, O(mlogn)
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.empty() || matrix[0].empty()) return false;
//         int m = matrix.size(), n = matrix[0].size();
        
//         for(int i = 0; i < m; i++){
//             if(matrix[i][0] > target) return false;
            
//             auto iter = lower_bound(matrix[i].begin(), matrix[i].end(), target);
//             if(iter == matrix[i].end()) continue;
//             if(*iter == target) return true;            
//         }
//         return false;
        
        
//     }
// };
