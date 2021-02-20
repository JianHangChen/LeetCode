// sol1, my, O(c), O(1)
class Solution {
public:
    unordered_map<char, int> rank;
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i = 0; i < order.size(); i++){
            rank[order[i]] = i;
        }
        for(int i = 0; i < words.size() - 1; i++){
            if(!isBefore(words[i], words[i+1])) return false;
        }
        return true;
    }
               
    bool isBefore(string& word1, string& word2){
        int n1 = word1.size(), n2 = word2.size();
        for(int i = 0; i < n1; i++){
            if(i >= n2) return false;
            if(rank[word1[i]] > rank[word2[i]]) return false;
            if(rank[word1[i]] < rank[word2[i]]) return true;
        }
        return true;
    }
};
