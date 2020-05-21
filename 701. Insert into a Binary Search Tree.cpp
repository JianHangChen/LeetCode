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

// sol2, my, iterativley, O(logn), O(1)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* cur = root, *newNode = new TreeNode(val);
        while(cur){
            if(val < cur->val){
                if(cur->left) cur = cur->left;
                else{
                    cur->left = newNode;
                    return root;
                }
            }
            else{
                if(cur->right) cur = cur->right;
                else{
                    cur->right = newNode;
                    return root;
                }
            }
        }
        return newNode;
    }
};
// so1, my, recursivley, O(logn), O(logn)
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root){
            if(val < root->val){
                root->left = insertIntoBST(root->left, val);
            }
            else{
                root->right = insertIntoBST(root->right, val);
            }
        }
        else{
            return new TreeNode(val);
        }
        return root;
    }
    
};
