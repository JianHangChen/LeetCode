
// !!! sol2, from gy2, O(n), O(1)
// 1 2 3 4 5 6 7 8
// 1 3 2 5 4 7 6 8
// 3 5 2 1 6 4
// 3 5 1 6 2 4

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++){
            if(i%2 == 1){
                if(nums[i-1] > nums[i]) swap(nums[i-1], nums[i]);
            }
            else{
                if(nums[i-1] < nums[i]) swap(nums[i-1], nums[i]);
            }
            
        }
        
    }
};


// sol1, my, sort, O(nlogn), O(1)
// 1 2 3 4 5 6 7 8
// 1 3 2 5 4 7 6 8
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for(int i = 1; i + 1 < nums.size(); i += 2){
//             swap(nums[i], nums[i+1]);
//         }
//     }
// };
