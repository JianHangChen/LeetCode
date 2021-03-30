
//!!! sol2, iteratively, from sol3, O(n), O(1)
class Solution {
public:
    
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* cur = head, *next, *newhead;
        while(cur){
            Node* newcur = new Node(cur->val);
            newcur->next = cur->next;
            cur->next = newcur;
            cur = newcur->next;
        }
        
        cur = head; newhead = cur->next;
        while(cur){
            Node* newcur = cur->next;
            if(cur->random) newcur->random = cur->random->next; // carefull!, you cannot change the random and deweav at the same time            
            cur = newcur->next;
        }
        
        cur = head;
        while(cur){
            Node* newcur = cur->next;
            cur->next = newcur->next;
            if(newcur->next) newcur->next = newcur->next->next;
            cur = cur->next;
        }
        
        return newhead;        
    }
};
//!! sol1, my, recursive, O(n), O(n)
class Solution {
public:
    unordered_map<Node*, Node*> m; // old->newNode
    
    Node* copyRandomList(Node* head) {
        Node* newhead = createNode(head);
        updateRand(head);
        return newhead;
    }
    void updateRand(Node* cur){
        if(!cur) return;        
        m[cur]->random = m[cur->random];
        updateRand(cur->next);
    }
    Node* createNode(Node* cur){
        if(!cur) return NULL;
        m[cur] = new Node(cur->val);
        m[cur]->next = createNode(cur->next);
            
        return m[cur];
    }
};
