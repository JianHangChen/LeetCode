Implement a Queue by linked list. Support the following basic methods:

enqueue(item). Put a new item in the queue.
dequeue(). Move the first item out of the queue, return it.

class ListNode{
    ListNode(int x){
        val = x;
    }
    int val;
    ListNode* next;
};

class Queue{
private:
    ListNode* head, *tail;
public:
    Queue(){
    }
    
    void enqueue(int x){
        ListNode* cur = new ListNode(x);
        if(!head){
          tail = cur;
          head = cur;
        }
        else{
          tail->next = cur;
          tail = tail->next;
        }
    }
    
    int dequeue(){
        if(!head){
          cout << "error" << endl;
          return -1;
        }
        int val = head->val;
        head = head->next;
        return val;
    }
}






