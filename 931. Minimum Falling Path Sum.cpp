

// !!! sol1.1, my dp, improved by 9ch,  O(n^2), O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                int topleft = A[i-1][max(j-1, 0)];
                int topright = A[i-1][min(j+1, n - 1)];
                A[i][j] += min({A[i-1][j], topleft, topright});
            }
        }
        int res = INT_MAX;
        for(int j = 0; j < n; j++) res = min(res, A[n - 1][j]);
        return res;
    }
};


// sol1, my dp, O(n^2), O(1)
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& A) {
//         int n = A.size();
//         for(int i = 1; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 int smallest = A[i - 1][j];
//                 if(j - 1 >= 0){
//                     smallest = min(smallest, A[i - 1][j - 1]);
//                 }
//                 if(j + 1 < n){
//                     smallest = min(smallest, A[i - 1][j + 1]);
//                 }
//                 A[i][j] += smallest;
//             }
//         }
//         int res = INT_MAX;
//         for(int j = 0; j < n; j++) res = min(res, A[n - 1][j]);
//         return res;
//     }
// };
