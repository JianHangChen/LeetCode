# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    # sol1, most voted, but O() 
    # https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/discuss/34814/A-Python-recursive-solution
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder or not postorder:
            return None
        root = TreeNode( postorder.pop() )
        rootInorderIdx = inorder.index(root.val)
        root.right = self.buildTree(inorder[rootInorderIdx+1:], postorder)
        root.left = self.buildTree(inorder[:rootInorderIdx], postorder)
        
        return root
        
        
        
    # That's because inorder traversal goes 'Left-Parent-Right' and postorder traversal goes 'Left-Right-Parent'. And, postorder.pop() keeps picking the right-most element of the list, that means it should go 'Parent-(one of parents of) Right (subtree) - Left'. So, switching the order doesn't work.

      
    # sol2,
    # def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
