
 sol1,  dfs
class Solution {
private:
    unordered_set<int> s;
    int k;
public:
    bool findTarget(TreeNode* root, int k) {
        this->k = k;
        return dfs(root);
    }
    
    bool dfs(TreeNode* root){
        if(root == NULL) return false;
        
        if(s.count(root->val) > 0){
            return true;
        }
        
        s.insert(k - root->val);     
        
        return dfs(root->left) || dfs(root->right);
    }
    
};


sol2, bfs
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        unordered_set<int> s;
        queue<TreeNode*> q({root});
        TreeNode* cur;
        
        while(!q.empty()){
            cur = q.front(); q.pop();
            if(s.count(k - cur->val) > 0 ) return true;
            s.insert(cur->val);
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        return false;
    }
    
    
};

//sol3, inorder travelsal
class Solution{
public:
    bool findTarget(TreeNode* root, int k){
        vector<int> arr;
        inorder(arr, root);
        int l = 0, h = arr.size() - 1;
        while(l < h){
            if(arr[l] + arr[h] == k) return true;
            (arr[l] + arr[h] < k) ? l++ : h--;
        }
        return false;
        
    }
    void inorder(vector<int>& arr,TreeNode* root){
        if(!root) return;
        inorder(arr, root->left);
        arr.push_back(root->val);
        inorder(arr, root->right);
    }
};
