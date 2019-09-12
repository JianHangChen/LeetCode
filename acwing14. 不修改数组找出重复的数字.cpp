//sol2, cycle detection O(1), O(1)
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int slow = 0, fast = 0;
        
        while(true){
            slow = nums[slow];
            fast = nums[fast]; fast = nums[fast];
            
            if(slow == fast) break;
        }
        
        fast = 0;
        
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast]; 
        }
        return slow;
        
    }
};

//sol1, hash O(1), O(n)
// class Solution {
// public:
//     int duplicateInArray(vector<int>& nums) {
//         unordered_set<int> m;
//         for(auto num:nums){
//             if(m.count(num) > 0) return num;
//             m.insert(num);
//         }
//         return -1;
//     }
// };
