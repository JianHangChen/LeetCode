// !!!!! sol4, 
// 2^n, 2^n
// https://www.youtube.com/watch?v=T909rebQJ70
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> cur = {};
        sort(nums.begin(), nums.end());
        dfs(nums, cur, 0, res);
        return res;
    } 
    void dfs(vector<int>& nums, vector<int>& cur, int start, vector<vector<int>>& res){
        if(start == nums.size()){
            res.push_back(cur);
            return;
        }
        
        cur.push_back(nums[start]);
        dfs(nums, cur, start+1, res); // add start to cur
        cur.pop_back();
        
        while(start+1 < nums.size() && nums[start+1] == nums[start]) start++;// remove duplicate
        dfs(nums, cur, start+1, res); // not add start to cur
        
    }
};

// // sol2, iteratively, from gy2, O(n* 2^n), O(2^n)
class Solution{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = {{}};
        if(nums.empty()) return res;
        
        int last = nums[0], start = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != last){
                last = nums[i];
                start = 0; 
            }            
            
            int n = res.size();
            while(start < n){
                res.push_back(res[start]);
                res.back().push_back(nums[i]);
                start++;
            }            
        }
        return res;
    }
};


// !!!!! sol1.1 my dfs, the same as gy2, O(n*2^n), O(2^n), n is the copy of a vector v
class Solution {
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<vector<int>> res = {};
        vector<int> v;
        sort(nums.begin(), nums.end());
        helpler(0, nums, res, v);
        return res;
    }
    void helpler(int level, vector<int>& nums,  vector<vector<int>>& res, vector<int>& v){
        
        res.push_back(v);
        for(int i = level; i < nums.size(); i++){
            if( (i > level) && nums[i] == nums[i - 1]) continue;
            v.push_back(nums[i]);
            helpler(i + 1, nums, res, v);      
            v.pop_back();
        }
    }

};

// sol1, my dfs
// class Solution {
// public:
    
//     vector<vector<int>> subsetsWithDup(vector<int>& nums){
//         vector<vector<int>> res = {{}};
//         vector<int> v;
//         sort(nums.begin(), nums.end());
//         helpler(-1, nums, res, v);
//         return res;
//     }
//     void helpler(int level, vector<int>& nums,  vector<vector<int>>& res, vector<int>& v){
//         if(level == nums.size()) return;
//         if(level != -1){
//             v.push_back(nums[level]);
//             res.push_back(v);       
//         }
//         for(int i = level + 1; i < nums.size(); i++){
//             int j = i - 1;
//             while(j > level){
//                 if(nums[j] == nums[i]) break;
//                 j--;
//             }
//             if(j != level) continue;            
//             helpler(i, nums, res, v);      
//         }
//         if(level != -1) v.pop_back();
//     }

// };
