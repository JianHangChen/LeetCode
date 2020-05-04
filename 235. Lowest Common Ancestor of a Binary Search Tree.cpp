

sol1, my recursively, O(n), O(n)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        else if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        else return root;
        
    }  
};

//!!!my, sol2, iteratively, O(n), O(1)

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(true){
            if(root->val > p-> val && root->val > q->val){
                root = root->left;
            }
            else if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else{
                return root;
            }
        }
        return root;
    }  
};
