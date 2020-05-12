
//!!!! sol2,  use list as a double liked list O(1), O(1)
// gy +
// https://leetcode.com/problems/lru-cache/discuss/45976/C%2B%2B11-code-74ms-Hash-table-%2B-List
#inlcude <list>
class LRUCache {
public:
    unordered_map<int, list<vector<int> >::iterator > m;
    list<vector<int>> lru; // key, value
    int CAP;
    
    LRUCache(int capacity){
        CAP = capacity;
    }
    
    int get(int key) {
        if(m.count(key) == 0) return -1;
        lru.splice(lru.begin(), lru, m[key]); // update the key to the front of d linked list
        return lru.front()[1];
    }
    void put(int key, int value){
        if(m.count(key) > 0){ // if exist key
            lru.splice(lru.begin(), lru, m[key]); // update the key to the front of d linked list
            lru.front()[1] = value;// update the value
        }
        else{
            if(lru.size() >= CAP){ // if cannot update and exceed cap
                m.erase(lru.back()[0]);
                lru.pop_back();
            }
            lru.push_front({key, value});
            m[key] = lru.begin();
        }
        
    }
};

//! sol1, using double linked list, from sol2, O(1), O(1) for get and put
class dNode{
public:
    int key, val;
    dNode* next, *prev;
    dNode(int k, int v) : key(k), val(v){};
};

class LRUCache {
public:
    int CAP;
    int size = 0;
    unordered_map<int, dNode*> m;
    dNode* head , * tail;
        

    
    LRUCache(int capacity) {
        CAP = capacity;
        head = new dNode(-1, -1);
        tail = new dNode(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    void remove(dNode* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;        
    }
    
    void add(dNode* node){
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    
    int get(int key) {
        if(m.count(key) == 0) return -1;
        dNode* node = m[key];
        int val = node->val;
        remove(node);
        add(node);
        return val;
    }
    
    void put(int key, int value) {

        if(m.count(key)){
            m[key]->val = value;
            remove(m[key]);
            add(m[key]); // move to the head
        }
        else{
            if(size >= CAP){
                m.erase(tail->prev->key);
                remove(tail->prev);
            }
            else{
                size++;
            }
                        
            dNode* node = new dNode(key, value);
            m[key] = node;
            add(node);        
        }
    }
};
