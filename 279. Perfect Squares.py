import collections
class Solution:
    
    # bfs use set
    def numSquares(self, n: int) -> int:
        squares = []
        i = 1
        while i * i <= n:
            squares.append(i * i)
            i += 1
            
        ps = 1
        q = set([0])
        while q:
            new = set()
            for cur in q:
                for square in squares:
                    s = square + cur
                    if s == n:
                        return ps
                    if s > n: # squares are increasing, no need to add s > n
                        break
                    else:
                        new.add(s)
            q = new
            ps += 1
        return -1
        
    # sol2, static dp
    _dp = [0]
    def numSquares(self, n: int) -> int:
        dp = self._dp
        while len(dp) <= n:
            j = len(dp)
            ps = sys.maxsize
            i = 1
            while i * i <= j:
                ps = min(ps, dp[j - i * i] + 1)
                i += 1
            dp.append(ps)
        return dp[n]
