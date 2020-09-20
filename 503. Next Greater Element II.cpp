
//!! 1.1, monotonic stack from gy2, O(n), O(n)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;
        for(int i = 0; i < 2 * n; i++){
            while(!s.empty() && nums[s.top()] < nums[i % n]){
                res[s.top()] = nums[i % n]; s.pop();
            }
            if(i < n) s.push(i);            
        }
        
        return res;
    }
};

// my sol1, using monotonic stack, O(n), O(n)
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res(n), arr = nums;
//         for(int i = 0; i < n; i++) arr.push_back(nums[i]);
//         stack<int> s;
//         vector<int> temp(2 * n, -1);
//         for(int i = 0; i < arr.size(); i++){
//             if(s.empty() || arr[s.top()] >= arr[i]){
//                 s.push(i);
//             }
//             else{
//                 temp[s.top()] = i;
//                 s.pop();
//                 i--;
//             }
//         }
        
//         for(int i = 0; i < n; i++){
//             if(temp[i] == -1) res[i] = -1;
//             else res[i] = arr[temp[i]];
//         }
//         return res;
//     }
// };
