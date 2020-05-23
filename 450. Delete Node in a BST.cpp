

//!!!sol2.1, iteratively from gy2, O(logn), O(1)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* pre = NULL, *cur = root, *left_right_most, *next;
        while(cur){
            if(cur->val == key) break;
            pre = cur;
            if(cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if(!cur) return root; // don't find a node
        if(!pre) return del(root);
        if(pre->left == cur) pre->left = del(cur);
        else pre->right = del(cur);
        return root;        
    }
    TreeNode* del(TreeNode* node){
        if(!node) return NULL;
        else if(!node->left) return node->right;
        else{
            TreeNode* left = node->left;
            while(left->right) left = left->right;
            left->right = node->right;
            return node->left;
        }
    }
};


//!!! sol1, my, dfs to find the node, and append right tree of the destination, to the rightmost node of the left tree, easier when answer in an interview
// O(logn), O(logn)
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{ // == key
            if(!root->left) return root->right;
            else{
                TreeNode* cur = root->left;
                while(cur->right){
                    cur = cur->right;
                }
                cur->right = root->right;
                return root->left;
            }
        }
        return root;
    }
};




sol2, my iteratively
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* pre = NULL, *cur = root, *left_right_most, *next;
        while(cur){
            if(cur->val == key) break;
            pre = cur;
            if(cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if(!cur) return root; // don't find a node
        
        if(!cur->left){
            next = cur->right;

        }
        else{
            next = cur->left;
            left_right_most = cur->left;
            while(left_right_most->right){
                left_right_most = left_right_most->right;
            }
            left_right_most->right = cur->right;
        }
        
        if(pre){
            if(pre->left == cur){
                pre->left = next;
            }
            else{
                pre->right = next;
            }
        }
        else{
            return next;
        }
        
        return root;
        
    }
};
