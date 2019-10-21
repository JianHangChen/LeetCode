
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







// ! sol2, dp, O(n^2)
class Solution{

public:
  int integerBreak(int n){

    vector<int> cache(n+1, 1);

    for(int i = 3; i <= n; i++){
      for(int j = 1; j < i; j++){
        cache[i] = max(cache[i], max(j * (i - j), j * cache[i - j]));
      }
    }
    return cache[n];
  }

};


You may check the breaking results of n ranging from 7 to 10 to discover the regularities.





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
