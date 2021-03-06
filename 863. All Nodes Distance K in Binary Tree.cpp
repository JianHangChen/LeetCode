/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// !!! sol2.1, my, similar to gy2, use hashmap to dfs record parent, bfs get res, O(n), O(n)
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> parent;
       
        dfs(root, parent, NULL);
        unordered_set<TreeNode*> visited({target});
        queue<TreeNode*> q({target});
        while(K > 0){
            int l = q.size();
            for(int i = 0; i < l; i++){
                TreeNode* cur = q.front(); q.pop();
                vector<TreeNode*> next = {cur->left, cur->right, parent[cur]};
                for(auto node:next){
                    if(node && visited.count(node) == 0){
                        visited.insert(node);
                        q.push(node);
                    }
                }
            }
            K--;     
        }
        while(!q.empty()){
            res.push_back(q.front()->val); q.pop();
        }
        return res;
    }
    
    void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* father){
        if(!root) return;
        parent[root] = father;
        dfs(root->left, parent, root);
        dfs(root->right, parent, root);        
    }
    
};


//sol2, from gy2, use hashmap to record parent, bfs, O(n), O(n)
class Solution{
private:
    unordered_map<TreeNode*, vector<TreeNode*>> m;
    unordered_set<TreeNode*> visited;
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K){
        vector<int> res;
        record(root);
        queue<TreeNode*> q({target});
    
        TreeNode* cur;
        while(!q.empty()){            
            if(K == 0){
                for(int i = q.size(); i > 0; i--){
                    cur = q.front(); q.pop();
                    res.push_back(cur->val);
                }
                break;
            }
            
            for(int i = q.size(); i > 0; i--){
                cur = q.front(); q.pop();
                if(visited.count(cur) > 0) continue;
                for(auto v:m[cur]){
                    if(visited.count(v) == 0) q.push(v);                
                }
                visited.insert(cur);
            }
            K--;
        }
        return res;
    }
    
    void record(TreeNode* cur){
        if(cur->left != NULL){
            m[cur].push_back(cur->left);
            m[cur->left].push_back(cur);
            record(cur->left);
        }        
        if(cur->right != NULL){
            m[cur].push_back(cur->right);
            m[cur->right].push_back(cur);
            record(cur->right);
        }
   }
    
    
    
};



// sol1, from gy1, use hashmap to record parent, dfs, O(n), O(n)
// class Solution {
// private:
//     unordered_map<TreeNode*, TreeNode*> m;
//     unordered_set<TreeNode*> visited;
// public:
//     vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
//         recordParent(root);
        
//         vector<int> res;
//         findKTarget(target, K, res);
//         return res;
        
//     }
    
//     void findKTarget(TreeNode* cur, int K, vector<int>& res){
//         if(cur == NULL || visited.count(cur)) return;
//         visited.insert(cur);
//         if(K == 0){
//             res.push_back(cur->val);
//             return;
//         }
        
//         if(cur->left) findKTarget(cur->left, K - 1, res);
//         if(cur->right) findKTarget(cur->right, K-1, res);
//         if(m[cur]) findKTarget(m[cur], K-1, res);
        
//     }
    
    
//     void recordParent(TreeNode* cur){
//         if(cur == NULL) return;
//         else{
//             if(cur->left){
//                 m[cur->left] = cur;
//                 recordParent(cur->left);
//             }
//             if(cur->right){
//                 m[cur->right] = cur;
//                 recordParent(cur->right);
//             }
//         }
//         return;
//     }
// };
