//!!! sol2, O(n), O(n)
// https://www.youtube.com/watch?v=P6RZZMu_maU
// hashset
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num:nums){
            s.insert(num);
        }
        int res = 0;
        for(int num:nums){
            if(s.count(num - 1) > 0) continue;
            int cur = 0;
            while(s.count(num) > 0){
                cur++;
                num++;
            }
            res = max(res, cur);
        }
        return res;
    }
};

// sol1, my, sort, O(nlogn), O(1)
// 1234445678
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cur = 0, res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] + 1){
                cur++;
            }
            else if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
        
            else{
                cur= 1;
            }
            res=max(cur, res);
        }
        return res;
    }
};
