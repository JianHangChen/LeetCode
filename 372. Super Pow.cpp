// !!! sol2, iteratively get superpow, from 9ch
class Solution{

const int mod = 1337;

  int pow(int a, int n){
    if(n == 0) return 1;
    if(n == 1) return a % mod;

    a %= mod; //!!!!!
    int half = pow(a, n / 2);

    if( n%2 == 0) return half * half % mod;
    else{
      return half * half % mod * a % mod;
    }
  }


public:
  int superPow(int a, vector<int>& b){
    if(b.empty()) return 1;
    int res = 1;
    for(int i = 0; i < b.size(); i++){
      res = pow(res, 10) % mod * pow(a, b[i]) % mod;
    }
    return res;
  }
};




// sol1, from https://leetcode.com/problems/super-pow/discuss/84472/C%2B%2B-Clean-and-Short-Solution
class Solution{

const int mod = 1337;

  int pow(int a, int n){
    if(n == 0) return 1;

    a %= mod; //!!!!!
    int half = pow(a, n / 2);

    if( n%2 == 0) return half * half % mod;
    else{
      return half * half % mod * a % mod;
    }
  }


public:
  int superPow(int a, vector<int>& b){
    if(b.empty()) return 1;
    int digit = b.back(); b.pop_back();
    return (pow(superPow(a, b), 10) % mod * pow(a, digit)) % mod;
  }
};
