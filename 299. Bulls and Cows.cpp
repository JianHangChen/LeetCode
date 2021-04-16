// !!! sol1.1, my O(n), O(1)
// one pass, sol2
//s 11231
//g 11112
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m; // not matched
        int bull = 0, cow = 0, n = secret.size();
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                bull++;
            }
            else{
                if(m[secret[i]] < 0) cow++;
                if(m[guess[i]] > 0) cow++;
                m[secret[i]]++;
                m[guess[i]]--;
            }
        }
        string res = to_string(bull) + "A" + to_string(cow) + "B";
        return res;
    }
};


// sol1, my O(n), O(1)
// the hash map is very small, only the same as the number of char
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m; // not matched
        int bull = 0, cow = 0, n = secret.size();
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i]){
                bull++;
                secret[i] = '#';
            }
            else{
                m[guess[i]]++; 
            }
        }
        for(int i = 0; i < secret.size(); i++){
            if(secret[i] == '#') continue;
            if(m.count(secret[i]) > 0 && m[secret[i]] > 0){
                cow++;
                m[secret[i]]--;
            }
        }
        string res = to_string(bull) + "A" + to_string(cow) + "B";
        return res;
    }
};

