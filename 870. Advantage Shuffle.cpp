// !!! sol4, sort and two pointers, from gy2
class Solution{
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B){
        int n = A.size();
        vector<int> res(n,0), temp = res;
        vector<pair<int, int>> vB;
        for(int i = 0; i < B.size(); i++) vB.push_back({B[i], i});
        
        sort(A.begin(), A.end());
        sort(vB.begin(), vB.end());
        
        int a = 0, b = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(A[b] > vB[i].first){
                res[vB[i].second] = A[b--];
            }
            else{
                res[vB[i].second] = A[a++];
            }
        }
        return res;
        
    }
        
};




//!!!  sol3, my, O(nlogn), hint from gy1, multi Treeset

// class Solution{
// public:
//     vector<int> advantageCount(vector<int>& A, vector<int>& B){
//         multiset<int> A_set(A.begin(), A.end());
//         vector<int> res = A;


//         for(int i = 0; i < B.size(); i++){
//             auto pos = A_set.upper_bound( B[i]); //!!!how to write upper bound
//             if(pos == A_set.end()){
//                 pos = A_set.begin();
//             }
//             res[i] = *pos;
//             A_set.erase(pos);
//         }
//         return res;
//     }
// };



// //sol2, my O(n^2)
// class Solution{
// public:
//     vector<int> advantageCount(vector<int>& A, vector<int>& B){
//         vector<int> res = A;
//         sort(A.begin(), A.end());
        
//         for(int i = 0; i < B.size(); i++){
//             bool found = false;
//             for(int j = 0; j < A.size(); j++){
//                 if(A[j] > B[i]){
//                     res[i] = A[j];
//                     A.erase(A.begin() + j);
//                     found = true;
//                     break;
//                 }
//             }
//             if(!found){
//                 res[i] = A.front(); A.erase(A.begin());
//             }
//         }
//         return res;
//     }
// };



// // sol1, my, dfs, backtracking
// class Solution {
// private:
//     int advantage = 0;
//     vector<int> best;
// public:
//     vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        
//         best = A;
//         permute(0, A, B);
//         return best;
//     }
//     void permute(int start, vector<int>& A, vector<int>& B){
//         if(start == A.size()){

//             int AB_advantage = compareAdvantage(A,B);
//             if(AB_advantage > advantage){
//                 advantage = AB_advantage;
//                 best = A;
//             }
//         }
//         for(int i = start; i < A.size(); i++){
//             swap(A[start], A[i]);
//             permute(start + 1, A, B);
//             swap(A[start], A[i]);
//         }

//     }

//     int compareAdvantage(vector<int>& A, vector<int>& B){
//         int res = 0;
//         for(int i = 0; i < A.size(); i++){
//             if(A[i] > B[i]) res++;
//         }
//         return res;
//     }
// };
