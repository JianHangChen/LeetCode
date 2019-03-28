
# sol1
class NestedIterator(object):
    #check nestedList = []

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.stack = []
        self.cur = nestedList
        self.idx = 0
        

    def next(self):
        """
        :rtype: int
        """
        
        result = self.cur[self.idx].getInteger()
        if self.idx < len(self.cur) - 1:
            self.idx += 1
        else:
            self.cur = []
        return result

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.cur == []:
            if self.stack != []:
                self.cur, self.idx = self.stack.pop()
            else:
                return False
        
        if self.cur[self.idx].isInteger():
            return True
        
        else:
            if self.idx + 1 < len(self.cur):
                self.stack.append((self.cur, self.idx + 1))
                
            self.cur = self.cur[self.idx].getList()
            self.idx = 0
            
            return self.hasNext()        

# sol2
class NestedIterator(object):
    #check nestedList = []

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.stack = [[nestedList,0]]
        

    def next(self):
        """
        :rtype: int
        """
        stack = self.stack
        cur, idx = stack[-1]
        stack[-1][-1] += 1
        return cur[idx]

    def hasNext(self):
        """
        :rtype: bool
        """
        stack = self.stack
        
        while stack:
            cur, idx = stack[-1]
            # if cur == []:
            #     return False
            if idx >= len(cur):
                stack.pop()
            else:
                if cur[idx].isInteger():
                    return True
                else:  # cur[idx] not integer but list
                    stack[-1][-1] += 1
                    stack.append([cur[idx].getList(),0])
        return False

# sol3, use original nestedList array

class NestedIterator(object):
    #check nestedList = []

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.nestedList = nestedList[::-1]

    def next(self):
        """
        :rtype: int
        """
        return self.nestedList.pop()


    def hasNext(self):
        """
        :rtype: bool
        """
        nestedList = self.nestedList
        if len( nestedList) == 0:
            return False
        if nestedList[-1].isInteger():
            return True
        else:
            last = nestedList.pop().getList()
            if last != []:
                for v in last[::-1]:
                    nestedList.append(v)
            return self.hasNext()


# sol4, similar to 3, no recursion

class NestedIterator(object):
    #check nestedList = []

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.nestedList = nestedList[::-1]

    def next(self):
        """
        :rtype: int
        """
        return self.nestedList.pop()


    def hasNext(self):
        """
        :rtype: bool
        """

        while self.nestedList:
            last = self.nestedList[-1]
            if last.isInteger():
                return True
            else:
                self.nestedList = self.nestedList[:-1] + last.getList()[::-1]
        return False
