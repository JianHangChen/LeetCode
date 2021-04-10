
!!! sol1, O(n), O(1)
 [1,1,1,0,0,0,1,1,1,1,0], k = 2
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        // count of zeros between [i,j]
        int count = 0;
        for(int i = 0, j = 0; j < n; j++){
            if(nums[j] == 0) count++;
            while(count > k){
                if(nums[i] == 0) count--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;
    }
};

// followup, data stream
// sol2, O(n), O(k)
//  [1,1,1,0,0,0,1,1,1,1,0], k = 2
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int count = 0, res = 0;
        queue<int> q;
        for(int num:nums){
            if(num == 0){
                count++;
                q.push(j);
            }
            while(count > k){
                count--;
                i = q.front() + 1; q.pop();
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
