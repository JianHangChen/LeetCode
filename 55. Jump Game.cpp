
// !!! sol3, greedy, from gy2 and sol4


class Solution{
public:
    bool canJump(vector<int>& nums){
        int n = nums.size();
        int reach = 0;
        for(int i = 0; i < n; i++){
            
            if(i > reach) return false;            
            reach = max(reach, i + nums[i]);
            
        }
        return true;
        
        
    }
};


//!! sol2, dp, from gy1, O(n), O(n)
dp[i] is the remaining jumping force in i position after iterating previous elements from [0, i-1]

class Solution{
public:
    bool canJump(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++){
            dp[i] = max(nums[i-1], dp[i-1]) - 1;
            if(dp[i] < 0) return false;
        }
        return true;        
    }
};





sol4, memo, bottom up, from sol3, tle, O(n^2), O(n)


class Solution {

public:
    unordered_map<int, bool> m;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        m[n-1] = true;
        
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j <= min(i + nums[i], n - 1); j++){
                if(m[j]){
                    m[i] = true;
                    break;
                }
            }
        }
        
        return m[0];
        
        
    }
};


sol3,my recursively with memo, dfs, same as sol2, tle O(n^2), O(n)

class Solution {

public:
    unordered_map<int, bool> m;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        return canJump(nums, 0);
    }
    
    bool canJump(vector<int>& nums, int idx){
        if(m.count(idx) > 0) return m[idx];
            
        if(idx >= nums.size() - 1 || idx + nums[idx] >= nums.size() - 1 ){
            return true;
        }
        if(nums[idx] == 0){
            m[idx] = false;
            return false;
        }
        for(int i = idx + nums[idx]; i > idx ; i--){
            if( canJump(nums, i)){
                m[idx] = true;
                return true;
            }
        }
        m[idx] = false;
        return false;
    }
};


// sol1,my recursively, dfs, tle, O(2^(n-2)), O(n)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return canJump(nums, 0);
    }
    
    bool canJump(vector<int>& nums, int idx){
        if(idx >= nums.size() - 1 ) return true;
        if(nums[idx] == 0) return false;
        
        for(int i = idx + nums[idx]; i > idx ; i--){
            if( canJump(nums, i)){
                return true;
            }
        }
        return false;
    }
};
