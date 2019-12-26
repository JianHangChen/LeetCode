/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// !!! sol2, iteratively dfs, O(N), O(H)
//   10
// 5     15
//3 7  null 18
// L 7  R 15
class Solution{
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root || L > R) return 0;
        int res = 0;
        stack<TreeNode*> s({root});
        while(!s.empty()){
            TreeNode* cur = s.top(); s.pop();
            if(cur == NULL) continue;
            if(L <= cur->val && cur->val <= R){
                res += cur->val;
                s.push(cur->left);
                s.push(cur->right);
            }
            else if(R < cur->val){
                s.push(cur->left);
            }
            else{
                s.push(cur->right);
            }
        }
        
        return res;
    
    }
};


//! sol1, my dfs, O(N), O(H)

//          10
//      5        15
//  3      7    13   18
//1 null  6  
class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        int res = 0;
        if(!root || L > R) return 0;
        if(L <= root->val && root->val <= R){
            res += root->val;
            res += rangeSumBST(root->left, L, R);
            res += rangeSumBST(root->right, L, R);            
        }
        else if(root->val < L){
            res += rangeSumBST(root->right, L, R);
        }
        else{ // R < root->val
            res += rangeSumBST(root->left, L, R);
        }
        
        return res;
    }
};
