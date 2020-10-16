
//!!!! sol2,  use list as a double liked list O(1), O(1)
// gy +
// https://leetcode.com/problems/lru-cache/discuss/45976/C%2B%2B11-code-74ms-Hash-table-%2B-List
// #inlcude <list>
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



sol2.1 use erase and push to update. not splice
class LRUCache{
private:
    int CAP;
    unordered_map<int, list<vector<int>>::iterator> m;
    
    list<vector<int>> lru; // each element: key, value
public:
    LRUCache(int capacity){
        CAP = capacity;
    }
    
    int get(int key){
        if(m.count(key) == 0) return -1;
        int value = (*m[key])[1];
        lru.erase(m[key]);
        lru.push_front({key,value});

        m[key] = lru.begin();
        
        return value;
    }
    
    void put(int key, int value){
        if(m.count(key) > 0){
            lru.erase(m[key]); //remove the key in list
        }
        else{ // delete the least recently used key
            if(m.size() >= CAP){
                m.erase(lru.back()[0]);
                lru.pop_back();
            }
        }
        lru.push_front({key, value}); // update the list
        m[key] = lru.begin();

    }
    
};


! sol1, using double linked list, from sol2, O(1), O(1) for get and put
class Node{
public:
    int key, val;
    Node(int k, int x):key(k), val(x){}
    Node* next, *prev;  
};



class LRUCache{
private:
    int CAP;
    int count;
    unordered_map<int, Node*> m;
    Node* head, * tail;
public:
    LRUCache(int capacity){
        CAP = capacity;
        count = 0;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void add(Node* node){
        node->next = tail;
        node->prev = tail->prev;
        node->prev->next = node;
        tail->prev = node;        
    }
    
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;        
    }    
    
    
    int get(int key){
        if(m.count(key) == 0) return -1;
        
        int value = m[key]->val;
        
        remove(m[key]);
        
        m[key] = new Node(key, value);
        add(m[key]);
        return value;
    }
    
    void put(int key, int value){
        if(m.count(key) > 0){
            remove(m[key]); 
            
            //update the list
            m[key] = new Node(key, value);
            add(m[key]);
        }
        else{ // delete the least recently used key
            if(count == CAP){
                m.erase(head->next->key);
                remove(head->next);
                count--;
            }
            m[key] = new Node(key, value);
            add(m[key]);
            
            count++;
        }
    }
};
