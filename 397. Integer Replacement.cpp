// sol3, math
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(n % 2 == 0) return 1 + integerReplacement(n / 2);
        if(n == 3) return 2;
        if(n % 4 == 3) return 2 + integerReplacement( n/2 + 1 ) ;
        else return 2 + integerReplacement(n / 2);
    }
};


//!!! sol2, 9 chapter dfs with memory
class Solution {
private:
    unordered_map<int, int> m = { {1,0} };
public:
    int integerReplacement(int n) {
      if(m.count(n) <= 0){
        if(!(n & 1)) m[n] = 1 + integerReplacement(n >> 1);
        else m[n] = 2 + min( integerReplacement((n >> 1) + 1), 
          integerReplacement(n >> 1) );
      }

      return m[n];
    }
};


// // sol1, gy, recursively
// //  dfs without memory
class Solution {
public:
    int integerReplacement(int n) {
      if(n == 1) return 0;
      if(!(n & 1)) return 1 + integerReplacement(n >> 1); // !!!

      // (n+1)/2, (n-1)/2
      return 2 + min(integerReplacement( (n >> 1) + 1), integerReplacement( n >> 1) );
    }
};


