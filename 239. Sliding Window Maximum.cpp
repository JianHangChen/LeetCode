
//!!! sol2, using deque, O(n), O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++){
            if(!dq.empty() && i - k >= dq.front()) dq.pop_front();
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) res.push_back(nums[dq.front()]);            
        }
        return res;               
    }
};

// sol1, from gy1, using multiset, O(nlogk), O(k) not include res
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++){
            if(s.size() >= k){
                s.erase(s.find(nums[i-k]));
            }
            s.insert(nums[i]);
            if(s.size() == k){
                res.push_back(*s.rbegin());
            }
            
        }
        return res;
        
    }
};
