
// !!! sol2, O(2^n), O(2^n), from gy2
// mirror from end to start
//from https://leetcode.com/problems/gray-code/discuss/29893/One-liner-Python-solution-(with-demo-in-comments)    
    
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        for(int i = 0; i < n; i++){
            int l = res.size();
            for(int j = l - 1; j >= 0; j--){
                res.push_back(res[j]^(1 << i));
            }
        }
        return res;
    }
};


//!!! sol1, from gy1, O(2^n), O(2^n)
// using binary manipulation
//https://leetcode.com/problems/gray-code/discuss/30028/4-lines-C%2B%2B-code.
    
//     I try to give a simple proof here. Let's denote i^(i>>1) as f(i). To proof f(i) is the ith gray code, we only need to prove the following statements:

// f(0) = 0
// (i) and f(i+1) only differs in one digit
// f(i) is bijective, e.g. f(i) = f(j) if and only if i = j.
// The first one is obvious.

// For the second , f(i) ^ f(i+1) = i^(i>>1)^(i+1)^((i+1)>>1) = (i^(i+1)) ^ ((i^(i+1)) >> 1). Let's denote g(i) = i^(i+1), g(i) has the form of 0000111...111. So f(i) ^ f(i+1) = g(i) ^ g(i)>>1 = 00001000...000.

// The third part can be proved alike.

    // if f(i) = f(j), i^(i>>1) = j^(j>>1)
    // i^(i>>1) ^ j^(j>>1) = 0
    // (i^j)^( (i>>1) ^ (j>>1)) = 0
    //(i^j)^(i^j>>1) = 0
    //a^(a>>1) should like 00001....
    // so a = 0
    // so i^j =0
    // so i = j
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;        
        for(unsigned int i = 0; i < pow(2, n); i++){
            res.push_back( i^(i >> 1));
        }
        return res;
    }
};


  sol3, backtracking
    from https://leetcode.com/problems/gray-code/discuss/29880/Backtracking-C%2B%2B-solution
    void utils(bitset<32> &b, vector<int> &ans, int k){
        if(k == 0){
            ans.push_back(b.to_ulong());
        }
        else{
            utils(b, ans, k-1);
            b.flip(k-1);
            utils(b, ans, k-1);
        }
        
    }
    
    vector<int> grayCode(int n) {
        bitset<32> b;
        vector<int> ans;
        utils(b, ans, n);
        return ans;
    }    
