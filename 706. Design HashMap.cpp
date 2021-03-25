// // !!! sol1.1, my, single linkedlist, O(n/l), O(l+m)
// // n is total number of possible key
// // m is the unique keys inserted


struct Node{
    Node* next;
    int val;
    int key;
    Node(int x, int k){
        val = x;
        key = k;
        next = NULL;
    }
};

class MyHashMap {
private:
    int getHash(int key){
        return (key%capacity + capacity) % capacity;
    }
public:
    vector<Node*> v;
    int capacity = 1e4;
    /** Initialize your data structure here. */
    MyHashMap() {
        v.resize(capacity, NULL);        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashkey = getHash(key);
        
        if(get(key) == -1){
            Node* newNode = new Node(value, key);
            newNode->next = v[hashkey];
            v[hashkey] = newNode;
        }
        else{
            Node* cur = v[hashkey];
            while(cur != NULL){
                if(cur->key == key){
                    cur->val = value;
                    return;
                }
                cur = cur->next;
            }
        }        
    }    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashkey = getHash(key);
        Node* cur = v[hashkey];
        
        while(cur){
            if(cur->key == key){
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {        
        int hashkey = getHash(key);
        Node* cur = v[hashkey];
        if(!cur) return;
        
        if(cur->key == key){ // head is the key
            v[hashkey] = cur->next;
            delete cur;
        }
        else{
            Node* pre = cur;
            cur = cur->next;
            
            while(cur){
                if(cur->key == key){
                    pre->next = cur->next;
                    delete cur;
                    return;
                }
                pre = cur;
                cur = cur->next;
            }            
        }
        return;
        
    }
};





// // ! sol1, my, double linkedlist, O(n/l), O(l+m)
// // n is total number of possible key
// // m is the unique keys inserted


struct Node{
    Node* next;
    Node* pre;
    int val;
    int key;
    Node(int x, int k){
        val = x;
        key = k;
        next = NULL;
        pre = NULL;
    }
};

class MyHashMap {
private:
    int getHash(int key){
        return key % l;
    }
public:
    vector<Node> v;
    int l = 1e4;
    /** Initialize your data structure here. */
    MyHashMap() {
        v.resize(l, Node(-1, -1));        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int hashkey = getHash(key);
        Node* dummy = &v[hashkey];
        Node* cur = dummy;
        
        
        while(cur != NULL){
            if(cur->key == key){
                cur->val = value;
                return;
            }
            cur = cur->next;
        }
        
        Node* newNode = new Node(value, key);
        if(dummy->next) dummy->next->pre = newNode;
        newNode->next = dummy->next;
        dummy->next = newNode;
        newNode->pre = dummy;        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int hashkey = getHash(key);
        Node* dummy = &v[hashkey];
        Node* cur = dummy;
        
        while(cur){
            if(cur->key == key){
                return cur->val;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int hashkey = getHash(key);
        Node* dummy = &v[hashkey];
        Node* cur = dummy;
        
        while(cur){
            if(cur->key == key){
                cur->pre->next = cur->next;
                if(cur->next) cur->next->pre = cur->pre;
                return;
            }
            cur = cur->next;
        }
        return;
        
    }
};

