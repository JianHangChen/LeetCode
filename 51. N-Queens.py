def solveNQueens(self, n: int) -> List[List[str]]:

    #(0, 1) -> (0+1, 1+-1), (2, 1 +- 2), (3,  1 +- 3)


    def visited(x,y):
        return hill[y-x] or dale[x+y] or cols[y]

    def setQueen(x,y):
        queens.append(y)
        hill[y - x] = True
        dale[x + y] = True
        cols[y] = True

    def removeQueen(x,y):
        queens.pop()
        hill[y - x] = False
        dale[x + y] = False
        cols[y] = False

    def translate(queens: List[int]) -> List[str]:
        sol = []
        for i in queens:
            string = "." * i + "Q" + "." * (n - i - 1)
            sol.append(string)
        return sol

    def backtracking(row):
        if row == n:
            print(queens)
            res.append( translate(queens) )
            return

        for col in range(n):
            if not visited(row,col):
                setQueen(row, col)
                backtracking(row+1)
                removeQueen(row, col)




    dale = [False] * (2*n - 1)
    hill = [False] * (2*n - 1)
    res = []
    queens = []
    cols = [False] * n

    backtracking(0)

    return res
