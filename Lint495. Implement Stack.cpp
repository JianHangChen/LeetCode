struct  myListNode{
    int val;
    myListNode* head;
    myListNode* next;
    
    myListNode(int initial) : val(initial), head(NULL), next(NULL){};
};

class Stack {

private:
    myListNode* head;
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        myListNode* cur = new myListNode(x);
        cur->next = head;
        head = cur;
    }

    /*
     * @return: nothing
     */
    void pop() {
        if(isEmpty()) return;
        else{
            myListNode* cur = head;
            head = head->next;
            delete cur;
            return;
        }
        
    }

    /*
     * @return: An integer
     */
    int top() {
        if(isEmpty()){cout << "error" << endl; return -1;}
        else{
            return head->val;
        }
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        return head == NULL;
    }
};
