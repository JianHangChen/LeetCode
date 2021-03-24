// We don't handle duplicate node values in the algorithm below. That is left as an exercise for the reader to solve :) It's a slight variation but an important one to understand for follow-up questions in an interview.


};

//!!! sol3, use bst, O(n), O(1)
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        TreeNode* cur = root, *res = NULL;
        while(cur){
            if(cur->val > p->val){
                res = cur;
                cur = cur->left;
            }
            else{
                cur = cur->right;
            }
        }
        
        return res;
    }
};
    
// ! sol2, recursively, gy2, O(n), O(n)
class Solution {
public:
    TreeNode* pre, * suc;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root) return NULL;
        inorder(root, p);
        return suc;
    }
    
    void inorder(TreeNode* root, TreeNode* p){
        if(!root) return;
        
        inorder(root->left, p);
        if(pre == p){
            suc = root;
            pre = root;
            return;
        }
        else{
            pre = root;        
            inorder(root->right, p);            
        }
    }
};

! sol1, iteratively using stack, O(n), O(n)
iteratively, inorder traversal
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool found = false;
        if(!root) return NULL;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top(); st.pop();
                if(found) return cur;
                if(cur == p) found = true;
                cur = cur->right;
            }
        }
        return NULL;    
    }
        
    
};
