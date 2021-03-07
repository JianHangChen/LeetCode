//!!! sol2, deque O(n), O(n)

// [8,2,4,7], limit = 4
// 8
// 8
// 2
// 2
//maxdq 4
//mindq 2 4
// maxdq 7
// mindq 4 7
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        deque<int> dqmax; // mono decreasing
        deque<int> dqmin;// mono increase
        int res = 0;
        int i = 0, j = 0;
        while(j < n){
            while(!dqmax.empty() && nums[dqmax.back()] <= nums[j]) {
                dqmax.pop_back();
            }
            dqmax.push_back(j);
            while(!dqmin.empty() && nums[dqmin.back()] >= nums[j]){
                dqmin.pop_back();
            }
            dqmin.push_back(j);
            while(nums[dqmax.front()] - nums[dqmin.front()] > limit){
                if(dqmax.front() == i) dqmax.pop_front();
                if(dqmin.front() == i) dqmin.pop_front();
                i++;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};


// sol1, my, O(nlogn), O(n)
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        int res = 0;
        int i = 0, j = 0;
        multiset<int> s;
        while(i < n){
            s.insert(nums[i]);
            while(*s.rbegin() - *s.begin() > limit){
                s.erase(s.find(nums[j++]));
            }
            res = max(res, int(s.size()));
            i++;
        }
        
       return res;
    }
};
