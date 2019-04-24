https://leetcode.com/problems/walls-and-gates/
https://www.lintcode.com/problem/walls-and-gates/

import collections
class Solution:
    """
    @param rooms: m x n 2D grid
    @return: nothing
    """
    # test m = 0 or n = 0
    
    # sol1, my
    def wallsAndGates(self, rooms):
        m = len(rooms)
        n = len(rooms[0])
        
        def getValidNeighboours(i,j,step):
            neighbours = []
            for u,v in [(i-1,j), (i+1,j), (i, j-1), (i, j+1)]:
                if  (0 <= u < m) and (0 <= v < n) and (rooms[u][v] > step):
                    neighbours.append((u,v))
            return neighbours
            
        def bfs(i, j, q):
            q.append((i,j))
            step = -1
            while q:
                step += 1
                l = len(q)
                for _ in range(l):
                    
                    i, j = q.popleft()
                    if step < rooms[i][j]:
                        rooms[i][j] = step
                    neighbours = getValidNeighboours(i,j,step)
                    for neighbour in neighbours:
                        q.append(neighbour)
                
                #print(q)
                    
        
        
        q = collections.deque([], m * n)
        
        
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    bfs(i,j, q)
                    
    # sol2, my, put candidates in queue                
    def wallsAndGates(self, rooms):
        m = len(rooms)
        n = len(rooms[0])
        
        def getValidNeighboours(i,j,step):
            neighbours = []
            for u,v in [(i-1,j), (i+1,j), (i, j-1), (i, j+1)]:
                if  (0 <= u < m) and (0 <= v < n) and (rooms[u][v] > step):
                    neighbours.append((u,v))
            return neighbours
            
        def bfs(q):
            step = -1
            while q:
                step += 1
                l = len(q)
                for _ in range(l):
                    
                    i, j = q.popleft()
                    if step <= rooms[i][j]:
                        rooms[i][j] = step
                        neighbours = getValidNeighboours(i,j,step)
                        for neighbour in neighbours:
                            q.append(neighbour)
                
                #print(q)
                    
        
        
        q = collections.deque([], m * n)
        
        
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == 0:
                    q.append((i,j))
                    
        bfs(q)
