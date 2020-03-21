

// !sol2, my, not inline  O(n^2), O(n)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        vector<int> dp(triangle.back());
        for(int i = n - 1; i > 0; i--){
            for(int j = 0; j < i; j++){
                dp[j] = triangle[i-1][j] + min( dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};


// !!!sol1, my, inline, O(n^2), O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n == 0) return 0;
        for(int i = n - 1; i > 0; i--){
            for(int j = 0; j < i; j++){
                triangle[i-1][j] = triangle[i-1][j] + min( triangle[i][j], triangle[i][j+1]);
            }
        }
        return triangle[0][0];
    }
};
