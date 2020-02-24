class Solution {
public:

    
    vector<vector<int>> levelOrderBottom(TreeNode* root){
        vector<vector<int>> res;
        visit(root, 0, res);

        reverse(res.begin(), res.end());
        return res;
    }

    void visit(TreeNode* root, int level, vector<vector<int>> & res){
        if(!root) return;
        if(res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        visit(root->left, level+1, res);
        visit(root->right, level+1, res);
    }
};






class Solution:
    
    # sol1: dfs recursively
    # https://leetcode.com/problems/binary-tree-level-order-traversal-ii/discuss/34978/Python-solutions-(dfs-recursively-dfs%2Bstack-bfs%2Bqueue).
#     def levelOrderBottom(self, root):
#         """
#         :type root: TreeNode
#         :rtype: List[List[int]]
#         """
#         res = []
#         self.dfs(root, 0, res)
#         return res[::-1]
        
#     def dfs(self, cur, level, res):
#         if cur:
#             if level == len(res):
#                 res.append([])
#             res[level].append(cur.val)
#             if cur.left:
#                 self.dfs(cur.left, level+1, res)
#             if cur.right:
#                 self.dfs(cur.right, level+1, res)

    # sol2 dfs+stack wrong because there are intersection between two level in stack
        # def levelOrderBottom(self, root):
        #     res = []
        #     if root is None:
        #         return []
        #     stack1 = [root]
        #     stack2 = []
        #     self.dfs(stack1, stack2, res)
        #     return res[::-1]
        # def dfs(self, stack1, stack2, res):
        #     level = 0
        #     while stack1 != []:
        #         while stack1 != []:
        #             cur = stack1.pop()
        #             if len(res) <= level:
        #                 res.append([])
        #             res[level].append(cur.val)
        #             if cur.right:
        #                 stack2.append(cur.right)
        #             if cur.left:
        #                 stack2.append(cur.left)
        #         level += 1
        #         stack1 = stack2
        #         stack2 = []
    # sol2: dfs+stack
    # https://leetcode.com/problems/binary-tree-level-order-traversal-ii/discuss/34978/Python-solutions-(dfs-recursively-dfs%2Bstack-bfs%2Bqueue).
        def levelOrderBottom(self, root):
            res = []
            if root:
                stack = [(root, 0)]
                while stack != []:
                    cur, level = stack.pop()
                    if level >= len(res):
                        res.insert(0, [])
                    res[-(level+1)].append(cur.val)
                    if cur.right:
                        stack.append((cur.right,level+1))
                    if cur.left:
                        stack.append((cur.left,level+1))
            return res
