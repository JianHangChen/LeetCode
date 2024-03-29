

// //!!!!!! sol3.1, greedy, from sol, O(n), O(1)
// // can solve unreachble array problem

// case 1: [3]
// case 2: [3 1]
// case 3: [2, 3, 1, 1, 4]
// case 4: [2 1 0 1]

class Solution{
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        int pre = 0, cur = 0, step = 0;
        for(int i = 0; i < n; i++){
            if(i > pre){
                step++;
                if(pre == cur) return -1; // if pre_max == cur_max, that's not moving!! false 
                pre = cur;
            }
            if(pre >= n - 1) break;
            
            cur = max(cur, i + nums[i]);
        }
        return step;

    }
};

// !!! sol3, greedy, from sol, O(n), O(1)
class Solution{
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        if(n <= 1) return 0;
        int pre_max = nums[0], cur_max = nums[0], steps = 1;
        for(int i = 1; i < n; i++){
            if(i > pre_max){
                steps++;
                pre_max = cur_max; 
            }
            cur_max = max(cur_max, i + nums[i]);
        }
        return steps;
        
    }
};





sol2, my, bfs, tle, O(n^2)
class Solution{
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        
        int jumps = 0;
        while(!q.empty()){
            int l = q.size();
            
            for(int i = 0; i < l; i++){
                int idx = q.front(); q.pop();
                if(idx == n - 1) return jumps;
                
                for(int j = idx + 1; j <= min(idx + nums[idx], n - 1); j++){
                    if(!visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }
            jumps++;
        }
        return jumps;
    }    
};



! sol1.1, my dp, O(n^2), O(n), better
class Solution{
public:
    int jump(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j <= i + nums[i] && j < n; j++){
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        
        return dp[n-1];
    }
};

sol1, my, dp, O(n^2), O(n), tle

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for(int i = n - 2; i >= 0; i--){
            int max_idx = min(i + nums[i], n - 1);
            for(int j = i + 1; j <= max_idx; j++){
                if(dp[j] != INT_MAX) dp[i] = min(dp[i], dp[j] + 1); 
            }
        }
        return dp[0];
        
        
    }
};
