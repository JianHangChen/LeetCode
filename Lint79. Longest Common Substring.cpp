// sol2, brute force, from ch9 c++, O(m * n * max(m,n)), O(1)
// class Solution {
// public:
//     int longestCommonSubstring(string &A, string &B) {
//         int maxlen = 0;
//         for(int i = 0; i < A.size(); i++){
//             for(int j = 0; j < B.size(); j++){
//                 int len = 0;
//                 while(i+len < A.size() && j + len < B.size() ){
//                     if(A[i+len] != B[j+len]) break;
//                     len++;
//                 }
//                 maxlen = max(len, maxlen);
                
//             }
//         }
//         return maxlen;
//     }
};


// !!!! sol1, dp, from ch9 java1, O(mn), O(mn)
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int n1 = A.size(), n2 = B.size();
        vector<vector<int>> dp(n1, vector<int> (n2));
        int maxlen = 0;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(A[i] != B[j]){
                    dp[i][j] = 0;
                }
                else{
                    if(i == 0 || j == 0) dp[i][j] = 1;
                    else{
                        dp[i][j] = dp[i-1][j-1] + 1;                    
                    }
                }
                maxlen = max(maxlen, dp[i][j]);
            }
        }
        return maxlen;
    }
};
