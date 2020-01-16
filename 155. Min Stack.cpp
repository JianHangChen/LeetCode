
// !!!! sol2, two stack, by grandyang
// O(1) push, O(1) pop, O(1) top, O(1) getMin

class MinStack{
private:
    stack<int> s1, s2;
    
    
public:
    MinStack(){}
    
    void push(int x){
        s1.push(x);
        if(s2.empty() || x <= s2.top()){
            s2.push(x);
        }
    }
    
    
    void pop(){
        if(s1.empty()) return;
        if(!s2.empty() && s1.top() == s2.top()) s2.pop();
        s1.pop();
    }
    
    int top(){
        return s1.top();
    }
    int getMin(){
        return s2.top();
    }
    
};


// my sol1, O(1) push, O(n) pop, O(1) top, O(1) getMin
class MinStack{
private:
  vector<int> s;
  int mini = INT_MAX;
public:
  MinStack(){
    return;
  }
  
  void push(int x){
    if(x < mini) mini = x;
    s.push_back(x);
  }
  
  void pop(){
    int t = top();
    s.pop_back();
    if(t == mini){
      mini = INT_MAX;
      for(auto num:s){
        mini = min(num, mini);
      }
    }
  }
  
  int top(){
    return s.back();
  }
  
  int getMin(){
    return mini;
  }
  
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
