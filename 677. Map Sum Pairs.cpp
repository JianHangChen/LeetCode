


// sol3,!!!! trie(prefix tree) + hash, from sol3
// insert O(P), sum O(P). P is the length of string
// space O(sum(P))
class Node{
public:
    vector<Node*> next;
    int val;
    Node(){
        val = 0;
        next.resize(256, NULL);
    }
};


class MapSum {
private:
    Node* root;
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        int delta = val - m[key];
        m[key] = val;
        
        Node* cur = root;
        cur->val += delta;
        
        for(auto c:key){            
            if(cur->next[c] == NULL) cur->next[c] = new Node();
            cur = cur->next[c];
            cur->val += delta;
        }        
    }
    
    
    int sum(string prefix) {
        Node* cur = root;
        for(auto c:prefix){
            if(cur->next[c]) cur = cur->next[c];
            else return 0;
        }
        return cur->val;
    }
};




// !sol4, binary search, from gy

class MapSum{
private:
  map<string, int> m;
public:
  MapSum(){
    
  }
  void insert(string key, int val){
    m[key] = val;
  }

  int sum(string prefix){
    int res = 0;
    auto iter = m.lower_bound(prefix);
    while(iter != m.end()){
      for(int i = 0; i < prefix.size(); i++){
        if(prefix[i] != iter->first[i]){
          return res;
        }
      }
      res += iter->second;  
      iter++;
    }
    return res;
  }
};


// sol2, prefix hashmap, from sol2
// sum O(1), insert O(P^2)
// O(sum(P^2))

class MapSum{
private:
  map<string, int> m;
  map<string, int> score;
public:
  MapSum(){}
  void insert(string key, int val){

    int delta = val - m[key];
    m[key] = val;
    for(int i  = 1; i <= key.size(); i++){
      score[key.substr(0, i)] += delta;  // substr
    }
  }

  int sum(string prefix){
    return score[prefix];
  }

};



// sol1, my brute force

// O(1) insert, O(N*P) sum
// O(sum(P)) 
class MapSum {

private:
  map<string, int> m;
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int res = 0;
        for(auto iter:m){
          string key = iter.first;
          
          int i = 0;
          while( i < prefix.size()){
            if(i >= key.size()) break;
            if(prefix[i] != key[i]) break;
            i++;
          }
          if(i == prefix.size()) res+= iter.second;
        }
        return res;
    }
};
