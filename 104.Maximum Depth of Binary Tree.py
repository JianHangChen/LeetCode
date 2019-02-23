# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # so1, my, bottom-up
    # def maxDepth(self, root):
    #     """
    #     :type root: TreeNode
    #     :rtype: int
    #     """
    #     if root == None:
    #         return 0
    #     return 1 + max( self.maxDepth(root.left), self.maxDepth(root.right))
    
    # sol2, top-down
    def maxDepth(self, root):
        self.ans = 0
        self.helpler(root, depth = 1)
        return self.ans
        
    def helpler(self, root, depth):
        if root == None:
            return 
        if root.left == None and root.right == None: # a leaf
            self.ans = max(self.ans, depth) # update the ans
        else:
            self.helpler(root.left, depth + 1)
            self.helpler(root.right, depth + 1)
        
