// !!! sol2, from sol3, O(n), O(logn), no need for extra memory, inorder traversal
// hard to implement
class Solution {
private:
    ListNode* curlist;
public:

    TreeNode * sortedListToBST(ListNode * head) {
        int l = 0;
        ListNode* cur = head;
        while(cur){
            l++;
            cur = cur->next;
        }
        curlist = head;
        return help(head, 0, l-1);
        
    }
    
    TreeNode* help(ListNode * head, int l, int r){
        if(l > r) return NULL;
        
        int m = l + (r - l) / 2;
        
        TreeNode* left = help(head, l, m-1);
        TreeNode* mid = new TreeNode(curlist->val);
        curlist = curlist->next;
        TreeNode* right = help(head, m+1, r);
        mid->left = left;
        mid->right = right;
        return mid;
        
    }
};

//!!! sol1, my extra array + dfs, O(n), O(n), same as sol2
class Solution {
private:
    vector<ListNode*> v;
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        while(cur){
            v.push_back(cur);
            cur =  cur->next;
        }
        return sortedListToBST(head, 0, v.size() - 1);   
    }
    TreeNode* sortedListToBST(ListNode* head, int l, int h) {
        if(l > h) return NULL;
        int mid = l + (h - l) / 2;
        TreeNode* res = new TreeNode(v[mid]->val);
        res->left = sortedListToBST(v[l], l, mid - 1);
        res->right = sortedListToBST(v[mid]->next, mid+1, h);
        return res;        
    }
};
