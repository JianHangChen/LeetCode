// my sol1, same as sol3
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool incre = true, dec = true;
        for(int i = 0; i < A.size() - 1; i++){
            if(A[i] > A[i+1]) incre = false;
            else if(A[i] < A[i+1]) dec = false;
            if(!incre && !dec) return false;
        }
        return true;
    }
};
