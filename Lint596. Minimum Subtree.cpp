// sol1, my, O(n), O(h)
class Solution {
public:
    TreeNode* res;
    int minimum = INT_MAX;

    TreeNode * findSubtree(TreeNode * root) {
        if(!root) return root;
        subtreesum(root);
        return res;
    }
    
    int subtreesum(TreeNode* root){
        if(!root) return 0;
        int s = root->val + subtreesum(root->left)+subtreesum(root->right);
        if(s < minimum){
            res = root;
            minimum = s;
        }
        return s;
    }
    
};
