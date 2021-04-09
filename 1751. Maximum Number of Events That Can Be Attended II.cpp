// !!!!! sol2, O(nlogn+nk), O(nk)
// https://www.youtube.com/watch?v=DBsANiXd0LA
class Solution {
public:
    struct CMP{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        }
    } cmp;
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp); // sort by the end date
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
        // dp[i][j] means  for at most i elements [0, i-1] inclusive, with at most j step, the maximum value we can have
        // base        
        // dp[i][0] = 0
        map<int, int> m;
        m[0] = 0; // 
        for(int i = 1; i <= n; i++){  // n
            // find no overlap index from [0, i-1]
            int noOverlapIdx = getIdx( events, i); // logn
            
            // case 1, do this job i-1, dp[i][j] = dp[noOverlapIdx][j-1] + events[i-1][2]
            // case 2, do not do this job, dp[i][j] = dp[i-1][j]
            for(int j = 1; j <= k; j++){ // k
                dp[i][j] = max(dp[noOverlapIdx][j-1] + events[i-1][2], dp[i-1][j]);
            }
        }
        return dp[n][k];
    }
    // get no overlap index
    int getIdx(vector<vector<int>>& events, int i){
        int l = 1, r = i;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(events[mid-1][1] < events[i-1][0]){ // mid - 1 is a good event, no overlap
                l = mid + 1;
            }
            else{ // overlap, mid is too big
                r = mid;
            }
        }
        return l - 1;
    }
};


// !!! sol1, dp with early break, O(n^2), O(nk)
// https://www.youtube.com/watch?v=DBsANiXd0LA

class Solution {
public:
    struct CMP{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        }
    } cmp;
    
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end(), cmp); // sort by the end date
        vector<vector<int>> dp(n+1, vector<int> (k+1, 0));
        // dp[i][j] means  for at most i elements [0, i-1] inclusive, with at most j step, the maximum value we can have
        // base        
        // dp[i][0] = 0
        for(int i = 1; i <= n; i++){ 
            // find no overlap index from [0, i-1]
            int noOverlapIdx = 0;
            for(int t = i - 1; t >= 1; t--){
                if(events[t-1][1] < events[i-1][0]){
                    noOverlapIdx = t; break;
                }
            }
            
            // case 1, do this job i-1, dp[i][j] = dp[noOverlapIdx][j-1] + events[i-1][2]
            // case 2, do not do this job, dp[i][j] = dp[i-1][j]
            for(int j = 1; j <= k; j++){
                dp[i][j] = max(dp[noOverlapIdx][j-1] + events[i-1][2], dp[i-1][j]);
            }
        }
        return dp[n][k];
    }
};


// [[1,2,4],[3,4,3],[2,3,1]], k = 2 
// [1,2,1],[2,2,2],[2,3,4],[4,4,4] k = 3
