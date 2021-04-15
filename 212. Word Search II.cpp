//!!! sol1.1, same as sol1, easier implementation, O(mn*4*3^(L-1)), O(word.size())

class Solution {
public:
    int m, n;
    struct Nod{
        Nod* next[26] = {NULL};
        string word = "";
    };
    Nod* root;
    void BuildTrie(vector<string>& words){
        for(string& w:words){
            Insert(w);
        }
    };
    void Insert(string& w){
        Nod* cur =root;
        for(char c:w){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new Nod();
            }
            cur = cur->next[c-'a'];
        }
        cur->word = w;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); n = board[0].size(); 
        root = new Nod();
        BuildTrie(words);
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                DFS(board, i, j, root);
            }
        }
        return res;
    }
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<string> res;
    void DFS(vector<vector<char>>& board, int i, int j, Nod* cur){
        char c = board[i][j];
        if(cur == NULL || cur->next[c-'a'] == NULL) return;
        
        board[i][j] = '#';
        cur = cur->next[c-'a']; // move to the point c
        
        if(cur->word.size() > 0){
            res.push_back(cur->word);
            cur->word = ""; // !!! remember to remove duplicate!
        }
        
        for(auto& dir:dirs){
            int x = i + dir[0], y = j + dir[1];
            if(Valid(x, y, board)) DFS(board, x, y, cur);
        }
        
        board[i][j] = c;
        
    }
    bool Valid(int x, int y, vector<vector<char>>& board){
        if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '#') return false;
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
