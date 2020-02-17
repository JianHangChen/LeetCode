!!! // sol1, my, O(n), O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            int compliment = target - nums[i];
            if( m.count(compliment) > 0){
                return {m[compliment], i};
            }
            m[nums[i]] = i;
        }
        
        return {};
    }
};







class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        # sol1: myself O(n^2)
        # length = len(nums)
        # for i in range(length-1):
        #     for j in range(i + 1,length):
        #         if((nums[i] + nums[j]) == target):
        #             return [i,j]
        
        # sol3: !!!one-pass hash table
        # dic = {}
        # for i in range(len(nums)):
        #     compliment = target-nums[i]
        #     if ( compliment not in dic):        
        #         dic[nums[i]] = i
        #     else:
        #         return [dic[compliment],i]
            
        # sol3: using enumerate
        # dic = {}
        # for index, num in enumerate(nums):
        #     complement = target - num
        #     if complement in dic:
        #         return [dic[complement],index]
        #     else:
        #         dic[num] = index
        
        # sol4: sorted then sum by Xiaoyu 
        sorted_nums = sorted(nums)
        length = len(nums)
        low = 0
        high = length - 1
        while low < high:
            sum = sorted_nums[low] + sorted_nums[high]
            if sum < target:
                low += 1
            elif sum > target:
                high -= 1
            else:
                if sorted_nums[low] == sorted_nums[high]:
                    l = nums.index(sorted_nums[low])
                    h = nums[(l+1):].index(sorted_nums[high])+ (l+1)
                else:
                    l = nums.index(sorted_nums[low])
                    h = nums.index(sorted_nums[high])                 
                return [l,h]
