import collections
class Solution:
    
    # sol1, bfs
    def openLock(self, deadends: List[str], target: str) -> int:
        def getValidNeighbours(cur, visited):
            neighbours = []
            for i in range(4):
                if cur[i] == "9":
                    new_digit1 = 0
                else:
                    new_digit1 = int(cur[i]) + 1
                    
                if cur[i] == "0":
                    new_digit2 = 9
                else:
                    new_digit2 = int(cur[i]) - 1
                neighbour1 = cur[:i] + str(new_digit1) + cur[i+1:]
                neighbour2 = cur[:i] + str(new_digit2) + cur[i+1:]
                if neighbour1 not in visited:
                    visited.add(neighbour1)
                    neighbours.append(neighbour1)
                if neighbour2 not in visited:
                    visited.add(neighbour2)
                    neighbours.append(neighbour2)
            return neighbours
            
        def dfs(q, visited):
            count = -1
            while q:
                count += 1
                for i in range(len(q)):
                    
                    cur = q.popleft()
                    if cur == "0000":
                        return count
                    neighbours = getValidNeighbours(cur, visited)
                    for neighbour in neighbours:
                        q.append(neighbour)
            return -1
        
        q = collections.deque([], 10000)
        visited = set(deadends)
        q.append(target)
        return dfs(q, visited)

    #!!! sol2, two-end, bidirectional search
    def openLock(self, deadends: List[str], target: str) -> int:
        def addValidNeighbours(cur, dead, new):
            for i in range(4):
                neighbour1 = cur[:i] + str( (int(cur[i]) + 1)%10 ) + cur[i+1:]
                neighbour2 = cur[:i] + str( (int(cur[i]) - 1)%10 ) + cur[i+1:]
                new.add(neighbour1)
                new.add(neighbour2)            
        

        begin = set(["0000"])
        end = set([target])
        visited = set(deadends)
        
        count = 0
        while begin:
            
            if len(begin) > len(end):
                begin,end = end, begin
            
            new = set()
            for item in begin:
                if item in visited:
                    continue
                else:
                    visited.add(item)
                if item in end:
                    return count
                addValidNeighbours(item, visited, new)
            begin = new
            count += 1
        
        return -1

    
