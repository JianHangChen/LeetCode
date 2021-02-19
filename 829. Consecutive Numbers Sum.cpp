// k = 3
    
// 9: 3, 4, 5
//     x, x+1, x+2
//     x+0, x+1, x+(k-1)

// k = 1
//     n = x
// k = 2
//     n = x + (x + 1)
// k = 3
//     n = x + (x + 1) + (x + 2)

// n = sum( x, x+1, ..., x+(k-1))
//   = kx + (k-1)*k/2

// !!!sol1, O(sqrt(N)), O(1)
class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int res = 0;
        for(int k = 1; k * (k + 1) / 2 <= N; k++){
            if( (N - (k-1)*k/2) % k == 0 ) res++;
        }
        return res;        
    }
};


  



// sol2, 

// #include <cmath>
// class Solution{
// public:
//     int consecutiveNumbersSum(int N){
//         int res = 0;
//         int bound = sqrt(2 * N) - 1;
//         for(int p = 0; p <= bound; p++){
//             if( (2*N - p*(p+1)) % (2 * (p + 1)) == 0)  res++;
//         }
//         return res;
        
//     }    
// };


// sol2, from sol2
// class Solution{
// public:
//     int consecutiveNumbersSum(int N){
//         int res = 0;
//         int bound = sqrt(2 * N) - 1; int pre_x = INT_MAX;

//         for(int p = 0; p <= bound; p++){
//             float x = (2.0 * N / (p+1) - p ) / 2.0;
//             if( x == (int) x && (int)x < pre_x && x <= N && x >= 1){
//                 res++;
//                 pre_x = (int) x;
//             }
//         }
//         return res;
        
//     }    
// };

//sol1, brute force, from sol1, TLE O(N^2)
// class Solution {
// public:
//     int consecutiveNumbersSum(int N) {
//         int res = 0;
//         for(int i = 1; i <= N; i++){
//             int s = 0, j = i;
//             while(s < N){
//                 s += j;
//                 j++;
//                 if(s == N) res++; 
//             }
//         }
//         return res;
//     }
// };
