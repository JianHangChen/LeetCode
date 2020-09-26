// !!! sol2.1, from sol4, O(n), O(n), the same as sol2, but less code, calculate presum online
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int res = 0, presum = 0;
        // [i:j] j is not included
        for(int j = 0; j < n; j++){
            presum += nums[j];
            res += m[presum - k];
            m[presum]++;
        }
        return res;
    }
};


//!! my, sol2, O(n), O(n)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n+1, 0);
        unordered_map<int, int> m;
        m[presum[0]]++;
        for(int i = 1; i <= n; i++){
            presum[i] = presum[i-1] + nums[i-1];
            m[presum[i]]++;
        }
        
        int res = 0;
        // [i:j] j is not included
        for(int i = 0; i < n; i++){
            // dp[k+presum[i]], how many number j after i has presum[j] = presum[i]+k, if(abs(presum[i]+k) > 1000) of course it is 0;            
            m[presum[i]]--;
            if(m.count(k + presum[i]) > 0 && m[k+presum[i]] > 0){
                
                res += m[k+presum[i]];
            }
        }
        return res;
    }
};

my,  sol1, O(n^2), O(n), TLE
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n+1, 0);
        for(int i = 1; i <= n; i++){
            presum[i] = presum[i-1] + nums[i-1];
        }
        int res = 0;
        // [i:j] j is not included
        for(int i = 0; i < n; i++){
            for(int j = i+1; j <= n; j++){
                if(presum[j] - presum[i] == k) res++;
            }
        }
        return res;
    }
};
