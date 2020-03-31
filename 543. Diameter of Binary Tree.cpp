/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

*/

//!!!! sol2, from sol1, O(n), O(n), only use one recursion
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int res = 0;
        
        maxDepth(root, res);        
        return res;
    }
    
    
    int maxDepth(TreeNode* root, int& res){
        if(!root) return 0;
        
        int leftDepth = maxDepth(root->left, res), rightDepth = maxDepth(root->right, res);
        
        res = max(res, leftDepth + rightDepth);
        
        return max(leftDepth, rightDepth) + 1;
    }
};

// my sol1, from gy1, O(n), O(n), but use recursion twice.
// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         if(!root) return 0;
//         int res = 0;
        
//         res = max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
//         return max(res, maxDepth(root->left) + maxDepth(root->right));
//     }
//     int maxDepth(TreeNode* root){
//         if(!root) return 0;
//         return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//     }
// };
