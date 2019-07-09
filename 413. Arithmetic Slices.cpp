//  O(n), O(1)
class Solution{
public:
    int numberOfArithmeticSlices(vector<int>& A){
        int n = A.size();
        int count = 0;
        int p = 0, q = p + 2;
        while(q < n){
            if(A[q]- A[q-1] == A[p+1] - A[p]){
                count += (q - (p + 1) );
                q++;
            }
            else{
                p = q - 1;
                q = p + 2;
            }
        }
        return count;
        
    }
};
