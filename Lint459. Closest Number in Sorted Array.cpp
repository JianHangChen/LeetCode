// !!! sol2, 新模板
class Solution {
public:
    int closestNumber(vector<int> &A, int target) {
        if(A.empty()) return -1;

        int l = 0, r = A.size() - 1;
        while(l < r - 1){
            int mid = l + (r - l) / 2;
            if(A[mid] < target){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        // post processing
        if(target - A[l] < A[r] - target){
            return l;
        }
        else{
            return r;
        }

    }

};


// sol1, my, Old version
// !!! 122222222222222223, target = 1 can work
class Solution {
public:
    /**
     * @param A: an integer array sorted in ascending order
     * @param target: An integer
     * @return: an integer
     */
    int closestNumber(vector<int> &A, int target) {
        if(A.empty()) return -1;

        int i = 0, j = A.size() - 1;
        
        while(i < j){
            int mid = i + (j - i) / 2;
            if(target - A[mid] <= A[mid+1] - target){
                j = mid;
            }
            else{
                i = mid+1;
            }
        }
        return i;
    }

};
