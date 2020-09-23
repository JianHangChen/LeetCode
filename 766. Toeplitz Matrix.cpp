// !!! followup2, streaming for partial row space, O(n^2), O(k)
// https://leetcode.com/problems/toeplitz-matrix/discuss/271388/Java-Solution-for-Follow-Up-1-and-2
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int k = 3;
        // 0 1 2 3 4 5
        for(int start = 0; start < n; start += (k-1)){
            int end = min(start+k, n);
            deque<int> dq;
            for(int j = start; j < end; j++) dq.push_back(matrix[0][j]);
            for(int i  = 1; i < m; i++){
                dq.pop_back();
                dq.push_front(matrix[i][start]);
                for(int j = start+1; j < end; j++){
                    if(matrix[i][j] != dq[j - start]) return false;
                }
            }
        }    
        return true;
    }
};
// !!! followup1, streaming for only one row, O(n^2), O(n)
// https://leetcode.com/problems/toeplitz-matrix/discuss/516366/Python-Follow-Up-1-with-Explanation-and-Diagrams
// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         deque<int> dq(matrix[0].begin(), matrix[0].end());
//         for(int i = 1; i < m; i++){
//             dq.pop_back();
//             dq.push_front(matrix[i][0]);
//             for(int j = 1; j < n; j++){
//                 if(matrix[i][j] != dq[j]) return false;
//             }
//         }
//         return true;
        
//     }
// };

// !!! sol2, check one by one, O(n^2), O(1)
// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
        
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(i + 1 < m && j + 1 < n && matrix[i][j] != matrix[i+1][j+1]) return false;
                
//             }
//         }
        
//         return true;
//     }
// };


// sol1, check for every hale (diagonal), O(n^2), O(1)
// class Solution {
// public:
//     bool isToeplitzMatrix(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
        
//         for(int d = -(m - 1); d < n; d++){
//             for(int t = max(0, -d), x = t; x < m; x++){
//                 int y = x + d;
//                 if(y < 0 || y >= n) break;
//                 if(matrix[x][y] != matrix[t][t+d]) return false;
//             }
//         }
//         return true;
//     }
// };
