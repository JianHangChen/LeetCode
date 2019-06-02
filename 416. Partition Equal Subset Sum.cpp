    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        
        for(auto num:nums){
            s += num;
        }
        
        if(s & 1 != 0){
            return false;
        }
        int half = s / 2;
        
        
        vector<bool> dp(half+1, false);
        
        dp[0] = true;
        
        for(auto num : nums){
            for(int j = half; j > 0; j--){
                if(j >= num){
                    dp[j] = dp[j] || dp[j - num];
                }
            }
            
        }
        
        return dp[half];  
    }
