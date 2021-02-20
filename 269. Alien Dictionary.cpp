

// sol1, my, O(c), O(min(u^2, n))  c:sum of number of char in words, n = words.size(), u: number of unique char
class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        set<char> alphabet;
        for(auto& word:words){
            for(char c:word){
                alphabet.insert(c);
            }
        }

        unordered_map<char, vector<char>> higherChar;
        unordered_map<char, int> inDegree;
        queue<char> q;
        for(int i = 0; i < n - 1; i++){
            string word1 = words[i], word2 = words[i+1];
            int n1 = word1.size(), n2 = word2.size();
            for(int i = 0; i < n1; i++){
                if(i >= n2) return ""; // invalid case like "abc" < "ab"
                
                if(word1[i] != word2[i]){
                    higherChar[word1[i]].push_back(word2[i]);
                    inDegree[word2[i]]++;
                    break;
                }
            }
        }
        for(char c:alphabet){
            if(inDegree[c] == 0){
                q.push(c);                
            }
        }
        
        
        int totalValidChar = 0;
        string res = "";
        while(!q.empty()){
            char cur = q.front(); q.pop();
            res.push_back(cur);
            
            totalValidChar++;
            for(char nei:higherChar[cur]){
                inDegree[nei]--;
                if(inDegree[nei] == 0) q.push(nei);
            }
        }
        if(totalValidChar != alphabet.size()) return ""; 
        return res;
        
    }
};
