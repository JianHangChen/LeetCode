//!!!!!! sol4, O(2^n), O(2^n)
// https://www.youtube.com/watch?v=T909rebQJ70
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, 0, nums);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& cur, int start, vector<int>& nums){
        if(start == nums.size()){
            res.push_back(cur);
            return;
        }
        
            cur.push_back(nums[start]);
            dfs(res, cur, start+1, nums);
            cur.pop_back();

            dfs(res, cur, start+1, nums);
        
    }
};

// !!!!sol2, iteratively, the same as sol1 or gy1, O(n*2^n), O(2^n), n is the copy of a vector v

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> res = {{}};
        for(auto num:nums){
            int n = res.size();
            for(int i = 0; i <n; i++){
                vector<int> v = res[i];
                v.push_back(num);
                res.push_back(v);
            }
        }
        return res;
    }
};

// !!! sol1.1, dfs gy2, change from sol1 O(n*2^n), O(2^n), n is the copy of a vector v
class Solution {
public:    
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> res = {};
        vector<int> v;
        helpler(0, nums, res, v);
        return res;
    }
    void helpler(int level, vector<int>& nums,  vector<vector<int>>& res, vector<int>& v){
        res.push_back(v); 
        for(int i = level; i < nums.size(); i++){   
            v.push_back(nums[i]);
            helpler(i + 1, nums, res, v);
            v.pop_back();
        }
    }
};

// sol1, my,dfs similar to  gy2,  O(n*2^n), O(2^n), n is the copy of a vector v
// class Solution {
// public:
    
//     vector<vector<int>> subsets(vector<int>& nums){
//         vector<vector<int>> res = {{}};
//         vector<int> v;
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
//             helpler(i, nums, res, v);      
//         }
//         if(level != -1) v.pop_back();
//     }

// };
