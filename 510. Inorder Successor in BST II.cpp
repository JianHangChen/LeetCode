/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

//!! sol1.1, followup, my O(h), O(1)
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right != NULL){
            node = node->right;
            
            while(node && node->left){
                node = node->left;
            }
            return node;
        }
        else{
            Node* parent = node->parent;
            
            while(parent){
                if(parent-> left == node){
                    return parent;
                }
                else{
                    node = parent;
                    parent = parent->parent;
                }
            }
            
        }
        return NULL;
    }
};

// sol1, my O(h), O(1)
class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if(node->right != NULL){
            node = node->right;
            
            while(node && node->left){
                node = node->left;
            }
            return node;
        }
        else{
            Node* parent = node->parent;
            while(parent){
                if(parent->val > node->val){
                    return parent;
                }
                else{
                    parent = parent->parent;
                }
            }
            
        }
        return NULL;
    }
};
