// my, hashmap, O(n), O(1)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for(auto c:s){
            m[c]++;
        }
        
        int how_many_odd = 0;
        for(auto item:m){
            if( item.second % 2 == 1){
                how_many_odd++;
            }
        }
        return how_many_odd <= 1;
    }
};
