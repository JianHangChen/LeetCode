

// 1. optional usage:

//     std::optional<int> deQueue(){
//         if(isEmpty()) return std::nullopt; 
//         int value = 0;
//         return value;
//     }
// callsite:
    // const auto op = m.deQueue();
    // if(op.has_value()) {
    //     std::cout << *op << std::endl;
    // }

// 2. template for array size
// template<typename SIZE> // use array in the private class
// private: 
//      std::array<int, SIZE> _arr;


class MyCircularQueue{
private:
    int _capacity;  // use _ for private member
    vector<int> _nums;
    int _head, _tail;
    int _len; // len : how many element actually in the queue
public:
    // Initializes the object with the size of the queue to be k.
    MyCircularQueue(int k): 
        _capacity(k),
        _head(0),
        _tail(0),
        _len(0)
    {
        _nums.resize(k, 0);
    }
     // Gets the front item from the queue. If the queue is empty, return -1.
    int Front() const {
        if(isEmpty()) return -1; 
        return _nums[_head]; // nums[1]
    };
    // Gets the last item from the queue. If the queue is empty, return -1.
    int Rear() const {
        if(isEmpty()) return -1;
        return _nums[(_tail - 1 + _capacity) % _capacity];
    } 
    
    // Inserts an element into the circular queue(enQueue from back). Return true if the operation is successful.
    bool enQueue(int value){
        if(isFull()) return false;
        _nums[_tail] = value;// nums[0] = -4
        _len++; // tail = 1, len = 4
        _tail = (_tail + 1) % _capacity;
        return true;
    }
    
    //Deletes an element from the circular queue(deQueue from front). Return true if the operation is successful.
    bool deQueue(){
        if(isEmpty()) return false; // std::nullopt; 
        
        int value = Front();
        _head = (_head + 1) % _capacity; //1
        _len--; // 1->0
        return true;
    }

    //Checks whether the circular queue is empty or not.
    bool isEmpty() const {
        return _len == 0;
    }
    //Checks whether the circular queue is full or not.
    bool isFull() const {
        return _len == _capacity;
    }
};


class MyCircularQueue:

    def __init__(self, k: 'int'):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        """
        self.head = None
        self.tail = None
        self.queue = [None]*k
        self.k = k
        

    def enQueue(self, value: 'int') -> 'bool':
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            self.head = self.tail = 0
        else:
            if self.isFull():
                return False
            self.tail = (self.tail+1)%self.k
        self.queue[self.tail] = value
        return True

    def deQueue(self) -> 'bool':
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        """
        if self.isEmpty():
            return False
        if self.head == self.tail:
            self.head = self.tail = None
        else:
            self.head = (self.head + 1) % self.k 
        return True
        

    def Front(self) -> 'int':
        """
        Get the front item from the queue.
        """
        if self.head is None:
            return -1
        else:
            return self.queue[self.head]

    def Rear(self) -> 'int':
        """
        Get the last item from the queue.
        """
        if self.tail is None:
            return -1
        else:
            return self.queue[self.tail]

    def isEmpty(self) -> 'bool':
        """
        Checks whether the circular queue is empty or not.
        """
        if self.tail is None or self.head is None:
            return True
        else:
            return False
        

    def isFull(self) -> 'bool':
        """
        Checks whether the circular queue is full or not.
        """
        
        if self.tail is not None and self.head is not None and (self.tail+1)%self.k == self.head:
            return True
        else:
            return False

# Your MyCircularQueue object will be instantiated and called as such:
# obj = MyCircularQueue(k)
# param_1 = obj.enQueue(value)
# param_2 = obj.deQueue()
# param_3 = obj.Front()
# param_4 = obj.Rear()
# param_5 = obj.isEmpty()
# param_6 = obj.isFull()
