//!!! sol2, my, use the orginal sequenc structure, O(n + q), O(n)
class RLEIterator {
private:
    vector<int> sequence;
    int idx;
public:
    RLEIterator(vector<int>& A) : sequence(A), idx(0) {}
    
    int next(int n) {        
        while(idx < sequence.size()){
            if(n > sequence[idx]){
                n -= sequence[idx];
            }
            else{
                sequence[idx] -= n;
                return sequence[idx+1];
            }            
            idx += 2;
        }
        return -1;
    }
};


// sol1, my, exceed memory limit, O(sum(mn)), O(sum(mn)) where m is the length of repeated number, n is the val of number
// class RLEIterator {
// private:
//     vector<int> sequence;
//     int idx;
// public:
//     RLEIterator(vector<int>& A) {
//         int i = 0;
//         idx = 0;
//         while(i < A.size()){
//             int times = A[i], num = A[i+1];
//             for(int j = 0; j < times; j++){
//                 sequence.push_back(num);
//             }
//             i += 2;
//         }
//         return;
//     }
    
//     int next(int n) {
//         idx += n;
//         if( idx <= sequence.size()){
//             return sequence[idx - 1];
//         }
//         else{
//             return -1;
//         }
//     }
// };

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
