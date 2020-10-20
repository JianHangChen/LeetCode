// sol2, inplace, O(nlogn), O(1)
class Solution {
public:

    int twoSum6(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int l = 0, r = nums.size() - 1;
        
        while(l < r){
            if(nums[l] + nums[r] == target){
                res++; l++; r--;
                while(l < r && nums[l] == nums[l - 1]) l++;
                while(l < r && nums[r] == nums[r+1]) r--;
            }
            else if(nums[l] + nums[r] < target){
                l++;
            }c
            else{
                r--;
            }
        }
        
        return res;
    }
};

// sol1, my, O(n), O(n)
class Solution {
public:

    int twoSum6(vector<int> &nums, int target) {
        int res = 0;
        unordered_set<int> s, visited;
        for(int i = 0; i < nums.size(); i++){
            if(visited.count(nums[i]) > 0) continue;

            if(s.count(target - nums[i]) > 0){
                res++;
                visited.insert(nums[i]);
            }
            else{
                s.insert(nums[i]);
            }
        }
        return res;
    }
};
