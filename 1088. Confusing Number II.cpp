//!!! sol2, DFS
// faster since for 1 6 8 9 we skip 0~10
// for 10 11 16 18 19, 60 61 66 68 69 ... we skip a lot of number from 0~100
// https://leetcode.com/problems/confusing-number-ii/discuss/316172/C%2B%2B-simple-dfs
// O(4^(log10(n))), O(log10(n))


class Solution {
public:
    int count = 0;
    int confusingNumberII(int N) {
        for(int i = 1; i < v.size(); i++){
            DFS(v[i], N);
        }
        return count;
    }
    void DFS(long long x, int N){
        if(x > N) return;
        if(IsConf(x)) count++;
        for(int add:v){
            DFS(x * 10 + add, N);
        }
    }
    bool IsConf(int n){
        int x = n, newn = 0;
        while(x > 0){
            int last = x % 10;
            if(map[last] == -1) return false;
            newn = newn*10 + map[last];
            x /= 10;
        }
        return newn != n;
    }
    vector<int> map = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
    vector<int> v = {0, 1, 6, 8, 9};

};


// 1. should be valid
//      (1) contain 23457 is invalid
//      (2) 
// 2. should become different
//      (1) has any of 6 or 9 // but 6 9->9 6
//      (2) 0 1 8 but not symmetric


// sol1, my, tle, took too long to process [1, 2..., N]

class Solution {
public:
    int confusingNumberII(int N) {
        int count = 0;
        for(int i = 1; i <= N; i++){
            if(isConfusing(i)){
                count++;
            }
        }
        return count;
    }
    unordered_set<char> sInvalid = {'2', '3', '4', '5', '7'};
    bool IsConfusing(int i){
        string a = to_string(i);
        for(char c:a){
            if(sInvalid.count(c) > 0) return false;
        }
        if(translate(a) == a) return false;
        return true;
    }
    string Translate(string& s){
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
