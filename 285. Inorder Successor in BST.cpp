// !!!!! sol2, from gy s3, O(h), O(1), no need for stack
class Solution{
public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* res = NULL;
    while(root){
      if(p-> val >= root->val){
        root = root->right;
      }
      else{
        res = root;
        root = root->left;
      }
    }
    return res;
  }
};
