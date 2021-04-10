// sol1, my trie, O(N+wd), O(N)
// N is sentence length
// d: dictionary length, w: max word length in dict
class Solution {
public:
    struct Nod{
        Nod* next[26]= {};
        string word = "";
    };
    Nod* root;
    void insert(const string& w){
        Nod* cur = root;
        for(char c:w){
            if(cur->next[c-'a'] == NULL) cur->next[c-'a'] = new Nod();
            cur = cur->next[c-'a'];
        }
        cur->word = w;
    }
    string search(const string& w){
        Nod* cur = root;
        for(char c:w){
            if(cur->next[c-'a'] == NULL) return w;            
            cur = cur->next[c-'a'];
            if(cur->word.size() > 0) return cur->word;
        }
        return w;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        root = new Nod();
        for(string& w:dictionary){ // w*d
            insert(w);
        }
        
        string res, w;
        istringstream s(sentence);
        while(s >> w){ // O(N/lengthof word)
            if(!res.empty()) res += ' ';
            res += (search(w)); // O(lengthofword)
        }
        return res;
    }
};
