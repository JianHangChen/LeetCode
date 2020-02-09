// !!! my sol1, same as gy2
class MyQueue {
    stack<int> s1, s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {
    }
    
    
    // O(1)
    /** Push element x to the back of queue. */
    void push(int x) { 
        s1.push(x);
    }
    
    // O(n) worst, O(1) amortized
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!empty()){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top()); s1.pop();
                }
            }
            int top = s2.top(); s2.pop();
            return top;
        }        
        return -1;
    }
    
    
    // O(n)
    /** Get the front element. */
    int peek() {
        if(!empty()){
            if(s2.empty()){
                while(!s1.empty()){
                    s2.push(s1.top()); s1.pop();
                }
            } 
            return s2.top();
        }
        return -1;
    }
    
    // O(1)
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};




#amortized O(1) pop()


def __init__(self):
    """
    Initialize your data structure here.
    """
    self.stack1 = []
    self.stack2 = []
    self.front = None

# o(1)
def push(self, x: int) -> None:
    """
    Push element x to the back of queue.
    """
    if len(self.stack1) == 0:
        self.front = x
    self.stack1.append(x)

# O(n) worst, O(1) amortized
def pop(self) -> int:
    """
    Removes the element from in front of queue and returns that element.
    """
    if len(self.stack2) == 0:
        while self.stack1:
            self.stack2.append(self.stack1.pop())
    return self.stack2.pop()


# O(1)
def peek(self) -> int:
    """
    Get the front element.
    """
    if len(self.stack2) == 0:
        return self.front
    else:
        return self.stack2[-1]

# O(1)
def empty(self) -> bool:
    """
    Returns whether the queue is empty.
    """
    return len(self.stack1) == 0 and len(self.stack2) == 0
