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
