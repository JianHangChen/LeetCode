/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// sol3, use pair output
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/discuss/923669/simple-C%2B%2B-solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto res = LCA(root, p, q);
        return (res.second == 2) ? res.first : NULL;
    }
    
    pair<TreeNode*, int> LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return {NULL, 0};
        auto left = LCA(root->left, p, q);
        auto right = LCA(root->right, p, q);

        int count = left.second + right.second;
        if(root == p || root == q) return {root, ++count};
        
        if(left.second == 1 && right.second == 1) return {root, count};
 
        return left.first == NULL ? right : left;
        
    } 
};


// sol2, use global flag to check if p, q exist
class Solution {
private:
    bool exist_p = false, exist_q = false; 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto res = LCA(root, p, q);
        if(exist_p && exist_q) return res;
        return NULL;
    }
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL) return root;
        
        if(root == p) exist_p = true;
        else if(root == q) exist_q = true;
        
        auto left = LCA(root->left, p, q);
        auto right = LCA(root->right, p, q);
        if(root == p || root == q) return root;
        if(left != NULL && right != NULL) return root;
        return left == NULL ? right : left;
        
    }
};

!!! sol1, reuse previous lca, from lai, followup
O(n), O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = LCA(root, p, q);
        if(res == p){
            if(LCA(root, q, q) != NULL) return res;
            else return NULL;
        }
        else if(res == q){
            if(LCA(root, p, p) != NULL) return res;
            else return NULL;
        }
        return res;
    }
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p, q);
        if(left != NULL && right != NULL) return root;
        return left != NULL ? left : right;
    }

};
