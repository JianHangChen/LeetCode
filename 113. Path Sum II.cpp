/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// !!! sol1, my recursively
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<vector<int>> res;
        if(!root) return res;
        
        vector<int> path = {};
        pathSum(root, sum, path, res);
        return res;
    }
    void pathSum(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& res){
        path.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == root->val){
                res.push_back(path);
            }
        }
        else{
            if(root->left){
                pathSum(root->left, sum - root->val, path, res);
            }
            if(root->right){
                pathSum(root->right, sum - root->val, path, res);
            }                
        }
        path.pop_back();
    }
};

// // sol2,  iteratively, from gy2
// class Solution{
// public:
//     vector<vector<int>> pathSum(TreeNode* root, int sum){
//         vector<vector<int>> res;
        
//         vector<TreeNode*> s;
//         if(!root) return res;
        
//         TreeNode* cur = root; int pre_sum = 0; TreeNode* pre;
        
//         while(cur || !s.empty()){
//             while(cur){
//                 s.push_back(cur);
//                 pre_sum += cur->val;
//                 cur = cur->left;
//             }
//             cur = s.back();
//             if(!cur->left && !cur->right){
//                 if(pre_sum == sum){
//                     vector<int> path;
//                     for(auto node:s){
//                         path.push_back(node->val);
//                     }
//                     res.push_back(path);
//                 }
//             }
            
//             if(cur->right && cur->right != pre){
//                 cur = cur->right;
//             }
//             else{
//                 pre = cur;
//                 s.pop_back();
//                 pre_sum -= cur->val;
//                 cur = NULL;
//             }   
//         }
//         return res;            
//     }   
    
// };

