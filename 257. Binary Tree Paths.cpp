

// sol1, my backtracking, O(n), O(n)
class Solution {
public:
    vector<string> res;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return res;
        vector<int> nums;
        traversal(root, nums);
        
        return res;
    }
    void traversal(TreeNode* root, vector<int>& nums){
        nums.push_back(root->val);
        if(!root->left && !root->right){
            string s = to_string(nums[0]);
            for(int i = 1; i < nums.size(); i++){
                s = s + "->" + to_string(nums[i]);
            }
            res.push_back(s);
        }
        if(root->left) traversal(root->left, nums);
        if(root->right) traversal(root->right, nums);
        nums.pop_back();
    }
    
};


// !!! sol2, iteratively, O(nlogn), O(nlogn)
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root) return res;
        stack<string> paths;
        
        stack<TreeNode*> st;
        st.push(root);
        paths.push(to_string(root->val));
        
        while(!st.empty()){
            TreeNode* cur = st.top(); st.pop();
            string path = paths.top(); paths.pop();
                        
            if(!cur->left && !cur->right){
                res.push_back(path) ; //leave
            }
            else{
                if(cur->left){
                    st.push(cur->left);
                    paths.push(path + "->" + to_string(cur->left->val));
                }
                if(cur->right){
                    st.push(cur->right);
                    paths.push(path + "->" + to_string(cur->right->val));
                }                
            }
        }
        
        return res;
    }

    

};
