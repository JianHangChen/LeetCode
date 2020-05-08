

!!!! sol2.1, revised from gy2, better than sol2, O(nlogk), O(n)， eaiser for implementation in an interview
class Solution {
public:    
    struct CMP{
        bool operator ()(const pair<string, int>& a, const pair<string, int>& b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        }
    } cmp;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res(k);
        unordered_map<string, int> m;
        for(string& word:words) m[word]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, CMP> pq;

        // nlogk
        for(auto& item:m){
            pq.push(item);
            if(pq.size() > k) pq.pop();
        }  
        for(int i = k - 1; i >= 0; i--){
            res[i] = pq.top().first; pq.pop();
        }
        return res;
    }
};

sol2,  min heap, by priority queue, O(nlogk), O(n)
class Solution {
public:    
    struct CMP{
        bool operator ()(const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    } cmp;
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> m;
        for(string& word:words){
            m[word]++;            
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, CMP> pq;

        // nlogk
        for(auto& item:m){
            pq.push( {item.second, item.first});
            if(pq.size() > k){
                pq.pop();
            }
        }         
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//!!!! sol1.1, bucket sort + trie, O(nm), O(nm), m is the word length, which is a constant
// https://leetcode.com/problems/top-k-frequent-words/discuss/431008/Summary-of-all-the-methods-you-can-imagine-of-this-problem
// very hard to implement

class Solution {
public:    
     vector<string> topKFrequent(vector<string>& words, int k) {
         unordered_map<string, int> m;
         int n = words.size();
         for(string& word:words) m[word]++;
         vector<trie*> count(n+1);
         for(auto& item:m){
             if(count[item.second] == NULL){
                 count[item.second] = new trie();
             }
             count[item.second]->insert(item.first);             
         }
         vector<string> res;
         for(int i = n - 1; i >= 0; i--){
             vector<string> ans;
             if(count[i] == NULL) continue;
             
             count[i]->get_word(count[i]->root, ans);
             if(ans.size() <= k){
                 res.insert(res.end(), ans.begin(), ans.end());
                 k -= ans.size();
             }
             else{
                 res.insert(res.end(), ans.begin(), ans.begin() + k);
                 return res;
             }
             if(k == 0) return res;
         }
         
         return res;
     }
    struct TrieNode{
        struct TrieNode* character[26];
        string word;

    };
    class trie{
        public:
        TrieNode* root;
        trie(){
            root = new TrieNode();
        }
        void insert(const string& word){
            TrieNode* cur = root;
            for(char c:word){
                if( (cur->character)[c-'a'] == NULL ){
                    (cur->character)[c-'a'] = new TrieNode();
                }
                cur = (cur->character)[c-'a'];
            }
            cur->word = word;
        }
        void get_word(TrieNode* root, vector<string>& ans){
            if(!root) return;
            if( !(root->word).empty()) ans.push_back(root->word);
            for(int i = 0; i < 26; i++){
                if( (root->character)[i] != NULL) {
                    get_word((root->character)[i], ans);
                }
            }
        }
    };
    
        
};
    




! sol1, bucket sort, worst O(nlogn), O(n), n is the size of words
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        vector<vector<string>> count(n+1);
        unordered_map<string, int> m;
        vector<string> res;
        for(auto& word:words){
            m[word]++;
        }
        for(auto& item:m){
            count[item.second].push_back(item.first);
        }
        for(int i = n; i >= 0; i--){
            sort( count[i].begin(), count[i].end() ); // this step might cause nlogn in worst case, but generally, it is just O(1)
            for(auto& word:count[i]){
                res.push_back(word);
                k--;
                if(k == 0) return res;
            }            
        }        
        return res;
    }
};




