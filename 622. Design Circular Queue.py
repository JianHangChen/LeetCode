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
