// !! sol1.1, two pointer from sol O(n), O(n)
// same as sol1, but better one pass from two sides to middle
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1;
        for(int i = n - 1; i >= 0; i--){
            int sqrl = nums[l] * nums[l];
            int sqrr = nums[r] * nums[r];
            if(sqrl > sqrr){
                res[i] = sqrl;
                l++;
            }
            else{
                res[i] = sqrr;
                r--;
            }
        }
        return res;
        
    }
};

//  [-4,-1,0,3,10]
// sol1, my O(n), O(n)
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> res;
//         int i = 0, j = 0;
//         while(i < n){ // i-> first number >= 0
//             if(nums[i] >= 0) break; 
//             i++;
//         }
//         j = i; i--;        
//         while(j < n || i >= 0){
//             if(i < 0){
//                 res.push_back(nums[j] * nums[j]);
//                 j++;
//             }
//             else if(j == n){
//                 res.push_back(nums[i] * nums[i]);
//                 i--;
//             }
//             else{
//                 int sqri = nums[i] * nums[i];
//                 int sqrj = nums[j] * nums[j];
//                 if(sqri > sqrj){
//                     res.push_back(sqrj);
//                     j++;
//                 }
//                 else{
//                     res.push_back(sqri);
//                     i--;
//                 }
//             }
//         }
//         return res;
        
//     }
// };
