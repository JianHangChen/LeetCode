
#leetcode: 346.Moving Average from Data Stream 
#lintcode: 642. Moving Average from Data Stream


# sol1, my, use queue
# import queue
# class MovingAverage:
#     """
#     @param: size: An integer
#     """
#     def __init__(self, size):
#         self.sum = 0
#         self.q = queue.Queue(size)

#     """
#     @param: val: An integer
#     @return:  
#     """
#     def next(self, val):
#         q = self.q
#         if q.full():
#             self.sum = self.sum - q.get() + val
#         else:
#             self.sum = self.sum + val
#         q.put(val)
        
#         return self.sum / q.qsize()


# sol2, use collections.deque
# class MovingAverage:
#     """
#     @param: size: An integer
#     """
#     def __init__(self, size):
#         self.sum = 0
#         self.q = collections.deque([],size)

#     """
#     @param: val: An integer
#     @return:  
#     """
#     def next(self, val):
#         q = self.q
#         if len(q) == q.maxlen:
#             self.sum = self.sum - q.popleft() + val
#         else:
#             self.sum = self.sum + val
#         q.append(val)
        
#         return self.sum / len(q)

# sol3, not using Queue
# from https://www.jiuzhang.com/solution/moving-average-from-data-stream/#tag-highlight
class MovingAverage:
    """
    @param: size: An integer
    """
    def __init__(self, size):
        self.id = 0
        self.sum = [0]*(size+1)
        self.size = size

    """
    @param: val: An integer
    @return:  
    """
    def mod(self, id):
        
        return id % (self.size+1)
        
    def next(self, val):
        self.id += 1
        size = self.size
        mod = self.mod
        self.sum[mod(self.id)] = self.sum[mod(self.id-1)] + val
        if self.id > size:
            return (self.sum[mod(self.id)] - self.sum[mod(self.id - size)])/size
        else:
            return self.sum[mod(self.id)]/self.id
        




# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param = obj.next(val)
