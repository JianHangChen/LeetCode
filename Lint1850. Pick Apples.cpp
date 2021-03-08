// !!! sol2, O(n), O(n) fix one and plus the max of the right
class Solution {
public:
    int PickApples(vector<int> &A, int K, int L) {
        int n = A.size();

        // edge case K, L > n 
        if(K + L > n) return -1;
        

        vector<int> ksum(n - K + 1), lsum(n - L + 1);
        for(int i = 0; i < K; i++) ksum[0] += A[i];
        for(int i = 1; i < ksum.size(); i++){
            ksum[i] = ksum[i-1] - A[i-1] + A[i+K-1];
        }
        for(int i = 0; i < L; i++) lsum[0] += A[i];
        for(int i = 1; i < lsum.size(); i++){
            lsum[i] = lsum[i-1] - A[i-1] + A[i+L-1];
        }
        int res = -1;
        int maxR = 0;
        for(int i = ksum.size() - 1; i >= 0; i--){
            int j = i + K;
            if(j >= lsum.size()) continue;
            maxR = max(maxR, lsum[j]);
            res = max(res, ksum[i] + maxR);
        }
        maxR = 0;
        for(int j = lsum.size() - 1; j >= 0; j--){
            int i = j + L;
            if(i >= ksum.size()) continue;
            maxR = max(maxR, ksum[i]);
            res = max(res, lsum[j] + maxR);
        }

        return res;
    }
};

// sol1, my, O(n^2), O(n)
// class Solution {
// public:
//     int PickApples(vector<int> &A, int K, int L) {
//         int n = A.size();

//         // edge case K, L > n 
//         if(K + L > n) return -1;
        

//         vector<int> ksum(n - K + 1), lsum(n - L + 1);
//         for(int i = 0; i < K; i++) ksum[0] += A[i];
//         for(int i = 1; i < ksum.size(); i++){
//             ksum[i] = ksum[i-1] - A[i-1] + A[i+K-1];
//         }
//         for(int i = 0; i < L; i++) lsum[0] += A[i];
//         for(int i = 1; i < lsum.size(); i++){
//             lsum[i] = lsum[i-1] - A[i-1] + A[i+L-1];
//         }
//         int res = -1;
//         for(int i = 0; i < ksum.size(); i++){
//             for(int j = 0; j < lsum.size(); j++){
//                 if(j >= i + K || i >= j + L){
//                     res = max(res, ksum[i] + lsum[j]);
//                 }
//             }
//         }
//         return res;

//     }
// };
