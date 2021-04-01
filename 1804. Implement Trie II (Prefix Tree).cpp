class Trie {
public:
    struct tNode{
        tNode* next[26] = {NULL};
        int childCount = 0;
        int wordCount = 0;
    };
    
    tNode* root;
    
    Trie() {
        root = new tNode();
    }

    
    void insert(string word) {
        tNode* cur = root;
        int i = 0;
        while(i < word.size()){
            if(cur->next[word[i] - 'a'] == NULL){
                cur->next[word[i] - 'a'] = new tNode();
            }
            cur->childCount++;
            cur = cur->next[word[i] - 'a'];
            i++;
        }
        cur->wordCount++;
        cur->childCount++;
    }
    
    int countWordsEqualTo(string word) {
        tNode* cur = root;
        int i = 0;
        while(i < word.size()){
            if(cur->next[word[i] - 'a'] == NULL){
                return 0;
            }
            cur = cur->next[word[i] - 'a'];
            i++;
        }
        return cur->wordCount;
    }
    
    int countWordsStartingWith(string word) {
        tNode* cur = root;
        int i = 0;
        while(i < word.size()){
            if(cur->next[word[i] - 'a'] == NULL){
                return 0;
            }
            cur = cur->next[word[i] - 'a'];
            i++;
        }
        return cur->childCount;        
    }
    
    void erase(string word) {
        // int t = countWordsEqualTo(word); // if you want to erase whole word
        tNode* cur = root;
        int i = 0;
        while(i < word.size()){
            if(cur->next[word[i] - 'a'] == NULL){
                return;
            }
            cur->childCount--;
            cur = cur->next[word[i] - 'a'];
            i++;
        }
        cur->wordCount--;
        cur->childCount--;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
