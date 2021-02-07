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


// sol2, revised from sol1, no sorting, O(n), O(n)
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        
        unordered_map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q({{root, 0}});
        int min_col = 0, max_col = 0;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            int col = cur.second; TreeNode* curNode = cur.first;
            min_col = min(min_col, col);
            max_col = max(max_col, col);
            m[col].push_back(curNode->val);
            if(curNode->left){
                q.push({curNode->left, col-1});
            }
            if(curNode->right){
                q.push({curNode->right, col+1});
            }
            
        }
        vector<vector<int>> res;
        for(int i = min_col; i <= max_col; i++){
            res.push_back(m[i]);
        }
        
        return res;
    }
};

// sol1, my, O(nlogn), O(n)
// class Solution {
// public:
//     vector<vector<int>> verticalOrder(TreeNode* root) {
//         if(!root) return {};
        
//         map<int, vector<int>> m;
//         queue<pair<TreeNode*, int>> q({{root, 0}});
//         while(!q.empty()){
//             auto cur = q.front(); q.pop();
//             int col = cur.second; TreeNode* curNode = cur.first;
//             m[col].push_back(curNode->val); // logn
//             if(curNode->left){
//                 q.push({curNode->left, col-1});
//             }
//             if(curNode->right){
//                 q.push({curNode->right, col+1});
//             }
            
//         }
//         vector<vector<int>> res;
//         for(auto& ele:m){
//             res.push_back(ele.second);
//         }
        
//         return res;
//     }
// };
