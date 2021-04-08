// !!!!!! sol4, use visited to remember the visited place
// https://www.youtube.com/watch?v=T909rebQJ70
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<bool> visited(n, false);
        vector<int> cur;
        dfs(res, nums, cur, visited);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, vector<bool>& visited){
        if(cur.size() == nums.size()){
            res.push_back(cur);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] || i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            visited[i] = true;
            cur.push_back(nums[i]);
            dfs(res, nums, cur, visited);
            cur.pop_back();
            visited[i] = false;
        }
    }
};




// !!! sol2, insert,O(sum[n*(n-1)!]) bigger than O(n!) smaller than O(n*n!), space O(n!)
// the same as python iteratively sol1
class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        int n = nums.size(); if(n == 0) return {};
        vector<vector<int>> res = {{}}, temp;
        for(int i = 0; i < n ; i++){
            for(auto& ele:res){
                int l = ele.size();
                for(int j = l; j >= 0; j--){
                    vector<int> v = ele;
                    if(j < l && nums[i] == ele[j]) break;
                    v.insert(v.begin() + j, nums[i]);
                    temp.push_back(v);
                }
            }
            res = temp; temp.clear();
        }
        return res;        
    }
};


// //!!! sol3, from gy4
// sum(O(n-1)!),   O(n!) 

// in position level, we only backtrack each unique number once.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(res, nums, 0);
        return res;
    }
    void backtrack(vector<vector<int>>& res, vector<int>& nums, int level){
        if( level == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = level; i < nums.size(); i++){
            int j = i - 1;
            while(j >= level){
                if(nums[j] == nums[i]) break;
                j--;
            }
            if(j != level - 1) continue;
            swap(nums[i], nums[level]);
            backtrack(res, nums, level + 1);
            swap(nums[i], nums[level]);
        }
    }

};


// // my sol1, use set is not good, more than sum(O((n-1)!) , but O(n!) extra space
// class Solution {
// public:
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         int n = nums.size();
        
//         set<vector<int>> s;
//         back_track(nums, s, 0);
//         vector<vector<int>> res;
//         for(auto& ele:s) res.push_back(ele);
//         return res;
//     }
    
//     void back_track(vector<int>& nums, set<vector<int>>& s, int level){
//         if(level == nums.size()){
//             s.insert(nums);
//             return;
//         }
//         for(int i = level; i < nums.size(); i++){
//             swap(nums[i], nums[level]);
//             back_track(nums, s, level+1);
//             swap(nums[i], nums[level]);
//         }
        
//     }
// };
                                                  
# sol1: iteratively
def permuteUnique(self, nums: List[int]) -> List[List[int]]:
    ans = [[]]
    for num in nums:
        new_ans = []
        for item in ans:
            for i in range(len(item), -1, -1):
                new_ans.append(item[:i] + [num] + item[i:])
                if i > 0 and num == item[i-1]: break
        ans = new_ans

    return ans

# sol2, dfs
# test nums=[], nums = None
def permuteUnique(self, nums: List[int]) -> List[List[int]]:
    ans = []

    def dfs(nums, item):
        if nums == []:
            ans.append(item)
        else:
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                dfs(nums[:i]+nums[i+1:],item + [nums[i]])
    if nums:
        dfs(sorted(nums),[])
    return ans
