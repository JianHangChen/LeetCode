
// sol1, backtracking O(n!), O(N) space if res is not into space consideration
// //read this:
    //https://leetcode.com/problems/n-queens/discuss/19808/Accepted-4ms-c%2B%2B-solution-use-backtracking-and-bitmask-easy-understand.

class Solution{
public:
    vector<bool> dale, hill, cols;
    vector<vector<string>> res;
    vector<string> queens;

    vector<vector<string>> solveNQueens(int n){
        dale.resize(2 * n - 1, false); hill = dale;
        cols.resize(n, false);
        queens.resize(n, string(n, '.'));
        backtracking(0);
        return res;
    }
    void backtracking(int row){
        int n = queens.size();
        if(row == n){
            res.push_back(queens); return;
        }
        for(int col = 0; col < n; col++){
            if(!cols[col] && !dale[row + col] && !hill[col - row + n - 1]){
                setQueen(row, col, n);
                backtracking(row + 1);
                removeQueen(row, col, n);
            }
        }
    }

    void setQueen(int row, int col, int n){
        queens[row][col] = 'Q';
        cols[col] = true;
        hill[col - row + n - 1] = true;
        dale[row + col] = true;
    }

    void removeQueen(int row, int col, int n){
        queens[row][col] = '.';
        cols[col] = false;
        hill[col - row + n - 1] = false;
        dale[row + col] = false;
    }

};




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
