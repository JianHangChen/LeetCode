
// sol1, my, O(n), O(n)
class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();
        string cur;
        unordered_set<string> s;
        int i = 0;
        while(i < n){
            if(isdigit(word[i])){
                while(i < n && word[i] == '0'){
                    i++;
                }
                while(i < n && isdigit(word[i])){
                    cur.push_back(word[i]);
                    i++;
                }
                s.insert(cur);
                cur = "";
            }
            else{
                i++;
            }
        }
        return s.size();
    }
};
