/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// !!! sol1, dfs, preorder, O(n), O(n)
class Codec {
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        preorder(root, out);
        return out.str();
    }
    
    void preorder(TreeNode* root, ostringstream& out){
        if(!root){
            out << "#" << " ";
        }
        else{
            out << (root->val) << " ";
            preorder(root->left, out);
            preorder(root->right, out);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return decoder(in);        
    }
    TreeNode* decoder(istringstream& in){
        TreeNode* root;
        string s;
        in >> s;
        if(s == "#"){
            return NULL;
        }
        else{
            root = new TreeNode(stoi(s));
            root->left = decoder(in);
            root->right = decoder(in);
        }
        return root;
    }
};

// ! sol2, bfs
class Codec{
public:
    string serialize(TreeNode* root){
        queue<TreeNode*> q;
        ostringstream out;
        if(root) q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front(); q.pop();
            if(cur){
                out << cur->val << " ";
                q.push(cur->left);
                q.push(cur->right);
            }
            else{
                out << "#" << " ";
            }
        }
        return out.str();
    }  
    TreeNode* deserialize(string data){
        if(data.empty()) return NULL;
        queue<TreeNode*> q;
        istringstream in(data);
        TreeNode* cur, *root;
        string s;
        in >> s;
        if(s != "#"){
            root = new TreeNode(stoi(s));
            q.push(root);
        }
        while(!q.empty()){
            cur = q.front(); q.pop();
            in >> s;
            if(s != "#"){
                TreeNode* left = new TreeNode(stoi(s));
                cur->left = left;
                q.push(left);
            }
            in >> s;
            if(s != "#"){
                TreeNode* right = new TreeNode(stoi(s));
                cur->right = right;
                q.push(right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque


class Codec:

    
# sol1, from pochmann, preorder dfs
# https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74259/Recursive-preorder-Python-and-C%2B%2B-O(n)
    
#     def serialize(self, root):
#         """Encodes a tree to a single string.
        
#         :type root: TreeNode
#         :rtype: str
#         """
#         ans = []
#         def build(root):
#             if root:
#                 ans.append(str(root.val))
#                 build(root.left)
#                 build(root.right)
#             else:
#                 ans.append("#")
            
#         build(root)
#         return ",".join(ans)



#     def deserialize(self, data):
#         """Decodes your encoded data to tree.
        
#         :type data: str
#         :rtype: TreeNode
#         """
        
#         list = data.split(',')
#         vals = iter(list)

        
#         def build():
#             val = next(vals)
            
#             if val == '#':
#                 return None
#             root = TreeNode( int(val) )
#             root.left = build()
#             root.right = build()
#             return root
        
#         return build()

    
# sol2, my iteratively preorder dfs
#https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74260/Recursive-DFS-Iterative-DFS-and-BFS


    # my serialize used for pochmann structure end with 4##5##
    # def serialize(self, root):
    #     ans = []
    #     stack = [root]
    #     # cur = root
    #     while stack != []:
    #         cur = stack.pop()
    #         if cur:
    #             ans.append(str(cur.val))
    #             stack.append(cur.right)
    #             stack.append(cur.left)
    #         else:
    #             ans.append("#")
    #     return ",".join(ans)

# my serialize used for iterative preorder structure end with 4##5#
#     def serialize(self, root):
#         ans = []
#         stack = []
#         cur = root
        
#         while cur or stack != []:
#             if cur:
#                 ans.append(str(cur.val))
#                 stack.append(cur)
#                 cur = cur.left
            
#             else:
#                 ans.append("#")
#                 cur = stack.pop()
#                 cur = cur.right
#         return ",".join(ans)
    
# # my deserialize used for iterative preorder structure end with 4##5#
#     def deserialize(self, data):
#         if data == "":  return None
#         # if data=="#":  return None    #used for pochmann 4##5## 

#         list = data.split(',')
#         length = len(list)
#         root = cur = TreeNode( int(list[0]) )
        
#         stack = [cur]
                
#         i = 1
        
#         while i < length:
#             while i < length and list[i] != "#":
#                 cur.left = TreeNode( int(list[i]) )
#                 cur = cur.left
#                 stack.append(cur)
#                 i += 1
            
#             while i < length and list[i] == "#":
#                 # if len(stack) == 0:       for pochmann 4##5#
#                 #     return root
#                 cur = stack.pop()
#                 i += 1
#             if i < length:
#                 cur.right = TreeNode( int(list[i]) )
#                 cur = cur.right
#                 stack.append(cur)
#                 i += 1        
#         return root

# sol3, bfs
# https://www.jiuzhang.com/solution/serialize-and-deserialize-binary-tree/#tag-highlight-lang-python

# testcase:  root = None
    def serialize(self, root):
        ans = []
        queue = collections.deque()
        queue.append(root)
        while queue:
            
            cur = queue.popleft()
            if cur:
                ans.append(str(cur.val))
                queue.append( cur.left )
                queue.append( cur.right)
            else:
                ans.append('#')
        
        return ','.join(ans)

    def deserialize(self, data):
        if data == "#": return None
        list = data.split(',')
        
        queue = collections.deque()
        root = TreeNode( int(list[0]) )
        queue.append( root )
        i = 1
        while queue:
            cur = queue.popleft()
            if list[i] != '#':                
                cur.left = TreeNode( int(list[i]) )
                queue.append(cur.left)
            i += 1
            if list[i] != '#':
                cur.right = TreeNode( int(list[i]) )
                queue.append(cur.right)
            i += 1
        return root


# sol4, bfs by Leetcode default method

# have a look at: https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/
