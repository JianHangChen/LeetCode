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
//!!! sol1.2, revised from 1.1, use index to avoid map, O(nlog(n/k)), O(n)
class Solution {
public:
    int min_col = 0, max_col = 0;
    int max_row = 0;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map<int, unordered_map<int, multiset<int>> > m;
        helpler(root, 0, 0, m);

        for(int c = min_col; c <= max_col; c++){
            vector<int> new_col;
            for(int r = 0; r <= max_row; r++){
                if(m[c].count(r) > 0){
                    new_col.insert(new_col.end(), m[c][r].begin(), m[c][r].end());
                }
            }
            ans.push_back(new_col);
        }
        return ans;
    }
    void helpler(TreeNode* cur, int row, int col,  unordered_map<int, unordered_map<int, multiset<int>> >& m){
        if(!cur) return;
        max_row = max(max_row, row);
        min_col = min(min_col, col);
        max_col = max(max_col, col);
        m[col][row].insert(cur->val); // log(n/k)
        helpler(cur->left, row+1, col-1, m);
        helpler(cur->right, row+1, col+1, m);
    }
};



//! sol1.1, my revised by gy2, O(nlognloghlog(n/k)), O(n)
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>> ans;
//         map<int, map<int, multiset<int>> > m;
//         helpler(root, 0, 0, m);
//         int prev_col = INT_MIN;
//         for(auto& cols:m){
//             vector<int> new_cols;
//             for(auto& rows:cols.second){
//                 new_cols.insert(new_cols.end(), rows.second.begin(), rows.second.end());
//             }
//             ans.push_back(new_cols);
//         }
//         return ans;
//     }
//     void helpler(TreeNode* cur, int row, int col,  map<int, map<int, multiset<int>> >& m){
//         if(!cur) return;
//         m[col][row].insert(cur->val); // log(n)(logh)log(n/k)
//         helpler(cur->left, row+1, col-1, m);
//         helpler(cur->right, row+1, col+1, m);
//     }
// };

// sol1, my, O(nlog(n)log(n/k)), O(n)
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         vector<vector<int>> ans;
//         map<vector<int>, multiset<int>> m;
//         helpler(root, 0, 0, m);
//         int prev_col = INT_MIN;
//         for(auto& ele:m){
//             if(ele.first[0] != prev_col){
//                 ans.push_back({});
//                 prev_col = ele.first[0];
//             }
//             for(int value:ele.second){
//                 ans.back().push_back(value);            
//             }
//         }
//         return ans;
//     }
//     void helpler(TreeNode* cur, int row, int col, map<vector<int>, multiset<int>>& m){
//         if(!cur) return;
//         m[{col, row}].insert(cur->val); // log(n)log(n/k)
//         helpler(cur->left, row+1, col-1, m);
//         helpler(cur->right, row+1, col+1, m);
//     }
// };
