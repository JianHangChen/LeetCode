/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
     */
    int findClosestLeaf(TreeNode * root, int k) {
        unordered_map<TreeNode*, TreeNode*> m;
        TreeNode* knode,* cur;
        knode = find(root, k, m);
        queue<TreeNode*> q({knode});
        unordered_set<TreeNode*> visited({knode});
        
        while(!q.empty()){
            cur = q.front(); q.pop();
            if(!cur->left && !cur-> right){
                return cur->val;
            }
            if(cur->left && visited.count(cur->left) == 0){
                visited.insert(cur->left);
                q.push(cur->left);
            }
            if(cur->right && visited.count(cur->right) == 0){
                visited.insert(cur->right);
                q.push(cur->right);
            }
            if(m.count(cur) != 0 && visited.count(m[cur]) == 0){
                visited.insert(m[cur]);
                q.push(m[cur]);
            }
        }
        return -1;
        
    }
    
    TreeNode* find(TreeNode* root, int val, unordered_map<TreeNode*, TreeNode*> &m){
        TreeNode* res;
        if(root->val == val){
            return root;
        }
        if(root->left){
            m[root->left] = root;
            res = find(root->left, val, m);
            if(res) return res;
        }
        if(root->right){
            m[root->right] = root;
            res = find(root->right, val, m);
            if(res) return res;
        }
        return NULL;
    }
};
