//!!! my sol1, O(n), O(1), same as sol4
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long s = (n+1)*n/2;
        for(int num:nums) s -= num;
        return s;
    }
};



//!!!! sol2, from sol3, bit manipulation, O(n), O(1)
// https://leetcode.com/problems/missing-number/discuss/69791/4-Line-Simple-Java-Bit-Manipulate-Solution-with-Explaination
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res = n;
        for(int i = 0; i < n; i++){
            res ^= nums[i] ^ i;
        }
        return res;
    }
};
