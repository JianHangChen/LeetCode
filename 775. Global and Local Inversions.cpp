//sol1, max_bar
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        if(n <= 1) return true;
        int m = INT_MIN; //max value from the left to i
        for(int i = 0; i < n - 2; i++){
            m = max(m, A[i]);
            if(A[i + 2] < m) return false;
        }
        return true;
    }
};

// sol2, abs, from grandyang
// class Solution{
// public:
//     bool isIdealPermutation(vector<int>& A){
//         int n = A.size();
//         for(int i = 0; i < n; i++){
//             if(abs(A[i] - i) > 1)  return false;
//         }
//         return true;
//     }    
// }

