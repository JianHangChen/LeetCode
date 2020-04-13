
// !!! sol2.1, dp , O(logN), O(1)
// from https://leetcode.com/problems/knight-dialer/discuss/189252/O(logN)
// use short matrix multiplication by reducing to vector
class Solution{
private:
    
public:
    long long mod = 1e9+7;
    int knightDialer(int N){
        
        vector<vector<long long>> M(10, vector<long long> (10));
        vector<long long> v(10,1);
        M[0][4] = 1; M[0][6] = 1;
        M[1][6] = 1; M[1][8] = 1;
        M[2][7] = 1; M[2][9] = 1;
        M[3][4] = 1; M[3][8] = 1;
        M[4][3] = 1; M[4][0] = 1; M[4][9] = 1;
        M[6][1] = 1; M[6][7] = 1; M[6][0] = 1;
        M[7][2] = 1; M[7][6] = 1;
        M[8][1] = 1; M[8][3] = 1;
        M[9][2] = 1; M[9][4] = 1;
        
        v = matrixPow_Vec(M, N-1,v);
        
        int res = 0;
        for(int i = 0; i < 10; i++){
            res = (res + v[i]) % mod;
        }
        return res;
    }
    vector<long long> matrixPow_Vec(vector<vector<long long>>& M, int n, vector<long long>& v){
        int len = v.size();
        
        
        while(n > 0){
            if(n % 2 == 1){
                // v = M*v
                vector<long long> tmp(len, 0);
                for(int i = 0; i < v.size(); i++){
                    for(int k = 0; k < v.size(); k++){
                        tmp[i] += M[i][k] * v[k] % mod;
                        tmp[i] %= mod;
                    }
                }
                v = tmp;
                n--;
            }
            else{
                // M = M * M
                vector<vector<long long>> tmp(len, vector<long long> (len));
                for(int i = 0; i < len; i++){
                    for(int j = 0; j < len; j++){
                        for(int k = 0; k < len; k++){
                            tmp[i][j] += M[i][k] * M[k][j] % mod;
                            tmp[i][j] %= mod;
                        }
                    }
                }
                M = tmp;
                n /= 2;
            }
        }
        return v;
    }

    
    
};


// // sol2, dp , O(logN), O(1)
// // from https://leetcode.com/problems/knight-dialer/discuss/189252/O(logN)
// // just to practice matrix multiplication
// class Solution{
// private:
    
// public:
//     long long mod = 1e9+7;
//     int knightDialer(int N){
        
//         vector<vector<long long>> M(10, vector<long long> (10));
//         vector<long long> v(10,1);
//         M[0][4] = 1; M[0][6] = 1;
//         M[1][6] = 1; M[1][8] = 1;
//         M[2][7] = 1; M[2][9] = 1;
//         M[3][4] = 1; M[3][8] = 1;
//         M[4][3] = 1; M[4][0] = 1; M[4][9] = 1;
//         M[6][1] = 1; M[6][7] = 1; M[6][0] = 1;
//         M[7][2] = 1; M[7][6] = 1;
//         M[8][1] = 1; M[8][3] = 1;
//         M[9][2] = 1; M[9][4] = 1;
        
//         M = matrixPow(M, N-1);
        
//         v = matrixMulVec(M, v);
        
//         int res = 0;
//         for(int i = 0; i < 10; i++){
//             res = (res + v[i]) % mod;
//         }
//         return res;
//     }
//     vector<vector<long long>> matrixPow(vector<vector<long long>>& M, int n){
//         vector<vector<long long>> ans(10, vector<long long> (10,0));
//         for(int i = 0; i < 10; i++) ans[i][i] = 1; // ans = eye
        
//         while(n > 0){
//             if(n % 2 == 1){
//                 ans = matrixMul(ans, M);
//                 n--;
//             }
//             else{
//                 M = matrixMul(M, M);
//                 n /= 2;
//             }
//         }
//         return ans;
//     }
    
//     vector<vector<long long>> matrixMul(vector<vector<long long>>& M1, vector<vector<long long>>& M2){
//         int n = M1.size();
        
//         vector<vector<long long>> ans(n, vector<long long> (n));
        
        
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 for(int k = 0; k < n; k++){
//                     ans[i][j] += M1[i][k] * M2[k][j] % mod;
//                     ans[i][j] %= mod;
//                 }
//             }
//         }
//         return ans;    
//     }    
    
//     vector<long long> matrixMulVec(vector<vector<long long>>& M, vector<long long>& v){
//         int n = v.size();
//         vector<long long> ans(n);
//         for(int i = 0; i < n; i++){
//             for(int k = 0; k < n; k++){
//                 ans[i] += M[i][k] * v[k] % mod;
//                 ans[i] %= mod;
//             }
//         }
//         return ans;
//     }
    
    
// };





// !!! sol1, my dp, O(N), O(1)
class Solution {
private:
    vector<vector<int>> neighbours = {{4,6}, {6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
public:
    int knightDialer(int N) {
        int res = 0, MOD = 1e9+7;
        vector<int> nums(10,1);
        for(int j = 1; j < N; j++){
            vector<int> temp(10,0);
            for(int i = 0; i < 10; i++){
                for(int nei:neighbours[i]){
                    temp[nei] = (temp[nei] + nums[i]) % MOD;
                }
            }
            nums = temp;
        }
        for(int i = 0; i < 10; i++){
            res = (res + nums[i]) % MOD;
        }
        return res;
    }
};
