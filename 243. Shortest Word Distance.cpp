// sol1, my, O(mn), O(1)
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int last1 = -1, last2 = -1;
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            if(words[i] == word1){
                if(last2 != -1){
                    res = min(res, i - last2);                
                }
                last1 = i;
            }
            else if(words[i] == word2){
                if(last1 != -1){
                    res = min(res, i - last1);
                }
                last2 = i;
            }
        }
        return res;
        
    }
};
