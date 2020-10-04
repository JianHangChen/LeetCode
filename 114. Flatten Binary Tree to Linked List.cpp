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

//!!! sol2, iteration, O(n), O(1), morris traversal, from sol3
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root, *rightmost;
        while(cur){
            if(cur->left){
                rightmost = cur->left;
                while(rightmost->right) rightmost = rightmost->right;
                rightmost->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }    
    }
};

//!!! sol1, my, O(n), O(n), recursion using a global last element
class Solution {
public:
    TreeNode* last;
    void flatten(TreeNode* root) {
        if(!root) return;
        last = root;
        TreeNode* left = root->left, *right = root->right;
        if(left){
            root->right = left;
            root->left = NULL;
            flatten(left);
        }
        last->right = right;
        flatten(right);        
        
    }
};
