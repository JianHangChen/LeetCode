

// so1, my, (2^n), O(2^n)
// same as gy2
class Solution {
public:
    unordered_map<int, vector<TreeNode*>> memo; 
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> res;
        if(memo.count(n) > 0) return memo[n];
        
        if(n % 2 == 0){
            return memo[n] = {};
        }
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return memo[n] = {root}; 
        }
        
        for(int leftCount = 1; leftCount < n - 1; leftCount += 2){ // !!! skip even number
            vector<TreeNode*> left = allPossibleFBT(leftCount);
            vector<TreeNode*> right = allPossibleFBT(n - 1 - leftCount);
            
            for(auto lroot:left){
                for(auto rroot:right){
                    TreeNode* cur = new TreeNode(0);
                    cur->left = lroot;
                    cur->right = rroot;
                    res.push_back(cur);
                }
            }
        }
        
        return res;
    }
};


// n = 4
//     0
//    /\
//   0  
//   /\
//  0  0 

//     0
//    /\
//      0  
//      /\
//     0  0 
// left = {00}
// right {}
