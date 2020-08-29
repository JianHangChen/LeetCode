//!!!! sol2, my, trie + deque
class StreamChecker {
public:
    struct tNode{
        tNode* next[26];
        bool end = false;
    };
    
    tNode* root;
    deque<char> history;
    int max_len = 0;
    
    StreamChecker(vector<string>& words) {
        root = new tNode();
        for(string& word:words){
            max_len = max(max_len, (int)word.size());
            tNode* cur = root;
            for(int i = word.size() - 1; i >= 0; i--){
                char c = word[i];
                if(!cur->next[c-'a']) cur->next[c-'a'] = new tNode();
                cur = cur->next[c-'a'];
            }
            cur->end = true;
        }
    }
    
    bool query(char letter) {
        tNode* cur = root;
        history.push_back(letter);
        if(history.size() > max_len) history.pop_front();
        
        for(auto it = history.rbegin(); it != history.rend(); it++){
            char c = *it;
            if(!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
            if(cur->end) return true;            
        }
        return false;
    }
};


//!!! sol1, my c++ version, from sisi
// trie + cylic array to maintain query history

// build trie
// time: O(MN), where M is the word size, N is the word number
// space: O(MN)
// query
// time: O(M), where M is the word size
// space: O(M) to store the stream

class StreamChecker {
public:
    struct tNode{
        tNode* next[26];
        bool end = false;
    };
    
    tNode* root;
    int max_len = 0, idx = 0;
    vector<char> history;
    
    StreamChecker(vector<string>& words) {
        root = new tNode();
        for(string& word:words){
            max_len = max(max_len, (int)word.size());
            tNode* cur = root;
            for(int i = word.size() - 1; i >= 0; i--){
                char c = word[i];
                if(!cur->next[c-'a']) cur->next[c-'a'] = new tNode();
                cur = cur->next[c-'a'];
            }
            cur->end = true;
        }
    }
    
    bool query(char letter) {
        tNode* cur = root;
        if(history.size() < max_len) history.push_back(letter);
        else  history[idx] = letter;
        idx = (idx + 1) % max_len;

        for(int i = 1; i <= history.size(); i++){
            int real_idx = (idx - i + max_len) % max_len;
            char c = history[real_idx];
            if(!cur->next[c-'a']) return false;
            cur = cur->next[c-'a'];
            if(cur->end) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
