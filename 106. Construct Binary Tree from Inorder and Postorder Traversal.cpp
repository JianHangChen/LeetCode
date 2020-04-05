// sol2, use map to avoid list search, O(n), O(n)
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        int n = inorder.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++){
            m[inorder[i]] = i;
        }
        return reconstruct(inorder, 0, n - 1, postorder, 0, n - 1, m);
    }

    TreeNode* reconstruct(vector<int>& inorder, int i, int j, vector<int>& postorder, int a, int b, unordered_map<int, int>& m){        
        TreeNode* res;
        if(i > j || a > b) return NULL;

        if(i == j){
            res = new TreeNode(inorder[i]);
            return res;
        }

        int pivot = m[postorder[b]];
        res = new TreeNode(inorder[pivot]);
        res->left = reconstruct(inorder, i, pivot - 1, postorder, a, a + pivot - i - 1, m);
        res->right = reconstruct(inorder, pivot + 1, j, postorder, a + pivot - i, b - 1, m);
        return res;
    }

};




// my, sol1, most voted, but O(n^2) O(n^2) 
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        int n = inorder.size();
        return reconstruct(inorder, 0, n - 1, postorder, 0, n - 1);
    }

    TreeNode* reconstruct(vector<int>& inorder, int i, int j, vector<int>& postorder, int a, int b){        
        TreeNode* res;
        if(i > j || a > b) return NULL;

        if(i == j){
            res = new TreeNode(inorder[i]);
            return res;
        }

        int pivot = i;
        
        while(pivot <= j){
            if(inorder[pivot] == postorder[b]){
                res = new TreeNode(inorder[pivot]);
                res->left = reconstruct(inorder, i, pivot - 1, postorder, a, a + pivot - i - 1);
                res->right = reconstruct(inorder, pivot + 1, j, postorder, a + pivot - i, b - 1);
                return res;
            }
            pivot++;
        }
        return res;
    }

};








106 in and postorder
105 pre and in
not pre and post


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    # sol1, most voted, but O(n^2) O(n^2) 
    # https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/34814/A-Python-recursive-solution
#     def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
#         if not inorder or not postorder:
#             return None
#         root = TreeNode( postorder.pop() )
#         rootInorderIdx = inorder.index(root.val)
#         root.right = self.buildTree(inorder[rootInorderIdx+1:], postorder)
#         root.left = self.buildTree(inorder[:rootInorderIdx], postorder)
        
#         return root
        
        
        
    # That's because inorder traversal goes 'Left-Parent-Right' and postorder traversal goes 'Left-Right-Parent'. And, postorder.pop() keeps picking the right-most element of the list, that means it should go 'Parent-(one of parents of) Right (subtree) - Left'. So, switching the order doesn't work.

      
    # sol2, using map to avoid recursively list search
    # from https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/221681/Don't-use-top-voted-Python-solution-for-interview-here-is-why
#     def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
#         # map inorder list
#         self.inorderMap = {}
#         for idx, val in enumerate(inorder):
#             self.inorderMap[val] = idx
            
#         self.inorder = inorder
#         self.postorder = postorder
#         return self.findTree(0, len(inorder)-1)
        
#     def findTree(self, low: int, high: int) -> TreeNode:
#         if low > high:
#             return None
#         root = TreeNode( self.postorder.pop() )
#         rootInorderIdx = self.inorderMap[root.val]
#         root.right = self.findTree(rootInorderIdx+1, high)
#         root.left = self.findTree(low, rootInorderIdx-1)
        # return root
    
    # sol3, my recursively without using map enlightened by pochman
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def build(stop: int) ->TreeNode:
            if inorder and inorder[-1] != stop:
                root = TreeNode( postorder.pop() )
                root.right = build(root.val)
                inorder.pop()
                root.left = build(stop)
                
                return root
            
        return build(None)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    # sol1, most voted, but O(n^2) O(n^2) 
    # https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/34814/A-Python-recursive-solution
#     def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
#         if not inorder or not postorder:
#             return None
#         root = TreeNode( postorder.pop() )
#         rootInorderIdx = inorder.index(root.val)
#         root.right = self.buildTree(inorder[rootInorderIdx+1:], postorder)
#         root.left = self.buildTree(inorder[:rootInorderIdx], postorder)
        
#         return root
        
        
        
    # That's because inorder traversal goes 'Left-Parent-Right' and postorder traversal goes 'Left-Right-Parent'. And, postorder.pop() keeps picking the right-most element of the list, that means it should go 'Parent-(one of parents of) Right (subtree) - Left'. So, switching the order doesn't work.

      
    # sol2, using map to avoid recursively list search
    # from https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/221681/Don't-use-top-voted-Python-solution-for-interview-here-is-why
#     def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
#         # map inorder list
#         self.inorderMap = {}
#         for idx, val in enumerate(inorder):
#             self.inorderMap[val] = idx
            
#         self.inorder = inorder
#         self.postorder = postorder
#         return self.findTree(0, len(inorder)-1)
        
#     def findTree(self, low: int, high: int) -> TreeNode:
#         if low > high:
#             return None
#         root = TreeNode( self.postorder.pop() )
#         rootInorderIdx = self.inorderMap[root.val]
#         root.right = self.findTree(rootInorderIdx+1, high)
#         root.left = self.findTree(low, rootInorderIdx-1)
        # return root
    
    # sol3, my recursively without using map enlightened by pochman
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def build(stop: int) ->TreeNode:
            if inorder and inorder[-1] != stop:
                root = TreeNode( postorder.pop() )
                root.right = build(root.val)
                inorder.pop()
                root.left = build(stop)
                
                return root
            
        return build(None) 
