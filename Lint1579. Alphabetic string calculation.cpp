
// my sol1
class Solution {
public:
    /**
     * @param aString: letter string
     * @return: the Minimum times
     */
    int Kstart(string &aString) {
        int res = 0;
        vector<int> count(26, 0);
        for(char c:aString){
            count[c-'a']++;
        }
        
        unordered_set<int> s;
        for(int i = 0; i < 26; i++){
            if(count[i] == 0) continue;
            
            if(s.count(count[i]) == 0){
                s.insert(count[i]);
                continue;
            }
            else{
                while(count[i] > 0){
                    count[i]--; res++;
                    if(s.count(count[i]) == 0){
                        s.insert(count[i]);
                        break;
                    }
                }
            }
        }
        return res;
        
    }
};
