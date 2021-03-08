// !!! sol1.1, my , after revised by https://www.jiuzhang.com/solution/subarray-sum-ii/ linghu
// O(n), O(1)
// A = [1, 2, 3, 4], start = 1, end = 3
// j = 0
// istart = 0, iend = 0
// sstart = 1, send = 1

class Solution {
public:
    int subarraySumII(vector<int> &A, int start, int end) {
        if(start > end) return 0;

        int res = 0;
        int n = A.size();
        int istart = 0, iend = 0; //index
        int sstart = 0, send = 0;//sum

        for(int j = 0; j < n ; j++){
            sstart += A[j];
            send += A[j];

            //move istart to first valid position [istart, j] or istart = j+1, sum = 0
            while(istart <= j && sstart > end){ // edge case end = -4
                sstart -= A[istart++]; 
            }

            //  when iend is valid, move to next position or iend = j+1, sum = 0
            while(iend <= j && send >= start){
                send -= A[iend++];
            }

            res += iend - istart;
        }
        return res;
    }
};






// A = [1, 2, 3, 4], start = 1, end = 3
// j = 0
// iend = 0, send = 1
// istart = 0, sstart = 1
// res += 1 
// j = 1
// iend = 0, send = 3
// istart = 0, sstart = 3





// sol1 my first version
// fail for [1, 2, 3, 4]
// -3, 3

// class Solution {
// public:

//     int subarraySumII(vector<int> &A, int start, int end) {
//         int res = 0;
//         int n = A.size();
//         int iend = 0, istart = 0;
//         int send = 0, sstart = 0;

//         for(int j = 0; j < n ; j++){
//             sstart += A[j];
//             send += A[j];
//             while(sstart > end && istart <= j){ // edge case end = -1
//                 sstart -= A[istart++];
//             }
//             while(iend <= j && send - A[iend] >= start){
//                 send -= A[iend++];
//             }
//             if(istart <= j && sstart <= end && send >= start) res += iend - istart + 1;
//         }
//         return res;
//     }
// };
