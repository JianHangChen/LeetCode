

//     1 
//  2    4 
// 5 3  6  7

// 

// 1 | 2 4 5 3 6 7
// 4 5 2 6 7 3 | 1
// pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]


//!!! sol2, use map to avoid list search, O(n), O(n)

class Solution {
public:
    unordered_map<int, int> m;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        for(int i = 0; i < n; i++) m[post[i]] = i;
        return constructFromPrePost(pre, 0, n-1, post, 0, n - 1);
    }
    TreeNode* constructFromPrePost(vector<int>& pre, int i, int j, vector<int>& post, int a, int b){
        if(i > j) return NULL;
        TreeNode* root = new TreeNode(pre[i]);
        if(i == j) return root;
        int pivot = m[ pre[i+1] ];
        int left_len = pivot - a + 1;
        root->left = constructFromPrePost(pre, i + 1, i + left_len, post, a, a + left_len - 1);
        root->right = constructFromPrePost(pre, i + left_len + 1, j, post, a + left_len, b);
        return root;        
    } 
};



// sol1.1, from gy2, recursive, use default find of c++
// find the structure
// pre:  [root][left subtree][right subtree]
// post: [left subtree][right subtree][root]


// class Solution {
// public:
//     TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
//         return buildSubTree(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
//     }
    
//     TreeNode* buildSubTree(vector<int>& pre, vector<int>& post, int preL, int preR, int postL, int postR){
//         if(preL > preR || postL > postR) return NULL;
        
//         TreeNode* root = new TreeNode(pre[preL]);
        
//         if(preL == preR || postL == postR) return root;
        
//         int len = find(post.begin() + postL, post.end(), pre[preL+1]) - (post.begin() + postL) + 1;
        
//         TreeNode* leftSubTree = buildSubTree(pre, post, preL+1, preL+len, postL, postL+len-1);
//         TreeNode* rightSubTree = buildSubTree(pre, post, preL + len + 1, preR, postL+len, postR - 1);
//         root->left = leftSubTree;
//         root->right = rightSubTree;
//         return root;      
        
//     }
    
    
// };




// // sol1, from gy1, recursive:
// // find the structure
// // pre:  [root][left subtree][right subtree]
// // post: [left subtree][right subtree][root]


// class Solution {
// public:
//     TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
//         return buildSubTree(pre, post, 0, pre.size() - 1, 0, post.size() - 1);
//     }
    
//     TreeNode* buildSubTree(vector<int>& pre, vector<int>& post, int preL, int preR, int postL, int postR){
//         if(preL > preR || postL > postR) return NULL;
        
//         TreeNode* root = new TreeNode(pre[preL]);
        
//         if(preL == preR || postL == postR) return root;
        
        
//         int len = findPost(post, postL, pre[preL+1]) - postL + 1;
        
//         TreeNode* leftSubTree = buildSubTree(pre, post, preL+1, preL+len, postL, postL+len-1);
//         TreeNode* rightSubTree = buildSubTree(pre, post, preL + len + 1, preR, postL+len, postR - 1);
//         root->left = leftSubTree;
//         root->right = rightSubTree;
//         return root;      
        
//     }
    
//     int findPost(vector<int>& post,int postL, int val){
//         int idx = postL;
//         while(idx < post.size()){
//             if(val == post[idx]) return idx;
            
//             idx++;
//         }
//         return -1;
//     }
    
// };



//

//   1
//  2 3
//4 5 6 7
// pre [1] [2 4 5] [3 6 7]
// post[4 5 2] [6 7 3] [1]


