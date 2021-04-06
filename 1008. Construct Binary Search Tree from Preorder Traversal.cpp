// !!! sol3, my, use preorder's property
// O(n), O(n)
//8,5,1,7,10,12
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, int i, int j) {
        if(i > j) return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        int k;
        for(k = i + 1; k <=  j; k++){
            if(preorder[k] > preorder[i]) break;
        }
        root->left = helper(preorder, i+1, k-1);
        root->right = helper(preorder, k, j);
        return root;
    }
};


//! sol2, Inorder traversal of BST is an array sorted in the ascending order.

// O(nlogn), O(n)
//8,5,1,7,10,12
//1 5 6 8 10 12
// 

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return helper(preorder, inorder, 0, n - 1, 0 , n-1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int i, int j, int a, int b){
        if(i > j) return NULL;
        int leftLen, rightLen, t;
        for(t = a; t <= b; t++) if(inorder[t] == preorder[i]) break;
        leftLen = t - a;
        rightLen = b - t + 1;
        
        TreeNode* root = new TreeNode(preorder[i]);
        root->left = helper(preorder, inorder, i+1, i+leftLen, a, t-1);
        root->right = helper(preorder, inorder, i+leftLen+1, j, t+1, b);
        return root;
    }
};

sol1, my, O(nlogn), O(n)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++){
            insert(preorder, i, root);        
        }
        return root;
        
    }
    void insert(vector<int>& preorder, int i, TreeNode* root){
        TreeNode* newNode = new TreeNode(preorder[i]);
        while(root){
            if(preorder[i] < root->val){
                if(root->left) root = root->left;
                else{
                    root->left = newNode;
                    return;
                }
            }
            else{
                if(root->right) root = root->right;
                else{
                    root->right = newNode;
                    return;
                }
            }
        }
        return;
    }
};
