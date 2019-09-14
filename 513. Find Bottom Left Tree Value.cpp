/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//sol1, my pre-order travelsar
class Solution {
    
private:
    int deepest_level = 0;
    TreeNode* leftmost;
public:
    int findBottomLeftValue(TreeNode* root) {
        leftmost = root;
        
        helpler(root, 0);
        
        
        return leftmost->val;
        
    }
    
    void helpler(TreeNode* cur, int level){
        if(!cur) return;
        if(level > deepest_level){
            leftmost = cur;
            deepest_level = level;
        }
        
        helpler(cur->left, level+1);
        helpler(cur->right, level+1);
    }
};


// sol2, from gy sol3, queue, level order travelsar and reverse order
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q({root});
        
        TreeNode* cur;
        while(!q.empty()){
            int l = q.size();
            
            for(int i = 0; i < l; i++){
                cur = q.front(); q.pop();
                if(cur->right) q.push(cur->right);
                if(cur->left) q.push(cur->left);
            }
            
        }
        return cur->val;
    }

};
