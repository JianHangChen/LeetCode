

TreeNode* reversLinkedList(TreeNode* root, int m, int n){
    TreeNode* dummy = new TreeNode(0);
    dummy->next = root;

    TreeNode* pre = dummy, *cur = root, *next, *head, *head_pre, *tail, *tail_next;
    int i = 1;
    while(cur){
        if(i == m){
            head = cur;
            head_pre = pre;
        }
        if(i == n){
            tail = cur;
            tail_next = tail->next;
        }
        if(i >= m && i <= n){
            next = cur->next;
            cur->next = pre;     
            pre = cur;
            cur = next;
        }else{
            pre = cur;
            cur = cur->next;
        }

        i++;
    }

    head->next = tail_next;
    head_pre->next = tail;
    return dummy->next; 
};


// !!! sol1, my, iteratively, O(n), O(1), same as ans2
class Solution{
public:
  ListNode* reverseBetween(ListNode* head, int m , int n){
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* pre = dummy, *cur = head, *next;

    ListNode* pre_m, *node_m;

    int i = 1;
    while(i <= n){
      next = cur->next;
      if(i == m){
        pre_m = pre;
        node_m = cur;
      }
      else if(i > m){
        cur->next = pre;
      }

      pre = cur;
      cur = next;
      i++;
    }


    pre_m->next = pre;
    node_m->next = cur;
    return dummy->next;
  }
};




Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL


// sol2, iteratively, from gy, even easier to implement

class Solution{
public:
  ListNode* reverseBetween(ListNode* head, int m, int n){
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;

    ListNode* pre = dummy, *cur = head, *next;

    int i = 1;
    while(i < m){
      pre = cur;
      cur = cur->next;
      i++;
    }

    while(i < n){
      next = cur->next;
      cur->next = next->next;
      next->next = pre->next;
      pre->next = next;
      i++;
    }

    return dummy->next;
  }
};
