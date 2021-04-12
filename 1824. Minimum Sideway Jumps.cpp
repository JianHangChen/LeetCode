

// !!! sol2, O(n), O(1)
// https://leetcode.com/problems/minimum-sideway-jumps/discuss/1152665/JavaC%2B%2BPython-DP-O(1)-space
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1, nextLane1, nextLane2;
        vector<int> dp = {0, 1, 0, 1}; // idx 0 1 2 3

        // dp[i] minJump for frog jump to lane i in current step
        for(int step = 1; step <= n; step++){
            dp[obstacles[step]] = 1e9;
            for(int lane = 1; lane <= 3; lane++){
                if(lane == obstacles[step]) continue;
                nextLane1 = (lane - 1 + 1) % 3 + 1;
                nextLane2 = (lane - 1 + 2) % 3 + 1;
                dp[lane] = min(dp[lane], min(dp[nextLane1] + 1, dp[nextLane2] + 1));
            }
        }
        
        return min(dp[1], min(dp[2], dp[3]));
    }
};

// sol1, my, O(n), O(n)
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(n+1, vector<int> (4, 1e9));
        // dp[i][j] minJump for frog jump to point i, lane j
        
        // base case:
        dp[0][2] = 0; dp[0][1] = 1; dp[0][3] = 1;
        for(int i = 1; i <= n; i++){
            int obs = obstacles[i];
            for(int j = 1; j <= 3; j++){
                if(j == obs) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }
            for(int j = 1; j <= 3; j++){
                if(j == obs) continue;
                if(j - 2 >= 1) dp[i][j] = min(dp[i][j], dp[i][j-2] + 1);
                if(j + 2 <= 3) dp[i][j] = min(dp[i][j], dp[i][j+2] + 1);

                if(j - 1 >= 1) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                if(j + 1 <= 3) dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
            }
        }
        int res = 1e9;
        for(int i = 1; i <= 3; i++) res = min(res, dp[n][i]);
        return res;
    }
};
