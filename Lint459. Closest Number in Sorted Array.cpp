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
