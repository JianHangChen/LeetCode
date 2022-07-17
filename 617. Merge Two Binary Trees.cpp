class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return NULL;
        int val1 = 0, val2 = 0;
        TreeNode* left1 = NULL, *right1 = NULL, *left2 = NULL, *right2 = NULL;
        if(root1){
            val1 = root1->val;
            left1 = root1->left;
            right1 = root1->right;
        }
        if(root2){
            val2 = root2->val;
            left2 = root2->left;
            right2 = root2->right;
        }
        TreeNode* root3 = new TreeNode(val1 + val2);
        root3->left = mergeTrees(left1, left2);
        root3->right = mergeTrees(right1, right2);
        return root3;
        
    }
};
