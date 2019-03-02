# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # so1, my, return Flag, not bad but easily wrong
#     def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
#         self.res = None
#         def containpq(root):
#             p_res = q_res = None
#             if root is None:
#                 return (False, False, False) # p, q, stop
#             if root is p:
#                 p_res = True
#             if root is q:
#                 q_res = True
            
#             if not(p_res and q_res):
#                 leftp, leftq, stop = containpq(root.left)
#                 if stop:
#                     return (True, True, stop)
#                 rightp, rightq, stop = containpq(root.right)
#                 if stop:
#                     return (True, True, stop)            
#             if not p_res:
#                 p_res = leftp or rightp
#             if not q_res:
#                 q_res = leftq or rightq
#             if p_res and q_res:
#                 self.res = root
#                 stop = True
#             return (p_res, q_res, stop)
        
#         containpq(root)
#         return self.res

    # sol2, return flag, recursively, from sol
#     def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
#         self.res = None
#         def containpq(root):
#             if root is None:
#                 return False
#             mid = root is p or root is q
#             left = containpq(root.left)
#             right = containpq(root.right)
            
#             if mid+left+right >= 2:
#                 self.res = root
                
#             return mid or left or right
#         containpq(root)
#         return self.res
    
    # sol3, iteratively using parent point, from sol
    # def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    #     parent = {root:None}
    #     stack = [root] # p, q exist so root is not None
    #     # iteratively traverse all point using stack until recorde p and q:
    #     while p not in parent or q not in parent:
    #         cur = stack.pop() # p, q exist so not check empty
    #         if cur.left:
    #             parent[cur.left] = cur
    #             stack.append(cur.left)
    #         if cur.right:
    #             parent[cur.right] = cur
    #             stack.append(cur.right)
    #     ancestors = set()
    #     while p:
    #         ancestors.add(p)
    #         p = parent[p]
    #     while q:
    #         if q in ancestors:
    #             return q
    #         q = parent[q]
    
    # sol4, iteratively without using parent pointer, from sol
    # extremely complicated
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        BOTH_PENDING = 2
        LEFT_DONE = 1
        BOTH_DONE = 0
        
        LCA_idx = -1
        
        stack = [(root, BOTH_PENDING)]
        
        while stack:
            
            cur, cur_state = stack[-1]
            
            if cur_state != BOTH_DONE:
                        
                if cur_state == BOTH_PENDING:
                    if cur is p or cur is q:
                        
                        if LCA_idx != -1:  # already found one p q
                            return stack[LCA_idx][0]
                        else:
                            LCA_idx = len(stack) - 1 # update current LCA_idx, indicate one p or q has been found

                    
                    child = cur.left
                else:
                    child = cur.right
                
                # indicate we visited left or both children
                stack.pop()
                stack.append((cur, cur_state - 1 ))

                if child:
                    stack.append((child, BOTH_PENDING))
                
            
            else:
                if LCA_idx == len(stack) - 1:
                    LCA_idx -= 1
                stack.pop()
        return None
    
