# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # sol1, my recursive, O(n), O(h)/O(n)
    # def invertTree(self, root: 'TreeNode') -> 'TreeNode':
    #     if root is not None:
    #         right = root.right
    #         left = root.left
    #         root.left = self.invertTree(right)
    #         root.right = self.invertTree(left)
    #     return root
    
    # sol2, my iterative
    # def invertTree(self, root: 'TreeNode') -> 'TreeNode':
    #     if root is None:
    #         return None
    #     stack = [root]
    #     while stack != []:
    #         cur = stack.pop()
    #         if cur:
    #             cur.left, cur.right = cur.right, cur.left
    #             stack.append(cur.left)
    #             stack.append(cur.right)
    #     return root
    
    # sol3, my iterative, just use a queue
    def invertTree(self, root: 'TreeNode') -> 'TreeNode':
        if root is None:
            return None
        q = collections.deque()
        q.append(root)
        
        while len(q)!= 0:
            cur = q.popleft()
            cur.left, cur.right = cur.right, cur.left
            if cur.left:
                q.append(cur.left)
            if cur.right:
                q.append(cur.right)
        return root
