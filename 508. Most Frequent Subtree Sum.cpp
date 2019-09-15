/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> m; // sum, count
        
        getSubSum(root, m);
        
        vector<int> res;
        int max_frequence = 0;
        
        for(auto iter:m){
            if( iter.second > max_frequence){
                res = {iter.first};
                max_frequence = iter.second;
            }
            else if(iter.second == max_frequence){
                res.push_back(iter.first);
            }
        }
        return res;
    }
    
    int getSubSum(TreeNode* root, unordered_map<int, int>& m){
        int subSum;
        if(!root) return 0;
        subSum = root->val;
        subSum += getSubSum(root->left, m);
        subSum += getSubSum(root->right, m);
        
        m[subSum]++;
        return subSum;
        
    }
};
