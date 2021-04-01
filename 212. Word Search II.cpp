//!!! sol1.1, same as sol1, easier implementation, O(mn*4*3^(L-1)), O(word.size())

class Solution {
public:
    int m, n;
    struct tNode{
        string word;
        tNode* next[26];
        tNode(){
            word = "";
            for(int i = 0; i < 26; i++) next[i] = NULL;
        }
    };
    
    tNode* root;
    
    void insert(string& word){
        tNode* cur = root;
        for(char c:word){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new tNode();
            }
            cur = cur->next[c-'a'];
        }
        cur->word = word;
    }
    vector<string> res;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); n = board[0].size();
        root = new tNode();    
        
        for(string& word:words){
            insert(word);    
        }
        
        for(int i = 0; i < m ; i++){
            for(int j = 0; j <n; j++){            
                dfs(board, i, j, root);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, tNode* cur){
        char c = board[i][j];
        if(cur->next[c - 'a'] == NULL) return;
        board[i][j] = '#';
        cur = cur->next[c-'a'];
        if(cur->word.size() != 0){
            res.push_back(cur->word);
            cur->word = "";
        }
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(isvalid(x, y, board)){
                dfs(board, x, y, cur);            
            }
        }
        
        board[i][j] = c;
    }
    bool isvalid(int x, int y, vector<vector<char>>& board){
        if(x < 0 || x >= m || y < 0 || y >= n || !isalpha(board[x][y])) return false;
        return true;
    }
    
};
  

// sol1, from gy1, need more practice, O(mn*4*3^(L-1)), O(word.size())
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
