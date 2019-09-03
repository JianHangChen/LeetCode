/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */




// sol2, !!!!! map from acwing, O(n), O(n)

class Solution {
private:
    unordered_map<int,int> m;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if(n == 0) return NULL;
        for(int i = 0; i < n; i++) m[inorder[i]] = i;
        
        return buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pi, int pj, int ii, int ij){
        
        if(pi > pj || ii > ij) return NULL;
        
        TreeNode* root = new TreeNode(preorder[pi]);
        
        int idx = m[preorder[pi]];
        root->left = buildTree(preorder, inorder, pi + 1, pi + idx - ii, ii, idx - 1);
        root->right = buildTree(preorder, inorder, pi + idx - ii + 1, pj, idx + 1, ij);
        
        return root;
        
    }
    
};






// sol1, only recursively, O(n^2)

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         if(n == 0) return NULL;

        
//         return buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
//     }
    
    
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int pi, int pj, int ii, int ij){
        
//         if(pi > pj || ii > ij) return NULL;
        
//         TreeNode* root = new TreeNode(preorder[pi]);
        
//         int idx;
//         for(idx = ii; idx <= ij;idx++){
//             if(preorder[pi] == inorder[idx]) break;          
//         }
        
        
//         root->left = buildTree(preorder, inorder, pi + 1, pi + (idx - ii), ii, idx - 1);
//         root->right = buildTree(preorder, inorder, pi + (idx - ii) + 1, pj, idx + 1, ij);
        
//         return root;
        
//     }
    
// };

