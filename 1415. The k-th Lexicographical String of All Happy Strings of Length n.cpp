
// !!! sol1, dfs, O(k), O(n)
// from https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/discuss/585590/C%2B%2B-DFS-minimalizm
class Solution {
public:
    int count = 0;
    string getHappyString(int n, int k) {
        if(k > 3 * pow(2, n-1)) return "";
        string res = "";
        helpler(n, k, 0, '0', res);
        return res;   
    }
    
    void helpler(int n, int k, int digit, char last_ch, string& res){
        if(digit == n){
            count++;
        }
        else{
            for(char c = 'a'; c <= 'c'; c++){
                if(c != last_ch){
                    res.push_back(c);
                    helpler(n, k, digit+1, c, res);
                    if(count == k) return;
                    res.pop_back();
                }
            }            
        }
    }
};
