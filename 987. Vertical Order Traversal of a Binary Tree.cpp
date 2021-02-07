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

//!! sol1.1, my revised by gy2, O(nlog(n/k)), O(n)
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>> > m;
        helpler(root, 0, 0, m);
        int prev_col = INT_MIN;
        for(auto& cols:m){
            vector<int> new_cols;
            for(auto& rows:cols.second){
                new_cols.insert(new_cols.end(), rows.second.begin(), rows.second.end());
            }
            ans.push_back(new_cols);
        }
        return ans;
    }
    void helpler(TreeNode* cur, int row, int col,  map<int, map<int, multiset<int>> >& m){
        if(!cur) return;
        m[col][row].insert(cur->val);
        helpler(cur->left, row+1, col-1, m);
        helpler(cur->right, row+1, col+1, m);
    }
};

// sol1, my, O(nlog(n/k)), O(n)
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
//         m[{col, row}].insert(cur->val);
//         helpler(cur->left, row+1, col-1, m);
//         helpler(cur->right, row+1, col+1, m);
//     }
// };
