// !!! sol2, dp with tree for fast search
// O(nlogn), O(n)
//https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/409009/JavaC%2B%2BPython-DP-Solution
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> data;
        for(int i = 0; i < n; i++) data.push_back({endTime[i], startTime[i], profit[i]});
        sort(data.begin(), data.end());
        map<int, int> dp;
        dp[0] = 0; //
        for(int i = 0; i < n; i++){
            int end = data[i][0], start = data[i][1], pro = data[i][2];
            int dpj = prev(dp.upper_bound(start))->second; // get the valid item j in the treemap
            dp[end] = max(pro+dpj, dp.rbegin()->second );
        }
        return dp.rbegin()->second;
    }
};


//!!! sol1, nice dp solution with a little bit greedy(find the closest no overlap index)
// O(n^2), O(n)
// https://leetcode.com/problems/maximum-profit-in-job-scheduling/discuss/411535/C%2B%2B-DP-explained-with-an-example-...
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> data;
        for(int i = 0; i < n; i++){
            data.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(data.begin(), data.end());
        
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++){
            if(i == 0){
                dp[i] = data[i][2];
                continue;
            }
            int nonOverlap = 0;
            for(int j = i - 1; j >= 0; j--){
                if(data[j][0] <= data[i][1]){ // endtimej <= starTime i
                    nonOverlap = dp[j];
                    break;
                }
            }
            dp[i] = max(dp[i-1], nonOverlap + data[i][2]);

        }
        
        return dp[n-1];
        
    }
};
