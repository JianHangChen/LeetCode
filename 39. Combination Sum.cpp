
// my sol1, same as gy1, O(N^target), O(target)
class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;    
        
        helpler(candidates, target, combination, 0);
        return res;
        
    }
    
    void helpler(vector<int>& candidates, int target, vector<int>& combination,int start){
        if(target < 0) return;
        if(target == 0){
            res.push_back(combination);
            return;
        }
        
        //target!=0
        for(int i = start; i < candidates.size(); i++){
            combination.push_back(candidates[i]);
            helpler(candidates, target - candidates[i], combination, i);
            combination.pop_back();
        }
        return;
    }
    
    
};
