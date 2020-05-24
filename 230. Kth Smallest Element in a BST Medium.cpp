/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// follow up
//https://leetcode.com/articles/kth-smallest-element-in-a-bst/?page=4
// O(logn + k), O(n) using double linked list + unordered_map to maintain the order
// delete is O(logn), insert is also O(logn)

// !!! sol2.1 iteratively, O(logn+k), O(k)
// save more space using deque
// from https://leetcode.com/problems/kth-smallest-element-in-a-bst/discuss/63734/O(k)-space-O(n)-time-10%2B-short-lines-3-solutions

class Solution{
public:
    int kthSmallest(TreeNode* root, int k){
        deque<TreeNode*> dq;
        TreeNode* cur = root;
        int count = 0;
        while(cur || !dq.empty()){
            if(cur){
                dq.push_back(cur);
                cur = cur->left;
                while(dq.size() > k){
                    dq.pop_front();
                }
            }
            else{
                cur = dq.back(); dq.pop_back();
                count++;
                if(count == k) return cur->val;
                cur = cur->right;
            }
        }
        return -1;
    }
};

// !! sol2, iteratively, O(logn + k), O(logn)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int count = 0;
        
        while(cur || !s.empty()){
            if(cur){
                s.push(cur);
                cur = cur->left;
            }
            else{
                cur = s.top(); s.pop();
                count++;
                if(count == k) break;
                cur = cur->right;
            }
        }
        return cur->val;       
    }
};

my ! sol1.1, O(logn+k), O(logn)
class Solution {
public:
    int count = 0, res = 0;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
    bool dfs(TreeNode* root, int k){
        if(k == count) return true;
        if(!root) return false;
        if(dfs(root->left, k)) return true;
        if(++count == k){
            res = root->val;
            return true;
        }
        return dfs(root->right, k);
        
    }
    
};
my sol1, O(k), O(logn)
class Solution {
public:
    int count = 0;
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
    
     void dfs(TreeNode* root, int k){
        if(k == count) return;
         
        if(!root) return;
        dfs(root->left, k);
        if(++count == k){
            res = root->val;
            return;
        }
        dfs(root->right, k);        
    }
    
};
