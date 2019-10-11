
  // !!! sol2, my, careful of overflow
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
      int n = A.size();
      if(n <= 0) return 0;

      long long sumA = 0, pre = 0;

      for(int i = 0; i < n; i++){
        sumA += A[i];
        pre += A[i] * i;
      }
      
      long long res = pre;

      for(int k = 1; k < n; k++){
        pre = pre -  (long long)A[n - k] * n + sumA;
        res = max(res, pre);
      }
      return res;  
    }
};


// sol1, my brute force, tle

// class Solution {
// public:
//     int maxRotateFunction(vector<int>& A) {
//       if(A.size() <= 0) return 0;

//       int res = INT_MIN;
//       for(int k = 0; k < A.size(); k++) res = max(res, F(A, k));
//       return res;  
//     }

//     int F(vector<int>& A, int k){
//       int res = 0, n = A.size();

//       for(int i = 0;  i < n; i++){
//         res += A[i] * ( (i + k) % n );
//       }
//       return res;
//     }
// };
