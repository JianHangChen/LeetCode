class Solution {
private:
    struct Nod{
        Nod* next[26] = {NULL};
        string word = "";
    };
    Nod* root;
    
    void insert(string& w){
        Nod* cur = root;
        for(char c:w){
            if(cur->next[c-'a'] == NULL){
                cur->next[c-'a'] = new Nod();
            }
            cur = cur->next[c-'a'];
        }
        cur->word = w;
    }
    void BuildTrie(vector<string>& words){
        root = new Nod();
        for(auto& w:words){
            insert(w);
        }
    }
    int Search(string& S, int i){ // return the end
        Nod* cur = root;
        int end = i;
        while(i < S.size()){
            if(cur->next[S[i] - 'a'] == NULL) break;
            cur = cur->next[S[i] - 'a'];
            i++;
            if(cur->word.size() > 0) end = i;
        }
        return end;
    }
    vector<bool> bold;
public:
    string boldWords(vector<string>& words, string S) {
        BuildTrie(words);
        
        int n = S.size();
        bold.resize(n, false);
        
        for(int i = 0; i < n; i++){
            int end = Search(S, i);
            for(int j  = i; j < end; j++){
                bold[j] = true;
            }
        }
        
        string res = "";
        int i = 0;
        while(i < n){            
            if(bold[i]){
                res += "<b>";
                while(i < n && bold[i]){
                    res += S[i];
                    i++;
                }
                res += "</b>";
            }
            else{
                res += S[i];
                i++;
            }
        }
        return res;        
    }
};
