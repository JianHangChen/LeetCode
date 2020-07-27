
//!!! sol1, from gy1, need more practice, O(mn*4*3^(L-1)), O(word.size())
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    struct tNode{
        string str;
        tNode* next[26];
        tNode():str(""){
            for(int i = 0; i < 26; i++) next[i] = NULL; // !!!
        };
    };
    struct Tries{
        tNode* root;
        Tries(): root(new tNode()){};
        
        void insert(string& s){
            tNode* p = root;
            for(char c:s){
                int i = c - 'a';
                if(!p->next[i]) p->next[i] = new tNode();
                p = p->next[i];
            }
            p->str = s;
        }        
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty() || board[0].empty() || words.empty()) return {};
        Tries* t = new Tries();
        for(auto& word:words) t->insert(word);
        vector<string> res;
        
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                search(board, i, j, t->root, res);
            }
        }
        return res;
    }
    
    void search(vector<vector<char>>& board, int i, int j, tNode* p, vector<string>& res){
        char c = board[i][j];
        tNode* nextNode = p->next[c-'a'];
        if(nextNode == NULL) return;
        if(nextNode->str != ""){
            res.push_back(nextNode->str);
            nextNode->str = "";
        }
        
        board[i][j] = '#';
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] != '#'){
                search(board, x, y, nextNode, res);
            }
            
        }
        board[i][j] = c;
    }
    
    
    
};
