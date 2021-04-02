// sol1, my, trie, 
// initialize: O(lk),O(lk)
// l sentence, k length
// input: O(l * q)
// q all strings with current prefix

class AutocompleteSystem {
public:
    struct tNode{
        tNode* next[256] = {NULL};
        string sentence = "";
        int time = 0;
    };
    
    void insert(string& s, int t){
        tNode* cur = root;
        for(char c:s){
            if(cur->next[c] == NULL){
                cur->next[c] = new tNode();
            }
            cur = cur->next[c];
        }
        cur->sentence = s;
        cur->time = cur->time + t;
    }
    string buf;
    tNode* root, *curr;
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new tNode();
        curr = root;
        for(int i = 0; i < times.size(); i++){
            insert(sentences[i], -times[i]);
        }
        buf = "";
    }
    
    vector<string> input(char c) {
        if(c == '#'){
            insert(buf, -1);
            buf = "";
            curr = root; // reset
            return {};
        }
        else{
            buf.push_back(c);
            if(curr->next[c] == NULL) curr->next[c] = new tNode();
            curr = curr->next[c];
            return getTop3();
        }
    }
    vector<string> getTop3(){
        vector<string> res;
        set<pair<int, string>> st;
        
        get3(curr, st);
        
        auto it = st.begin();
        while(it != st.end()){
            res.push_back((*it).second);
            it++;
        }
        
        return res;
    }
    
    void get3(tNode* cur, set<pair<int, string>>& st){
        if(cur->time != 0) st.insert({(cur->time), cur->sentence});
        if(st.size() > 3) st.erase(*st.rbegin());
        
        for(int i = 0; i < 256; i++){
            if(cur->next[i] == NULL) continue;
            get3(cur->next[i], st);
        }
    }
    
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
