// !!! sol2, calculate new number
// https://leetcode.com/problems/confusing-number/discuss/368706/C%2B%2B-Easy-to-understand-solution
class Solution{
public:
    bool confusingNumber(int N){
        vector<int> map = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
        int x = N, newNum = 0;
        while(x > 0){
            int lastDigit = x%10; x /= 10;
            if(map[lastDigit] == -1) return false;
            newNum = newNum * 10 + map[lastDigit];
        }
        return (newNum != N);        
    }    
};

// sol1, my, using string, slower because of translate
// O(logn), O(logn)
class Solution {
public:
    unordered_set<char> sInvalid = {'2', '3', '4', '5', '7'};

    bool confusingNumber(int i){
        if(i == 0) return false; // !!!edge case
        
        string a = to_string(i);
        for(char c:a){
            if(sInvalid.count(c) > 0) return false;
        }
        if(translate(a) == a) return false;
        return true;
    }
    string translate(string& s){
        string res;
        for(int i = 0; i < s.size(); i++){
            char c;
            if(s[i] == '6') c = '9';
            else if(s[i] == '9') c = '6';
            else c = s[i];
            res += c;
        }
        while(!s.empty() && s.back() == '0') s.pop_back();
        
        reverse(res.begin(), res.end());
        return res;
    }
};
