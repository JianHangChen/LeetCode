   sol1, dfs
    TreeNode* new_root;
    
    void dfs(TreeNode* root){
        if(root->left){
            dfs(root->left);
            root->left->right = root;
            root->left->left = root->right;
            root->left = NULL;
            root->right = NULL;
        }
        else{
            new_root = root;
        }
    }
    
    TreeNode * upsideDownBinaryTree(TreeNode* root) {
        if(!root){
            return root;
        }
        dfs(root);
        return new_root;
    }
    
    //sol2, iteratively
    TreeNode * upsideDownBinaryTree(TreeNode* root) {
        if(!root){
            return root;
        }
        
        TreeNode* left, * leftleft, * leftright, *right; 
        left = root->left;
        right = root->right;
        root->left = NULL; root->right = NULL;
        
        while(left){
            leftright = left->right;
            leftleft = left->left;
            left->right = root;
            left->left = right;
            
            root = left;
            left = leftleft;
            right = leftright;
        }
        return root;
        
    }
