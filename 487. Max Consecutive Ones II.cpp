// !!! sol1, my, two pointer, O(n), O(1)
// [1,0,1,1,0,1]
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        // count [i, j] total zeros count
        int res = 0;
        int count = 0, j = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0) count++;
            while(count > 1){
                if(nums[j++] == 0) count--;
            }
            res = max(res, i - j + 1);
        }
        
        return res;
    }
};

// !!! followup , data stream, from gy
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        queue<int> q;
        int j = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                q.push(i);
            }
            if(q.size() > 1){
                j = q.front() + 1; q.pop();
            }
            res = max(res, i - j+1);
        }
        return res;
    }
};
