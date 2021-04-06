
//!! sol1, my, O(n), O(n)
class Solution {
public:
    vector<TreeNode*> v;
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n = v.size();
        return build(0, n - 1);
    }
    
    TreeNode* build(int start, int end){
        if(start > end) return NULL;
        
        int mid = start + (end - start + 1) / 2;
        v[mid]->left = build(start, mid-1);
        v[mid]->right = build(mid+1, end);
        return v[mid];
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        v.push_back(root);
        inorder(root->right);
    }
};

// 1 2 3 4 5 6 7 8 
// 
