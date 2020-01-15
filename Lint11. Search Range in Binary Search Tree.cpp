// !!! sol2, from 9ch

class Solution{
public:
  vector<int> searchRange(TreeNode* root, int k1, int k2){
    vector<int> res;
    searchRange(res, root, k1, k2);
    return res;
    
  }
  void searchRange(vector<int>& res, TreeNode* root, int k1, int k2){
    if(!root) return;
    if(root->val >= k1) searchRange(res, root->left, k1, k2);    
    if(root->val >= k1 && root->val <= k2) res.push_back(root->val);
    if(root->val <= k2) searchRange(res, root->right, k1, k2);
  }
};


// sol1, my
class Solution{
public:
  vector<int> searchRange(TreeNode* root, int k1, int k2){
    vector<int> res;
    
    searchRange(res, root, k1, k2);
    
    return res;
    
  }
  void searchRange(vector<int>& res, TreeNode* root, int k1, int k2){
    if(!root) return;
    if(root->val == k1){
      res.push_back(root->val);
      searchRange(res, root->right, k1, k2);
    }
    else if(root-> val > k1){
      searchRange(res, root->left, k1, k2);
      if(root->val <= k2){
        res.push_back(root->val);
      }
      searchRange(res, root->right, k1, k2);
    }
    else{
      searchRange(res, root->right, k1, k2);
    }    
  }
};
