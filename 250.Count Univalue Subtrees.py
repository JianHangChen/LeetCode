# leetcode: 250.Count Univalue Subtrees
# lintcode: 921.Count Univalue Subtrees



"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: the given tree
    @return: the number of uni-value subtrees.
    """
    # sol1.1 from https://www.geeksforgeeks.org/find-count-of-singly-subtrees/
    
    # sol1, my recursive
    # def countUnivalSubtrees(self, root):
    #     return self.helpler(root)[0]
    # def helpler(self, root):
    #     # return a count and if it is a unival subtree
    #     isUnival = False
    
    #     if root == None:
    #         return (0, False)
    #     children = [root.left, root.right]
    #     if not any(children):
    #         return (1, True)
            
    #     left_result = self.helpler(root.left)
    #     right_result = self.helpler(root.right) 
    #     count = left_result[0] + right_result[0]
        
    #     if left_result[1] and right_result[1]:
    #         if root.val == root.left.val and root.val == root.right.val:
    #             count += 1
    #             isUnival = True
                
    #     if left_result[1] and root.left and root.right == None: # only left
    #         if root.val == root.left.val:
    #             count += 1
    #             isUnival = True
    #     if right_result[1] and root.right and root.left == None: #only right
    #         if root.val == root.right.val:
    #             count += 1
    #             isUnival = True
    #     return (count,isUnival)
    
