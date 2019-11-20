class Solution {
public:
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
        ListNode* curA = headA, *curB = headB;
        while(curA != curB){
            if(curA) curA = curA->next;
            else curA = headB;
            if(curB) curB = curB->next;
            else curB = headA;
        }
        return curA;
    }
};
