



// !!!! sol2, O(mn), O(1), inplace, sol2, gy
class Solution {
private:
    vector<int> dirs = {-1, 0, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m <= 0) return;
        int n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int count = 0;
                for(int a:dirs){
                    for(int b:dirs){
                        if(!(a==0 && b==0)){
                            int new_i = i + a, new_j = j + b;
                            if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                                if(board[new_i][new_j] >= 1){
                                    count++;                                    
                                }
                            }
                        }
                    }
                }
                if(board[i][j] == 0){ // 0 -> 1      -1
                    if(count == 3){
                        board[i][j] = -1;
                    }
                }
                else{
                    if(!(count == 2 || count == 3)){  // 1 -> 0   2
                        board[i][j] = 2;
                    }
                }

            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 2){
                    board[i][j] = 0;
                }
                if(board[i][j] == -1){
                    board[i][j] = 1;
                }
            }
        }

        return;
    }


};





// !!! sol3, follow up, from sol3

1. computationally impossible to iterate matrix
2. store the matrix in memory
3. only few live but rest are dead. sparse matrix

// !!! sol3.1 sparse solution
class Solution {
private:
    vector<int> dirs = {-1, 0, 1};
    int m,n;
public:


     set<vector<int>> sparseGameOfLife(set<vector<int>>& live){
        set<vector<int>> new_live;

        map<vector<int>, int> appear;

        for(vector<int> pair:live){
            int i = pair[0], j = pair[1];
            for(auto di:dirs){
                for(auto dj:dirs){
                    if(!(di==0 && dj==0)){
                        int x = i + di, y = j + dj;
                        if(x >= 0 && x < m && y >= 0 && y < n)
                            appear[{x,y}]++;
                    }
                }
            }
        }

        for(auto item:appear){
            if(item.second == 3 || item.second == 2 && live.count(item.first)==1 ){
                new_live.insert(item.first);
            }
        }
        return new_live;
    }


    void gameOfLife(vector<vector<int>>& board) {
        set<vector<int>> live;
        m = board.size(); if(m == 0) return;
        n = board[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 1)
                    live.insert({i,j});
            }
        }

        set<vector<int>> new_live = sparseGameOfLife(live);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(new_live.count( {i,j} ) > 0){
                    board[i][j] = 1;
                }
                else{
                    board[i][j] = 0;
                }
            }
        }
    }
};





// ! sol1.1, O(mn), O(mn), better copy based on sol1
class Solution {
private:
    vector<int> dirs = {-1, 0, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m <= 0) return;
        int n = board[0].size();

        vector<vector<int>> copy_board(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                copy_board[i][j] = board[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isLife(i,j,copy_board, m, n))
                    board[i][j] = 1;
                else{
                    board[i][j] = 0;
                }
            }

        }

        return;
    }

    bool isLife(int i, int j, vector<vector<int>>& board, int m, int n){
        
        int count = 0;

        for(int a:dirs){
            for(int b:dirs){
                if(!(a == 0 && b == 0)){
                    int new_i = i + a, new_j = j + b;
                    if( new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                        count += board[new_i][new_j];
                    }                    
                }
            }
        }

        if(board[i][j] == 0){ // dead
            if(count == 3) return true;
        }
        else{ // live
            if(count == 2 || count == 3) return true;            
        }
        return false;
    }
};


// my sol1, O(mn), O(mn)
class Solution {
private:
    vector<vector<int>> dirs = {{1,1}, {1,0}, {1,-1}, {0, 1}, {0,-1}, {-1,1},{-1,0},{-1,-1}};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if(m <= 0) return;
        int n = board[0].size();

        vector<vector<int>> new_board(m, vector<int> (n, 0));

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(isLife(i, j, board, m , n)){
                    new_board[i][j] = 1;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                    board[i][j] = new_board[i][j];
            }
        }

        return;
    }

    bool isLife(int i, int j, vector<vector<int>>& board, int m, int n){
        
        int count = 0;
        if(board[i][j] == 0){ // dead
            for(auto dir:dirs){
                int new_i = i + dir[0], new_j = j + dir[1];
                if( new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    count += board[new_i][new_j];
                }
            }
            if(count == 3) return true;
        }
        else{ // live
            for(auto dir:dirs){
                int new_i = i + dir[0], new_j = j + dir[1];
                if( new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    count += board[new_i][new_j];
                }
            }
            if(count == 2 || count == 3) return true;            
        }
        return false;
    }
};


