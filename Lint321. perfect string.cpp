// sol1, O(n), from wp

class Solution {
public:
    /**
     * @param s: string need to be transformed
     * @param k: minimum char can be transformed in one operation
     * @return: minimum times to transform all char into '1'
     */
    int perfectString(string &s, int k) {
        int j, res = 0;
        for(int i = 0; i< s.size(); i++){
            if(s[i] == '0'){
                for(j = i; j < s.size() && j - i  < k; j++){
                    if(s[j] == '1') break;
                }
                res++;
                i = j - 1;
            }
        }
        return res;
    }
};
