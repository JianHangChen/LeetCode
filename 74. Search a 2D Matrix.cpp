
// sol3,!!! binary search only once, from grandyang O(logn+logm)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(); if(m <= 0) return false;
        int n = matrix[0].size(); if(n <= 0) return false;
        
        
        int low = 0, high = m * n - 1, mid;
        while(low < high){
            mid = low + (high - low) / 2;
            
            if(matrix[mid / n][mid % n] == target) return true;
            else if(matrix[mid / n][mid % n] > target) high = mid;
            else low = mid + 1;            
        }
        return matrix[low / n][low % n] == target;
        
    }
};

// sol2, my, bound, binsearch twice
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(); if(m <= 0) return false;
//         int n = matrix[0].size(); if(n <= 0) return false;
        
//         vector<int> col(m,0);
//         for(int i = 0; i < m; i++) col[i] = matrix[i][0];
        
//         auto iter = upper_bound(col.begin(), col.end(), target);
//         if(iter == col.begin()) return false;
//         int row = iter - col.begin() - 1;
        
//         auto lower = lower_bound(matrix[row].begin(), matrix[row].end(), target); // don't use the same name twice
//         if(lower == matrix[row].end()) return false;
//         return target == *lower;        
//     }
// };
        
// sol1, my binary search
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         if(matrix.empty()||matrix[0].empty()) return false;
//         int m = matrix.size(), n = matrix[0].size();
        
//         int low = 0, high = m;
//         int mid;
//         while(low < high){
//             mid = low + (high - low) / 2;
            
//             if(matrix[mid][0] > target){
//                 high = mid;
//             }
//             else{
//                 low = mid + 1;
//             }
            
//         }

//         int row = low - 1;
//         if(row < 0) return false;
        
//         low = 0, high = n - 1;
//         while(low < high){
//             mid = low + (high - low) / 2;
//             if(matrix[row][mid] >= target){
//                 high = mid;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }
        
//         return matrix[row][low] == target;
        
//     }
// };
