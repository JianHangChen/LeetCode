// sol2, two pointer, O(n), O(1)
// https://leetcode.com/problems/maximum-score-of-a-good-subarray/discuss/1108333/JavaC%2B%2BPython-Two-Pointers
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i = k, j = k, n = nums.size();
        int res = nums[k], curmin = nums[k];
        while(i >= 0 && j < n ){
            curmin = min(curmin, min(nums[i], nums[j]));
            res = max(res, curmin * (j - i + 1));
            if(i == 0 || j + 1 < n && nums[i-1] <= nums[j+1]){
                j++;
            }
            else i--;
        }
        return res;
    }
};


// sol1, my, O(n), O(n)
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        nums.push_back(0);
        int n = nums.size();
        cout << n <<endl;
        stack<int> st;
        int right = 0, res = 0;
        while(right < n){
            if(st.empty() || nums[st.top()] < nums[right]){
                st.push(right++);
            }
            else{
                int left = -1, cur = st.top(); st.pop();
                int h = nums[cur];
                if(!st.empty()) left = st.top();
                if(left < k &&  k < right){ // left is the left most position LOWER than h, so left + 1 = i  
                    res = max(res, h * (right - left - 1));
                }
            }
        }
        return res;
    }
};
