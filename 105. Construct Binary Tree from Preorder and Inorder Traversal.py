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

        
