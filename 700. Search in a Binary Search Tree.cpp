/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// !!! sol2, iterative, O(n), O(1)
class Solution{
public:
    TreeNode* searchBST(TreeNode* root, int val){
      while(root != NULL){
        if(root->val == val) return root;
        if(root->val > val){
          root = root->left;
        }
        else{
          root = root->right;
        } 
      } 
      return root;                
    }
};
// sol1, my, recursion O(H), O(H)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val){
          return root;
        }
        if(root->val > val){
          return searchBST(root->left, val);
        }
        else{
          return searchBST(root->right, val);
        }
    }
};
