// !! sol2, from   gy, easier implementation
class Solution{
public:
    vector<string> summaryRanges(vector<int>& nums){
        vector<string> res;
        int i = 0, j = 0, n = nums.size();

        while(i < n){
            if( i == n - 1 || nums[i] + 1 != nums[i+1]){ // from j to i
                string s;
                if(j < i){
                    s += to_string(nums[j]) + "->";
                }
                s += to_string(nums[i]);
                res.push_back(s);
                j = i + 1;
            }
            i++;
        }
        return res;
    }
};

// sol1, my
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(n < 1) return res;  // !!! corner case
        int j = 0;
        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1] + 1){
                string s;
                if(j < i - 1){
                    s += to_string(nums[j]) + "->";
                }
                s += to_string(nums[i - 1]);
                res.push_back(s);
                j = i;
            }
        }

        string s;
        if(j < n - 1){
            s += to_string(nums[j]) + "->";
        }
        s += to_string(nums[n - 1]);
        res.push_back(s);
        return res;
    }
};
