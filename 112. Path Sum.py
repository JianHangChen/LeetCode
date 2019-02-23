# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        
        #sol1: recursive, my, hint from solution
        # if root is None:
        #     return False
        # if root.left is None and root.right is None:
        #     return root.val == sum
        # else:
        #     if self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val):
        #         return True
        #     else:
        #         return False
            
        # #sol1.1: recursive from solution
        # if root is None:
        #     return False
        # children = [root.left, root.right]
        # if not any(children):
        #     return sum == root.val
        # else:
        #     return self.hasPathSum(root.left, sum - root.val) or self.hasPathSum(root.right, sum - root.val)
        
        # sol2: dfs with stack, from sol
#         cur = root
#         stack = []
        
#         while cur or stack:
#             if cur:
#                 sum = sum - cur.val
#                 children = [cur.left, cur.right]
#                 if sum == 0 and not any(children):
#                     return True
#                 stack.append((cur, sum))
#                 cur = cur.left
#             else:
#                 cur, sum = stack.pop()
#                 cur = cur.right
#         return False
    
        # sol3: BFS with queue
        # from https://leetcode.com/problems/path-sum/discuss/36486/Python-solutions-(DFS-recursively-DFS%2Bstack-BFS%2Bqueue)
        if root == None:
            return False
        q = collections.deque()
        q.append((root,sum))
        while len(q)!= 0:
            cur,sum = q.popleft()
            children = [cur.left, cur.right]
            if not any(children) and sum == cur.val:
                return True
            if cur.left:
                q.append((cur.left, sum-cur.val))
            if cur.right:
                q.append( (cur.right, sum-cur.val) )
        return False
                
        
