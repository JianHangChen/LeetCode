// sol1.1, similar but easier implementation
class Solution {
public:
    int m, n;
    unordered_set<string> visited;
    queue<string> q;
    vector<vector<int>> dirs = {{0, 1},  {0, -1}, {1, 0}, {-1, 0}};
    int slidingPuzzle(vector<vector<int>>& board){
        m = board.size(), n = board[0].size();
        string boardStr = BoardToString(board);
        string destination = "123450";
        if(boardStr == destination) return 0;
        
        q.push(boardStr);
        visited.insert(boardStr);
        int move = 0;
        while(!q.empty()){
            move++;
            for(int k = q.size(); k > 0 ; k--){
                string cur = q.front(); q.pop();
                for(auto& nei:GetNext(cur)){
                    if(visited.count(nei) > 0) continue;
                    if(nei == destination) return move;
                    q.push(nei);
                    visited.insert(nei);
                }
            }
        }
        return -1;
    }
    vector<string> GetNext(string& cur){
        vector<string> res;
        int idx = cur.find("0");
        int i = idx / n, j = idx % n;
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            int newidx = x * n + y;
            swap(cur[newidx], cur[idx]);
            res.push_back(cur);
            swap(cur[newidx], cur[idx]);
        }   
        return res;
    }
    string BoardToString(vector<vector<int>>& board){
        string res = "";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res.push_back('0' + board[i][j]);
            }
        }
        return res;
    }
};

// sol1, O((mn)!mn),  O((mn)!mn)
// // solved
// //[1,2,3]
// //[4,5,0]

// // initial
// // [1,2,3]
// // [4,0,5]
class Solution {
public:
    set<vector<vector<int>>> visited;
    int m = 2, n = 3;
    vector<vector<int>> finalBoard = {{1,2,3}, {4, 5, 0}};
    int slidingPuzzle(vector<vector<int>>& board){
        queue<pair<vector<vector<int>>, vector<int>> > q;
        auto zero = FindZero(board);
        q.push({board, zero});
        visited.insert(board);
        
        int move = 0;
        if(board == finalBoard) return move;
        while(!q.empty()){
            move++;
            for(int k = q.size(); k > 0; k--){
                auto cur = q.front(); q.pop();
                for(auto& nei:GetNext(cur.first, cur.second)){
                    if(nei.first == finalBoard) return move;
                    visited.insert(nei.first);
                    q.push(nei);
                }
            }
        }
        
        return -1;
    }
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> FindZero(vector<vector<int>>& board){
        // find 0
        int i, j;
        for(int a = 0; a < m; a++){
            for(int b = 0; b < n; b++){
                if(board[a][b] == 0){
                    i = a; j = b;
                }// don't use break!
            }
        }
        return {i, j};
    }
    vector<pair<vector<vector<int>>,vector<int>>> GetNext(vector<vector<int>>& board, vector<int>& zero){
        vector<pair<vector<vector<int>>,vector<int>>> res;
        int i = zero[0], j = zero[1];
        // if the direction valid swap 4 direction
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(x < 0 || x >= m || y < 0 || y >= n) continue;
            auto newBoard = board;
            swap(newBoard[i][j], newBoard[x][y]);
            if(visited.count(newBoard) > 0){
                continue;
            }
            res.push_back({newBoard, {x, y}});
        }
        return res;
    }
};
