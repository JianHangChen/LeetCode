# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    # sol1, recursively !!!
#     def isSymmetric(self, root):
#         """
#         :type root: TreeNode
#         :rtype: bool
#         """       
#         if root == None:
#             return True
#         else:
#             return self.isReflection(root.left,root.right)
            
#     def isReflection(self,left,right):
#         if left == None and right == None:
#             return True
#         elif left == None or right == None:
#             return False

#         if left.val != right.val:
#             return False
#         else:
#             return self.isReflection(left.left,right.right) and self.isReflection(left.right, right.left)

    # sol2, iteratively, O(n), O(n)
#     def isSymmetric(self, root):
#         if root == None:
#             return True
#         leftstack = [root.left]
#         rightstack = [root.right]
        
#         while leftstack and rightstack:
#             left = leftstack.pop()
#             right = rightstack.pop()
#             if (left != None and right == None) or (left == None and right != None):
#                 return False
#             if (left and right):
#                 if left.val != right.val:
#                     return False
#                 leftstack.extend([left.left,right.left])
#                 rightstack.extend([right.right,left.right])
        
#         return True
    # sol3, ieratively, only use one queue        
    def isSymmetric(self, root):
        if root == None:
            return True
        q = collections.deque()
        q.append(root.left)
        q.append(root.right)
        while len(q) != 0:
            left= q.popleft()
            right = q.popleft()
            if left == None and right == None: continue
            if left == None or right == None: return False
            if left.val != right.val: return False
            q.append(left.left)
            q.append(right.right)
            q.append(left.right)
            q.append(right.left)
        
        return True
        
