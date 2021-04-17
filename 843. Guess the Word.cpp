// !!! sol1, iteratively filter out the wordlist with correct match number
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        unordered_set<string> s(wordlist.begin(), wordlist.end());
        
        
        for(int t = 0; t < 10; t++){
            string word = *s.begin();
            int match = master.guess(word);
            if(match == 6) return;
            unordered_set<string> news;
            for(auto w:s){
                if(Match(w, word) == match){
                    news.insert(w);
                }
            }
            s = news;
        }
        
    }
    int Match(string& a, string& b) const{
        int match = 0;
        for(int i = 0; i < a.size(); i++){
            if(a[i] == b[i]) match++;
        }
        return match;
    }
};
