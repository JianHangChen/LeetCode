// sol2, from gy, using unordered_set, O(n* 2^n), faster for insert
class Solution{
public:
    vector<vector<int>> findSubsequences(vector<int>& nums){
        vector<vector<int>> res;
        vector<int> out;
        helpler(nums, 0, out, res);
        return res;
    }
    void helpler(vector<int>& nums, int start, vector<int>& out, vector<vector<int>>& res){
        if(out.size() > 1) res.push_back(out);
        unordered_set<int> visit;
        for(int i = start; i < nums.size(); i++){
            if(visit.count(nums[i]) > 0) continue;
            visit.insert(nums[i]);
            
            if(out.empty() || out.back() <= nums[i]){
                out.push_back(nums[i]);
                helpler(nums, i + 1, out, res);
                out.pop_back();
            }
        }
        
    }
};


// sol1, from gy, using set, O(n* 2^n)
// class Solution {
// public:
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         unordered_set<vector<int>> res;
//         vector<int> out;
//         helpler(nums, 0, out, res);
        
//         return vector<vector<int>> (res.begin(), res.end());
//     }  
//     void helpler(vector<int>& nums, int start, vector<int>& out, set<vector<int>>& res){
//         if(out.size() >= 2) res.insert(out);
//         for(int i = start; i < nums.size(); i++){
//             if(out.size() > 0 && nums[i] >= out.back() || out.size()==0){
//                 out.push_back(nums[i]);
//                 helpler(nums, i+1, out, res);
//                 out.pop_back();                
//             }   
//         }
//     }
// };
