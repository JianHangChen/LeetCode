
// sol1, !!! my cached dp, O(n^2)

class Solution {

private:
    unordered_map<int, int> m;

public:
    int integerBreak(int n) {

      if(n == 2) return 1;
      if(n == 3) return 2;

      return helpler(n);
        
    }


    int helpler(int n){
        int res = n;
        for(int i = 2; i <= n/2; i++){
          if(m.count(n - i) == 0){
            helpler(n - i);
          }

          res = max( res, i * m[n - i]);
        }

        m[n] = res;
        return m[n];

    }
};







// !!!!! sol2, dp, O(n^2)
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 0;
        for(int i = 2; i <=n; i++){
            for(int j = 1; j < i; j++){
                dp[i] = max(dp[i], j * max(i - j, dp[i - j]));
            }
        }
            
            
        return dp[n];
    }
};

// 1 1| 1 1 1  n = 5
// 
// dp[i] : length i, maximum product of the length i subarray, at least divided into 2 group
// dp[1] = 0
// dp[2] = max(1 * max(1, dp[1]));
// dp[3] = max(1* max(2, dp[2]), 2 * max(1, dp[1]))





// ! sol3, math from gy, O(n)



class Solution{
public:
  int integerBreak(int n){
    if(n == 2) return 1;
    if(n == 3) return 2;

    int res = 1;
    while(n > 4){
      n -= 3;
      res *= 3;
    }

    return res * n;
  }
};
