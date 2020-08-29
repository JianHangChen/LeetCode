class Trie {
public:
    /** Initialize your data structure here. */
    struct tNode{
        tNode* next[26];
        bool end = false;
    };
    
    tNode* root;
    Trie() {
        root = new tNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        tNode* cur = root;
        for(char c:word){
            if(!cur->next[c-'a']) cur->next[c-'a'] = new tNode();
            cur = cur->next[c-'a'];
        }
        cur->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        tNode* cur = root;
        for(char c:word){
            if(!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        }
        return cur->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        tNode* cur = root;
        for(char c:prefix){
            if(!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
