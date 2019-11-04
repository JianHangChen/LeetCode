// !!! sol2, from gy3, a nice solution using the relationship of num[cur] and num[overwrite - 1]

class Solution{
    public:
    int removeDuplicates(vector<int>& nums){
        int i = 0;
        for(auto num:nums){
            if(i == 0 || num > nums[i-1]){
                nums[i++] = num;
            }
        }
        return i;
    }
};

// sol1, my two pointer
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int i = 0, j = 0, n = nums.size();
//         if(n < 1) return 0;
        
//         while(j < n){
//             if(nums[i] != nums[j]) nums[++i] = nums[j];
            
//             j++;
//         }
//         return i+1;
//     }
// };
