    # SOL1, BFS
    #O(r*c)
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        def bfs():
            while q:
                i, j, step = q.popleft()
                if result[i][j] > step:
                    result[i][j] = step
                    if i + 1 < m:
                        q.append((i+1,j, step + 1))
                    if i - 1 >= 0:
                        q.append((i-1,j, step + 1))
                    if j + 1 < n:
                        q.append((i, j + 1, step + 1))
                    if j - 1 >= 0:
                        q.append((i,j-1, step + 1))
        m = len(matrix)
        n = len(matrix[0])
        result = [ [float("inf")]* n for _ in range(m) ]
        q = collections.deque()
        
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    q.append((i,j, 0))
        bfs()
        return result
    
    # sol2, dp
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        result = [[m+n]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    result[i][j] = 0
                else:
                    if i > 0:
                        result[i][j] = min(result[i-1][j]+1, result[i][j])
                    if j > 0:
                        result[i][j] = min(result[i][j-1]+1, result[i][j])
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if matrix[i][j] == 0:
                    result[i][j] = 0
                else:
                    if i+1<m:
                        result[i][j] = min(result[i+1][j]+1, result[i][j])
                    if j+1<n:
                        result[i][j] = min(result[i][j+1]+1, result[i][j])
        return result
        
    # sol2.1, dp
    # With only O(1) space complexity
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            for j in range(n):
                if matrix[i][j]:
                    top = matrix[i-1][j] if i > 0 else m + n
                    left = matrix[i][j-1] if j > 0 else m + n
                    matrix[i][j] = min(top+1, left+1)
                    
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if matrix[i][j]:
                    bottom = matrix[i+1][j] if i + 1 < m else m + n
                    right = matrix[i][j + 1] if j + 1 < n else m + n
                    matrix[i][j] = min(bottom + 1, right + 1, matrix[i][j])
        
        return matrix
