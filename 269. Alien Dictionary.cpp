// sol1, my, O(c), O(min(u^2, n))  c:sum of number of char in words, n = words.size(), u: number of unique char
class Solution {
public:
    string alienOrder(vector<string>& words) {
        int n = words.size();
        unordered_map<char, vector<char>> higherChar;
        unordered_map<char, int> indegree;
        for(auto& word:words){
            for(char c:word){
                indegree[c]= 0;
            }
        }

        queue<char> q;
        for(int i = 0; i < n - 1; i++){
            string word1 = words[i], word2 = words[i+1];
            int n1 = word1.size(), n2 = word2.size();
            for(int i = 0; i < n1; i++){
                if(i >= n2) return ""; // invalid case like "abc" < "ab"
                
                if(word1[i] != word2[i]){
                    higherChar[word1[i]].push_back(word2[i]);
                    indegree[word2[i]]++;
                    break;
                }
            }
        }
        for(auto& item:indegree){
            if(item.second == 0){
                q.push(item.first);                
            }
        }
        
        
        string res = "";
        while(!q.empty()){
            char cur = q.front(); q.pop();
            res.push_back(cur);
            
            for(char nei:higherChar[cur]){
                indegree[nei]--;
                if(indegree[nei] == 0) q.push(nei);
            }
        }
        if(res.size() != indegree.size()) return ""; 
        return res;
        
    }
};
