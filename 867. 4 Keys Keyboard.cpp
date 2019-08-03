

// sol3,!!! dp, O(n^2), O(n)
class Solution{ 
public:
  int maxA(int N){
    vector<int> dp(N+1, 0);
    for(int i = 1; i <= N; i++){
      dp[i] = dp[i-1] + 1;
      for(int j = 1; j < i - 2; j++){
        dp[i] = max(dp[i], dp[j]* (i - j - 2 + 1) ); // careful here
      }
    }
    return dp[N];
  }
};


//sol2, dfs cache, O(n^2), O(n)
class Solution{ 
private:
  unordered_map<int, int> m;
public:
  int maxA(int N){
    if(m.count(N) > 0) return m[N];
    int res = N;
    for(int i = 1; i < N - 1; i++){
      res = max(res, maxA(i) * (N - 1 - i));
    }
    m[N] = res;
    return res;
  }
};



// sol1, dfs,  TEL
class Solution {
public:
    /**
     * @param N: an integer
     * @return: return an integer
     */
  int maxA(int N){
    int res = N;
    for(int i = 1; i < N-1; i++){
      res = max(res, maxA(i) * (N - 1 - i));
    }
    return res;
  }

};









