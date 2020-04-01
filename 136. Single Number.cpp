//!!! sol2, my, bit manipulation, O(n), O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto num:nums){
            res ^= num;
        }
        return res;
    }
};

sol1, naive hash, my, O(n), O(n)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(auto num:nums){
            m[num]++;
        }
        
        for(auto& ele:m){
            if(ele.second == 1) return ele.first;
        }
        return -1;
    }
};


class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # sol1: brute force, fail

#         l = len(nums)
#         a = 0
#         b = 1
#         def swap(i, j, nums):
#             nums[i], nums[j] = nums[j], nums[i]
            
#         while b < l:
#             if nums[a] == nums[b]:
#                 a += 1
#                 swap(b, l-1, nums)
#                 b = a + 1
#                 l -= 1
#             else:
#                 b += 1
#         return nums[a]

        # sol2: from answer, but bad
        # time O(n^2) brute force, and O(n) space
        # no_duplicate_list = []
        # for i in nums:
        #     if i not in no_duplicate_list:
        #         no_duplicate_list.append(i)
        #     else:
        #         no_duplicate_list.remove(i)
        # return no_duplicate_list.pop()
    
        # # sol3: hash table !!!!!!!!
        # hash_table = {}
        # for i in nums:
        #     if i not in hash_table.keys():
        #         hash_table[i] = 1
        #     else:
        #         hash_table.pop(i)
        # return hash_table.popitem()[0]

        # sol3.: hash table, from solution
        # time O(n)   space O(n)
        # hash_table = {}
        # for i in nums:
        #     try:
        #         hash_table.pop(i)
        #     except:
        #         hash_table[i] = 1
        # return hash_table.popitem()[0]
        
        # sol3.2: hash table, from solution discuss
        # time O(n)   space O(n)
        hash_table = set()
        for i in nums:
            try:
                hash_table.remove(i)
            except:
                hash_table.add(i)
        return hash_table.pop()        
    
        # sol4: Math, from sol !!! O(n), space O(n)
        
        # return 2 * sum(set(nums)) - sum(nums)
    
        # sol5: bitwise, O(n), space O(1)
        # result = 0
        # for i in nums:
        #     result = result^i
        # return result
