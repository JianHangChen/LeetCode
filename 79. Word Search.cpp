
// sol1, my dfs, O(mn* 4^L), O(L)
class Solution {
    
public:
    int m, n;
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); n = board[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(match(board, 0, word, i, j)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool match(vector<vector<char>>& board, int k, string& word, int i , int j){
        if(board[i][j] != word[k]) return false;
        if(k == word.size() - 1) return true;
        
        board[i][j] = '0';
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(x >= 0 && x < m && y >= 0 && y < n){
                if(match(board, k+1, word, x, y)) return true;
            }
        }
        board[i][j] = word[k];
        return false;
    }
};
