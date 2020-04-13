
// !!! sol3.1, O(logn), O(1), revised from sol3 for matrix multiplication
// from https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/575485/C%2B%2BPython-O(logN)-Time
class Solution{
public:
    long mod = 1e9+7;
    int numOfWays(int n){
        vector<vector<long>> v = {{6},
                                  {6}};
        vector<vector<long>> M = {{3, 2},
                                  {2, 2}};
        int iteration = n - 1;
        
        while(iteration > 0){
            if(iteration % 2 == 1){
                // v = M * v
                v = matMul(M, v);
                iteration--;
            }
            else{
                // M = M * M;
                M = matMul(M, M); 
                iteration /= 2;
            }
        }
        return (v[0][0] + v[1][0])%mod;        
    }
    vector<vector<long>> matMul(vector<vector<long>>& M1, vector<vector<long>>& M2){
        int m = M1.size(), n = M2[0].size();
        int l = M2.size();
        vector<vector<long>> ans(m, vector<long> (n));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ;j++){
                for(int k = 0; k < l; k++){
                    ans[i][j] += M1[i][k] * M2[k][j] % mod;
                    ans[i][j] %= mod;
                }
            }
        }
        return ans;
    }
    
};


// !!! sol3, O(logn), O(1)
// from https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/575485/C%2B%2BPython-O(logN)-Time
// class Solution{
// public:
//     int numOfWays(int n){
//         long long i = 6, j = 6;
//         long long x, y, mod = 1e9+7;
//         int iteration = n - 1;
        
//         vector<vector<long long>> m =  {{3, 2},
//                                         {2, 2}};
        
//         while(iteration > 0){
//             if(iteration % 2 == 1){
//                 // v = M * v
                
//                 x = i * m[0][0] + j * m[0][1];
//                 y = i * m[1][0] + j * m[1][1];
//                 i = x % mod;
//                 j = y % mod;
//                 iteration--;
//             }
//             else{
//                 // M = M * M;
//                 vector<vector<long long>> tmp(2, vector<long long> (2));
//                 for(int a = 0; a < 2; a++){
//                     for(int b = 0; b < 2; b++){
//                         for(int k = 0;  k < 2; k++){
//                             tmp[a][b] += m[a][k] * m[k][b] % mod;
//                             tmp[a][b] %= mod;
//                         }
//                     }
//                 }
//                 m = tmp;
//                 iteration /= 2;
//             }
//         }
//         return (i + j)%mod;
        
//     }
// };



// !!!! sol2, my, math, O(n), O(1), best
class Solution {
public:
    int numOfWays(int n) {
        long long i = 6, j = 6;
        long long x,y, mod = 1e9+7;
        
        while(n > 1){
            x = i * 3 + j * 2;
            y = i * 2 + j * 2;
            i = x % mod;
            j = y % mod;
            n--;
        }
        return (i + j)%mod;
    }
};

// my sol1, use dfs, tle
// class Solution {
// public:
//     int res;
//     int numOfWays(int n) {
//         vector<vector<int>> grid(n, vector<int> (3));
//         dfs(grid, 0, 0);
//         return res;
//     }
//     void dfs(vector<vector<int>>& grid, int i, int j){
//         int n = grid.size();
//         if(i == n && j == 0){
//             res++;
//             res = res % (1000000007);
//             return;
//         }
//         else{
//             for(int color = 0; color <= 2; color++){
//                 if( (i == 0 || i > 0 && grid[i-1][j] != color) 
//                    && (j == 0 || j > 0 && grid[i][j-1] != color) ){
//                     grid[i][j] = color;
//                     if(j == 2){
//                         dfs(grid, i+1, 0);
//                     }
//                     else{
//                         dfs(grid, i, j+1);
//                     }                    
//                 }
//             }
//         }
        
//     }
// };
