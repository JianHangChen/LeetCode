//sol2, iteratively
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        while(root || !st.empty()){
            if(root){
                res.push_back(root->val);
                st.push(root->right);
                root = root->left;
            }
            else{
                root = st.top(); st.pop();
            }
        }
        return res;        
    }
};


//sol1, recursively
class Solution {
vector<int> res;
public:
    vector<int> preorderTraversal(TreeNode* root) {
      helpler(root);
      return res;
    }

    void helpler(TreeNode* root){
      if(root == NULL) return;
      res.push_back(root->val);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
    }
};
