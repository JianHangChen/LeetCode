# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # sol1,  morris traversal
        # https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45550/C++-Iterative-Recursive-and-Morris-Traversal/112664
        # https://www.youtube.com/watch?v=5jWYOwMsVGo&t=194s
#         dummy = TreeNode(0)
#         dummy.left = root
#         cur = dummy
#         res = []
#         while cur:
#             if cur.left:
#                 predecessor = self.findpred(cur.left, cur)
#                 if predecessor.right is None:
#                     predecessor.right = cur
#                     cur = cur.left
#                 else:
#                     predecessor.right = None
#                     self.postpop(cur.left, predecessor,res)
#                     cur = cur.right
#             else:
#                 cur = cur.right
#         return res
                    
#     def findpred(self, start, cur):
#         while start.right and (start.right is not cur):
#             start = start.right
#         return start
#     def postpop(self, start, end, res):
#         self.reverse(start, end)
#         while end:
#             res.append(end.val)
#             end = end.right
#     def reverse(self,start,end):
#         pre = None
#         cur = start
#         next_node = cur.right
#         while cur:
#             next_node = cur.right
#             cur.right = pre
#             pre = cur
#             cur = next_node
#         return
    #sol2:my recursively
#         res = []
#         self.helpler(root, res)
#         return res
    
#     def helpler(self, root, res):
#         if root is None:
#             return
#         else:
#             self.helpler(root.left, res)
#             self.helpler(root.right, res)
#             res.append(root.val)
    # sol3, iteratively
        res = []
        if root is not None:
            stack = [root]
            cur = root
            while stack:
                cur = stack.pop()
                res.append(cur.val)
                if cur.left:
                    stack.append(cur.left)
                if cur.right:
                    stack.append(cur.right)
        return res[::-1]
    
    # very good summary for all iterative methods
    # https://leetcode.com/problems/binary-tree-postorder-traversal/discuss/45551/Preorder-Inorder-and-Postorder-Iteratively-Summarization
    # sol3.1 iteratively, but use the thinking of above link
        res = []
        stack = []
        cur = root
        while cur or stack != []:
            if cur:
                res.append(cur.val)
                stack.append(cur)
                cur = cur.right
            else:
                cur = stack.pop().left
        return res[::-1]
                    
