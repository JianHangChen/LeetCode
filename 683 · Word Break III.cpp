// sol1, my, trie + dfs with memo
//  level 1: start 0,   1,   2, .... , n - 1
//            /|\ \ \ 
// level 2: 1  2 3.. n-1
// level 3：/|\          
// levle 4:2 3...n-1
// by memo, O(n * l * l)         
// space O(ml)
// n = sentence.size, m = size(words), l = length(longest word)
class Solution{
private:
    struct tNode{
        tNode* next[26] = {NULL};
        bool valid = false;
    };
    tNode* root;
    void insert(const string& s){ // carefull about w:words and reference
        tNode* cur = root;
        for(char c:s){
            if(c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
            if(cur->next[c - 'a'] == NULL){
                cur->next[c - 'a'] = new tNode();
            }
            cur = cur->next[c - 'a'];
        }
        cur->valid = true;
    }
    bool search(const string& s){
        tNode* cur = root;
        for(char c:s){
            if(cur->next[c - 'a'] == NULL){
                return false;
            }
            cur = cur->next[c - 'a'];
        }
        return cur->valid;       
    }
    void buildTrie(unordered_set<string>& words){
        root = new tNode();    
        for(auto& w:words){
            longestWordLen = max(longestWordLen, (int)w.size());
            insert(w);
        }
    }
    unordered_map<int, int> memo;
    int longestWordLen = 0;

    int getNum(unordered_set<string>& words, string& sentence, int idx){
        buildTrie(words);
        int n = sentence.size();
        if(idx == n) return 1;
        if(memo.count(idx) > 0) return memo[idx];
        int res = 0;
        for(int j = idx; j < min(n, idx + longestWordLen); j++){ // l
            if(search( sentence.substr(idx, j - idx + 1) )){ // l
                res += getNum(words, sentence, j + 1);
            }
        }
        memo[idx] = res; //memo[3] = 1
        return res;
    }
public:
    int wordBreak3(string& sentence, unordered_set<string>& words){
        for(int i = 0; i < sentence.size(); i++){
            if(sentence[i] >= 'A' && sentence[i] <= 'Z') sentence[i] = sentence[i] - 'A' + 'a';
        }
        return getNum(words, sentence, 0);
    }
};
