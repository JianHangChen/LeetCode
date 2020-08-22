class Solution {
public:
    /**
     * @param A: a string A
     * @param B: a string B
     * @return: return the minimum number of operations to transform
     */
    int transform(string &A, string &B) {
        vector<int> countA(128, 0), countB(128,0);
        for(char c:A) countA[c]++;
        for(char c:B) countB[c]++;
        for(int i = 0; i < 128; i++){
            if(countA[i] != countB[i]) return -1;
        }
        
        int n = A.size();
        int i = n - 1, j = n - 1;
        while(i >= 0){
            if(A[i] == B[j]){
                i--;
                j--;
            }
            else{
                i--;
            }
        }
        return j+1;
    }
};
