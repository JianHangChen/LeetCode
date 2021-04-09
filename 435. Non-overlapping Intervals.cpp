//!!!! sol1, from gy1, O(nlogn), O(1)
// greedy
// if overlap:  remove the longer interval (with larger end point) first
// if not overlap: update the interval
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return 0;
        
        int count = 0;
        sort(intervals.begin(), intervals.end());
        
        int preIdx = 0;
        for(int i = 1; i < intervals.size(); i++){
            auto cur = intervals[i]; auto pre = intervals[preIdx];
            if(pre[1] > cur[0]){
                count++;
                if(pre[1] >= cur[1]) preIdx = i;
            }
            else{
                preIdx = i;
            }
        }
        return count;
        
    }
};

// [[1,100],[11,22],[1,11],[2,12]]
// 1 100,  1 11, 2 12,  11 22

//  1 11, 1 100, 2 12,  11 22


// sol2, dp, O(n^2), O(n)
// [[1,2],[2,3],[3,4],[1,3]]
// 1 2, 1 3, 2 3, 3 4

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n, 1);
        // dp[i], the maximum intervals we can take for [0, i] intervals in total
        // base case dp[0] = 1
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(intervals[i][1] <= intervals[j][0]){
                    dp[j] = max(dp[i] + 1, dp[j]);
                }
            }
        }
        return n - dp[n-1];
    }
};



// sol2.2, much better dp, O(n^2), O(n)
// early break compare to sol2

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        sort(intervals.begin(), intervals.end());
        vector<int> dp(n, 1);
        // dp[i], the maximum intervals we can take for [0, i] intervals in total
        // base case dp[0] = 1
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1];
            for(int j = i-1; j >= 0; j--){
                if(intervals[j][1] <= intervals[i][0]){
                    dp[i] = max(dp[j] + 1, dp[i]);
                    break;
                }
            }
        }
        return n - dp[n-1];
    }
};
