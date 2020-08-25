// !!! sol2, O(1) build, O(n) for pickup
// reservoir sampling
// from gy,  but use vector *_nums = nums to save space;
// a better story is a large file stream: https://leetcode.com/problems/random-pick-index/discuss/88071/C%2B%2B_Time%3A-O(n)-Space%3A-O(n)_116ms_96.41_with-clear-explanation-by-probability

//https://www.youtube.com/watch?v=A1iwzSew5QY
class Solution {
public:
    vector<int>* v;
    Solution(vector<int>& nums){
        v = &nums; // or use vector<int> v = move(nums) here to save space???
    }
    int pick(int target){
        int res = -1, cnt = 0;
        for(int i = 0; i < (*v).size(); i++){
            if(target == (*v)[i]){ 
                cnt++;
                if(rand() % cnt == 0) res = i;
            }
        }
        return res;
    }
    
};



// my, sol1, hash map, the problem is not well stated, it is mainly about input a stream without knowing the length, and return a pick(target) online 
// class Solution {
// public:
//     unordered_map<int, vector<int>> m;
        
//     Solution(vector<int>& nums) {
//         for(int i = 0; i < nums.size(); i++){
//             m[nums[i]].push_back(i);
//         }
//     }
    
//     int pick(int target) {
//         int n = m[target].size();
//         return m[target][rand() % n];        
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
