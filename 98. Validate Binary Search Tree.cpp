

// !!! sol3, from gy5, inorder, morris traversal, O(n), O(1)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* cur = root, *pre = NULL, *l_most;
        bool res = true;
        while(cur){
            if(!cur->left){
                if(pre && pre->val >= cur->val){
                    res = false;
                }
                pre = cur;
                cur = cur->right;
            }
            else{
                l_most = cur->left;
                while(l_most->right && l_most->right != cur){
                    l_most = l_most->right;
                }
                if(!l_most->right){
                    l_most->right = cur;
                    cur = cur->left;
                }
                else{
                    l_most->right = NULL;
                    if(pre && pre->val >= cur->val){
                        res = false;
                    }
                    pre = cur;
                    cur = cur->right;
				}
            }
        }
        return res;
    }
};

// sol2.2, from gy4, inorder and stack, O(n), O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root, *pre = NULL;
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top(); s.pop();
                if(pre && pre->val >= cur->val) return false;
                pre = cur;
                cur = cur->right;
            }
        }
        return true;
    }
};

sol2.1, from gy3, inorder and compare the pre and current value
O(n), O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = NULL;
        return inorder(root, pre);
    }
    bool inorder(TreeNode* root, TreeNode*& pre){
        if(!root) return true;
        bool leftValid = inorder(root->left, pre);
        if(!leftValid) return false;
        if(pre && pre->val >= root->val) return false;
        pre = root;
        return inorder(root->right, pre);
    }
};

!! sol2, from gy2, inorder and create another array O(n), O(n)
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        int n = in.size();
        for(int i = 0; i < n - 1; i++){
            if(in[i] >= in[i+1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int>& in){
        if(!root) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
};

sol1, long min, O(n), O(n), gy1
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long mini, long maxi) {
        if(!root ) return true;
        if(root->val >= maxi || root->val <= mini) return false;
        return isValidBST(root->left, mini, root->val) && isValidBST(root->right, root->val, maxi);
        
    }
    
};

