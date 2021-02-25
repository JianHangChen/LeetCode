// sol1, my O(n), O(1)
class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int last1 = -1, last2 = -1;
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            if(words[i] == word1 && word1 == word2){
                if(last1 != -1) res = min(res, i - last1);
                last1 = i;
                continue;
            }
            
            if(words[i] == word1){
                if(last2 != -1) res = min(res, i - last2);
                last1 = i;
                
            }
            else if(words[i] == word2){
                if(last1 != -1) res = min(res, i - last1);
                last2 = i;
            }
        }
        return res;
    }
};
