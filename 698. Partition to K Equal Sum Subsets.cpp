// sol1, O(2^n), O(n)
// https://www.youtube.com/watch?v=qpgqhp_9d1s
// https://www.geeksforgeeks.org/partition-set-k-subsets-equal-sum/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0,n = nums.size();
        for(int num:nums) total+=num;
        sort(nums.begin(), nums.end(), greater<int> ());
        
        int avg = total / k;
        if(total % k != 0 || nums[0] > avg || n < k) return false;

        vector<bool> visited(n, false); // index
        return DFS(nums, k, 0, avg, 0, visited);
        
    }
    bool DFS(vector<int>& nums, int k, int cursum, int avg, int start, vector<bool>& visited){
        if(k <= 1) return true;
        if(cursum == avg){
            return DFS(nums, k-1, 0, avg, 0, visited);
        }

        if(cursum > avg) return false;


        for(int i = start; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = true;
                bool res = DFS(nums, k, cursum + nums[i], avg, i+1, visited); 
                visited[i] = false;//!!! very carefull about backtracking, return to previous state, should not return early 
                if(res || cursum == 0) return res; // if cursum == 0, we "must" select nums[i], return the result of select nums[i] directly
            }
        }            

        return false;
        
    }
};
