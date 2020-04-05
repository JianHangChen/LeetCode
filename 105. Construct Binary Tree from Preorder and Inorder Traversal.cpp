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



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# my sol1, O(n) O(n), using map
# class Solution:
#     def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        
#         # build inordermap
#         self.inorderMap = {}
#         for idx, val in enumerate(inorder):
#             self.inorderMap[val] = idx
#         self.preorder = preorder
#         self.inorder = inorder
#         self.preorderIdx = 0
        
#         return self.helpler(0, len(preorder)-1)
        
#     def helpler(self, low, high) -> TreeNode:
#         if low > high:
#             return None
        
#         root = TreeNode( self.preorder[self.preorderIdx] )
#         self.preorderIdx += 1
#         inorderIdx = self.inorderMap[root.val]
#         root.left = self.helpler(low, inorderIdx-1)
#         root.right = self.helpler(inorderIdx+1, high)
        
#         return root

# sol2, O(n), space <O(n) 
#from https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34543/Simple-O(n)-without-map
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        preorder.reverse()
        inorder.reverse()
        
        def build(stop):
            if inorder and inorder[-1] != stop:
                root = TreeNode(preorder.pop())
                root.left = build(root.val)
                inorder.pop()
                root.right = build(stop)
                return root
            
        return build(None)

        

