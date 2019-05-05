
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
