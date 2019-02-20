class MyStack:
    
    # sol1, my, One queue
    # the application of collections.deque is from 
    # https://leetcode.com/problems/implement-stack-using-queues/discuss/62516/Concise-1-Queue-Java-C%2B%2B-Python

#     def __init__(self):
#         """
#         Initialize your data structure here.
#         """
#         self._queue = collections.deque()

#     def push(self, x: 'int') -> 'None':
#         """
#         Push element x onto stack.
#         """
#         self._queue.append(x)
#         for i in range(len(self._queue) - 1):
#             self._queue.append(self._queue.popleft())
        

#     def pop(self) -> 'int':
#         """
#         Removes the element on top of the stack and returns that element.
#         """
#         return self._queue.popleft()
        

#     def top(self) -> 'int':
#         """
#         Get the top element.
#         """
#         return self._queue[0]
        

#     def empty(self) -> 'bool':
#         """
#         Returns whether the stack is empty.
#         """
#         return len(self._queue) == 0

    # sol2, from solution, use two queue
    # pop O(n), push O(1)
#     def __init__(self):
#         """
#         Initialize your data structure here.
#         """
#         self.q1 = collections.deque()
#         self.q2 = collections.deque()
#         self._top = None
        

#     def push(self, x: 'int') -> 'None':
#         """
#         Push element x onto stack.
#         """
#         self._top = x
#         self.q1.append(x)
        

#     def pop(self) -> 'int':
#         """
#         Removes the element on top of the stack and returns that element.
#         """
#         for _ in range(len(self.q1) - 1):
#             self._top = self.q1.popleft()
#             self.q2.append(self._top)
#         temp = collections.deque()
#         temp = self.q2
#         self.q2 = self.q1
#         self.q1 = temp
#         return self.q2.popleft()
        

#     def top(self) -> 'int':
#         """
#         Get the top element.
#         """
#         return self._top
        

#     def empty(self) -> 'bool':
#         """
#         Returns whether the stack is empty.
#         """
#         return len(self.q1) == 0

    # sol3, from solution, use two queues
    # pop O(1), push O(n)
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.q1 = collections.deque()
        self.q2 = collections.deque()
        
        

    def push(self, x: 'int') -> 'None':
        """
        Push element x onto stack.
        """
        
        self.q2.append(x)
        while len(self.q1) != 0: # q1 is not empty
            self.q2.append( self.q1.popleft() )
        temp = collections.deque()
        temp = self.q2
        self.q2 = self.q1
        self.q1 = temp
        

    def pop(self) -> 'int':
        """
        Removes the element on top of the stack and returns that element.
        """
        return self.q1.popleft()
        

    def top(self) -> 'int':
        """
        Get the top element.
        """
        return self.q1[0]
        

    def empty(self) -> 'bool':
        """
        Returns whether the stack is empty.
        """
        return len(self.q1) == 0



# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()
