import collections
class Solution:
    # test m = 0 or n = 0
    def numIslands(self, grid: List[List[str]]) -> int:
        
        def getValidNeighbours(i, j, visited):
            neighbours = []
            for u, v in [(i, j+1), (i, j - 1), (i+1, j), (i-1, j)]:
                if (0 <= u < m) and (0 <= v < n) and (grid[u][v] == "1") and ((u, v) not in visited):
                    neighbours.append((u, v))
            return neighbours
        
        def bfs(q, visited):
            while q:
                i,j = q.popleft()
                neighbours = getValidNeighbours(i,j, visited)
                for neighbour in neighbours:
                    visited.add(neighbour)
                    q.append(neighbour)
        
        visited = set()
        m = len(grid)
        if m == 0:
            return 0
        n = len(grid[0])
        
        
        count = 0
        q = collections.deque([],m*n)
        
        for i in range(m):
            for j in range(n):
                if grid[i][j] == "1" and (i, j) not in visited:
                    count += 1
                    q.append((i,j))
                    visited.add((i, j))
                    bfs(q, visited)
        return count
