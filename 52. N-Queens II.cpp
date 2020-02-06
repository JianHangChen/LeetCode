//sol1, my, dfs, O(n!) O(n)
class Solution{
private:
    vector<bool> dale, hill, cols;
    int res = 0;
    int n;

public:
    int totalNQueens(int n){
        this->n = n;
        cols.resize(n, false);
        dale.resize(2*n - 1, false); hill = dale;

        backtracking(0);
        return res;

    }

    void backtracking(int row){
        if(n == row){
            res++;
            return;
        }

        for(int col = 0; col < n; col++){
            if(!cols[col] && !hill[col - row + n - 1] && !dale[col + row]){
                setQueen(row, col);
                backtracking(row + 1);
                removeQueen(row, col);
            }
        }
    }

    void setQueen(int row, int col){
        cols[col] = true;
        hill[col - row + n - 1] = true;
        dale[col + row] = true;
    }
    void removeQueen(int row, int col){
        cols[col] = false;
        hill[col - row + n - 1] = false;
        dale[col + row] = false;
    }   
    

};
