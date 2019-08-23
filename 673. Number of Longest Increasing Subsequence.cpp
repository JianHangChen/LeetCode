
// sol2!!!!, binary search twice + dp
// O(nlogn), O(n) 
//https://leetcode.com/problems/number-of-longest-increasing-subsequence/discuss/107295/9ms-C%2B%2B-Explanation%3A-DP-%2B-Binary-search-%2B-prefix-sums-O(NlogN)-time-O(N)-space
//solution https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
//complexity https://www.geeksforgeeks.org/lis-using-segment-tree/


class Solution {
public:    
    
    int findNumberOfLIS(vector<int>& nums) {
    	int n = nums.size(); 
    	if( n < 1) return 0;
        vector<vector<pair<int,int>>> dp(n+1);
        
        int max_length = 0, mid;
    	for(int i = 0; i < n; i++){
    		int l = 0, r = max_length;
    		while(l < r){
    			mid = l + (r - l) / 2;
    			if(dp[mid].back().first < nums[i]){
    				l = mid + 1;
    			}
    			else{
    				r = mid;
    			}
    		}

    		int count = 1;
    		int pre = l - 1;
    		if(pre >= 0){
    			int l1 = 0, r1 = dp[pre].size();

    			while(l1 < r1){
    				mid = l1 + (r1 - l1) / 2;
    				if(dp[pre][mid].first < nums[i]){
    					r1  = mid;
    				}
    				else{
    					l1 = mid + 1;
    				}
    			}
    			count = dp[pre].back().second;
    			if(l1 > 0){
	    			count -= dp[pre][l1 - 1].second;
    			}
    		}
			if(!dp[l].empty()) count += dp[l].back().second;

			dp[l].push_back({nums[i],count});

    		if(l == max_length){
    			max_length++;
    		}

    	}
    	return dp[max_length-1].back().second;
    }
};







// sol 1, dp O(n^2), O(n), from gy
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max_len = 1, res = 1;
        if(n < 2) return n;
        vector<int> longest(n,1), lnumber(n,1);
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j]){
                    if(longest[i] < longest[j] + 1){
                        longest[i] = longest[j]+1;
                        lnumber[i] = lnumber[j];
                    }
                    else if(longest[i] == longest[j]+1){
                        lnumber[i] += lnumber[j];
                    }
                }
            }
            if(max_len < longest[i]){
                max_len = longest[i];
                res = lnumber[i];
            }
            else if(max_len == longest[i]){
                res += lnumber[i];
            }
        }
        return res;
    }
};
