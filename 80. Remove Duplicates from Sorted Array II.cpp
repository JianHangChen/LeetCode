// !!! sol2, from gy3, use the relationship between nums[i-2] and num[cur], similar to 26.remove duplicates I
class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int i = 0;
        for(auto num:nums){
            if(i <= 1 || num > nums[i-2]){
                nums[i++] = num;
            }
        }
        return i;
    }    
};

// // sol1, my two pointer
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 0) return 0; // careful
//         int i = 0, j = 0, count = 0;
        
//         while(j < n){
//             if(nums[i] == nums[j]){
//                 if(count == 1){
//                     nums[++i] = nums[j++];
//                 }
//                 else{
//                     j++;
//                 }
//                 count++;
//             }
//             else{
//                 count = 1;
//                 nums[++i] = nums[j++];
//             }            
//         }
//         return i + 1;
//     }
// };
