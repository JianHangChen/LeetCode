//sol3, !!!!!!!, balanced tree, from grandyang
// O(NlogN)for N book, O(N)
class MyCalendar{
private:
  map<int, int> m;
public:
  MyCalendar(){

  }
  bool book(int start, int end){
    auto interval = m.lower_bound(start);

    if(interval != m.end() && end > interval->first) return false;
    
    if(interval!= m.begin() && prev(interval)->second > start) return false;


    m[start] = end;
    return true;
  }
};


class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = cal.lower_bound(start);
        if (it != cal.end() && it->first < end) return false;
        if (it != cal.begin() && prev(it)->second > start) return false;
        cal[start] = end;
        return true;
    }

private:
    map<int, int> cal;
};


// sol2, !! min max overlap , O(N^2), O(N)
class MyCalendar {
private:  
  vector<pair<int, int>> intervals; 
public:
    MyCalendar() {
        
    }
    
  bool book(int start, int end){
    for(pair<int, int> interval:intervals){\

      int small = max(start, interval.first);
      int big = min(end, interval.second);

      if(small < big) return false;

    }
    intervals.push_back({start, end});
    return true;  
  }
};


// sol1, O(N^2), O(N) for N book
class MyCalendar {
private:  
  vector<pair<int, int>> intervals; 
public:
    MyCalendar() {
        
    }
    
  bool book(int start, int end){
    for(pair<int, int> interval:intervals){\

      //! my, careful
      // if(interval.first <= start && start < interval.second || interval.first < end && end <= interval.second || start < interval.first && interval.second < end){
      //   return false;
      // }

      //sol1, from grandyang

      // if(interval.first >= start && interval.first < end) return false;
      // if(start >= interval.first && start < interval.second) return false;

      //from sol1, !! by demogan's law, no conflict: e <= start || end <= s -> e > start && end > s
      if(interval.second > start && end > interval.first) return false;


    }
    intervals.push_back({start, end});
    return true;  
  }
};








//sol4, binary tree, from sol2

class Node{
private:
  int s, e;
  Node* left, *right;
public:
  Node(int start, int end){
    s = start;
    e = end;
    left = NULL; right = NULL;
  }

  bool insert(Node& node){
    // cout << node.s << node.e << s << e << endl;
    if(node.s >= e){
      if(right == NULL){
        right = &node;
        return true;
      }
      return right->insert(node);
    }
    else if(node.e <= s){
      if(left == NULL){
        left = &node;
        return true;
      }
      return left->insert(node);
    }
    else{
      return false;
    }
  }
};

class MyCalendar{

private:
  Node* root;
public:
  MyCalendar(){
    root = NULL;
  }

  bool book(int start, int end){
    Node* node_ptr = new Node(start, end); //!!! shouldnot use Node node(start, end);
    if(root == NULL){
      root = node_ptr;
      return true;
    }
    bool ans = root->insert(*node_ptr);
    if(!ans) delete node_ptr;
    return ans;
  }

};
