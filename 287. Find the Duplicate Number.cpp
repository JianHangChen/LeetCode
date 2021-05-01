
// !!!!!  sol4, cycle detection, O(n), O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0], f = nums[0];
        
        // cycle detection // use number as indicator
        while(true){
            s = nums[s]; 
            f = nums[nums[f]];
            if(s == f) break;
        }
        // find intersection point
        s = nums[0];
        while(s != f){
            s = nums[s];
            f = nums[f];
        }
        return s;        
    }
    
    
};


//! sol6, my, O(n), O(1)
// inplace
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        while(true){
            if(nums[0] == nums[nums[0]]) return nums[0];
            swap(nums[0], nums[nums[0]]);
        }
        return -1;
    }
};


//sol5, bit manipulation, O(n), O(1)
class Solution{
public:
    int findDuplicate(vector<int> & nums){
        int res = 0;
        
        for(int i = 0; i < 32; i++){
            int bit = 1 << i;
            int cnt1 = 0, cnt2 = 0;
            for(int i = 0; i < nums.size(); i++){
                if( ( bit & i ) > 0) cnt1++; //carefull about order of bit manipulation
                if( ( bit & nums[i]) > 0 ) cnt2++;
            }
            if(cnt2 > cnt1) res += bit;
        }
        return res;
        
    }
};

sol3, from sol2, hash, O(N), O(N)
class Solution{
public:
    int findDuplicate(vector<int> & nums){
        unordered_set<int> s;
        for(auto num:nums){
            if(s.count(num) > 0) return num;
            s.insert(num);
        }
        return -1;
        
    }
};



sol2, my sort, not support, O(nlogn), O(n)

class Solution {
public:
    int findDuplicate(vector<int>& nums){
        sort(nums.begin(), nums.end() ); //!!!!
        for(int i = 0; i < nums.size()-1; i++){
            if(nums[i] == nums[i+1]) return nums[i];
        }
        return -1;
    }
};

sol1, my brute force, O(n^2), O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[i] == nums[j]) return nums[i];
            }
        }
        return -1;
    }
};
