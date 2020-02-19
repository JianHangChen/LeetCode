//!!my O(n^3), O(n^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < n; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int k = j + 1, h = n - 1, s = target - nums[j] - nums[i];

                while(k < h){
                    if( nums[k] + nums[h] == s){
                        res.push_back({nums[i], nums[j], nums[k], nums[h]});
                        while(k < h && nums[k] == nums[k+1]) k++;
                        while(k < h && nums[h] == nums[h-1]) h--;
                        k++; h--;
                    }
                    else if(nums[k] + nums[h] > s){
                        h--;
                    }
                    else{
                        k++;
                    }

                }
            }
        }
        return res;
    }
};









// class Solution:
    
//     # sol1, https://leetcode.com/problems/4sum/discuss/8545/Python-140ms-beats-100-and-works-for-N-sum-(Ngreater2)
//     def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
//         def NSum(left, target, N, result, results):
//             if len(nums) < N or target < nums[left] * N or target > nums[-1] * N:
//                 return
            
//             if N == 2:
//                 right = len(nums) - 1
                
//                 while left < right:
//                     s = nums[left] + nums[right]
//                     if s == target:
//                         results.append(result + [nums[left], nums[right]])
//                         left += 1
//                         while left < right and nums[left] == nums[left - 1]:
//                             left += 1
//                     elif s > target:
//                         right -= 1
//                     else:
//                         left += 1
                
                
//             else:
//                 for i in range(left, len(nums) - N + 1):
//                     if i == left or (i > left and nums[i] != nums[i-1]):
//                         NSum(i+1, target - nums[i], N - 1, result + [nums[i]], results)
                
        
        
//         results = []
//         nums.sort()        
//         NSum(0, target, 4, [], results)
//         return results
