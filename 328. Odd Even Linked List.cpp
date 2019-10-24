
// !!!! sol1.1, from sol, similar but eaiser for bug free
ListNode* oddEvenList(ListNode* head){
    if(head == NULL) return NULL;
    ListNode *odd = head, *even = head->next, *evenHead = head->next;
    while(even != NULL && even->next != NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;

}


// sol1, my

ListNode* oddEvenList(ListNode* head){
    if(!head) return head;
    ListNode* cur = head, *oddTail = head, *evenHead = head->next;
    bool isOdd = true;
    while(cur && cur->next){
      if(isOdd && cur->next->next) oddTail = cur->next->next;
      ListNode* next = cur->next;
      cur->next = cur->next->next;
      isOdd = !isOdd;
      cur = next;
    }
    oddTail->next = evenHead;
    return head;
}
