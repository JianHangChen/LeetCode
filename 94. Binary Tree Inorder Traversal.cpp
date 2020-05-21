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

//!!! sol3, iteratively, Morris traversal, O(n), O(1)
https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html

class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        TreeNode* cur = root, *pre = NULL;
        while(cur){
            if(!cur->left){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                // find pre
                pre = cur->left;
                while(pre->right && pre->right != cur){
                    pre = pre->right;
                }
                if(pre->right == NULL){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;        
    }
};
!! sol2, iteratively, O(n), space: avg O(logn), worst O(n)
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top(); s.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }    
};

sol1, recursive, my, O(n), space: avg O(logn), worst O(n)
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }
    void dfs(TreeNode* root){
        if(!root ) return;
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);        
    }
};
