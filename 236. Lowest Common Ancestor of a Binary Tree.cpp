



// !!! sol1.1, from gy2, O(n), O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root == p || root ==q ) return root;
        else{
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            if(left != NULL && (left  != p && left != q))  return left;
            
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if(left != NULL && right == NULL) return left;
            else if(left == NULL && right != NULL) return right;
            else if(left != NULL && right != NULL) return root;
            else return NULL;
        }   
    }
};




// sol1, from gy1, O(n), O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root-> val == p->val || root->val ==q->val) return root;
        else{
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if(left != NULL && right == NULL) return left;
            else if(left == NULL && right != NULL) return right;
            else if(left != NULL && right != NULL) return root;
            else return NULL;
        }   
    }
};

