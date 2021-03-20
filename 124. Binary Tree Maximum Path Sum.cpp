/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxPath2Root(root);
        return maxSum;
    }
    
    int maxPath2Root(TreeNode* root){
        if(!root) return 0;
        int leftVal = max(0, maxPath2Root(root->left));
        int rightVal = max(0, maxPath2Root(root->right));
        
        maxSum = max(maxSum, 
                     root->val + leftVal + rightVal);
        
        int maxVal = max(leftVal, rightVal);
        return root->val + maxVal;        
    }
    
};
