
// sol2.1, !!!!! dp, O(KN^2), O(N^2), from gy
//dp means start form (i,j), the possible routes for every valid place
class Solution {
private:
  vector<vector<int>> directions = { {1,2}, {2,1}, {1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2, -1} };

public:
    double knightProbability(int N, int K, int r, int c) {
      vector<vector<double>> dp(N, vector<double> (N, 1)); // !! carefull about the number used dp, not 

      for(int k  = 1; k <= K; k++){
        vector<vector<double>> dp2(N, vector<double> (N, 0));
        for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){
            for(auto direct:directions){
              int x  = i + direct[0], y = j + direct[1];
              if(x >= 0 && x < N && y >= 0 && y < N){
                dp2[i][j] += dp[x][y];
              }
            }
          }

        }
        dp = dp2;
      }

      return dp[r][c]/pow(8, K);

    }

};








// sol2.0, dp, O(KN^2), O(N^2)
//dp means start form (r,c), the possible routes in (i,j)
class Solution {
private:
  vector<vector<int>> directions = { {1,2}, {2,1}, {1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2, -1} };

public:
    double knightProbability(int N, int K, int r, int c) {
      double prob;
      vector<vector<double>> dp(N, vector<double> (N, 0 ));
      dp[r][c] = 1;
      for(int i = 1; i <= K; i++){
        vector<vector<double>> dp2(N, vector<double> (N, 0));
        for(int x = 0; x < N; x++){
          for(int y = 0; y < N; y++){
            for(auto direct:directions){
              int a = x + direct[0], b = y + direct[1];
              if( a >= 0 && a < N && b >= 0 && b < N){
                dp2[a][b] += dp[x][y];
              }
            }
          }
        }
        dp = dp2;
      }

      double s = 0;
      for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
          s += dp[i][j];
        }
      }

      prob = s / pow(8,K);
      return prob;
    }
};




//sol1.1,  cached dfs, from gy
class Solution {
private:
  vector<vector<int>> directions = { {1,2}, {2,1}, {1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2, -1} };
  vector<vector<vector<double>>> cache;
  
public:
    double knightProbability(int N, int K, int r, int c) {

      cache.resize(K+1, vector<vector<double>> (N, vector<double> (N, 0)));
      return prob(N, K, r, c);

    }

    double prob(int N, int K, int r, int c){

      double res = 0;
      if(K == 0) return 1;
      if(cache[K][r][c] != 0) return cache[K][r][c];

      for(vector<int> direc:directions){
        int x = r + direc[0], y = c + direc[1];
        if( x >= 0 && x < N && y >= 0 && y < N){
          res += 1.0 / 8 * prob(N, K-1, x, y);
        }
      }
      cache[K][r][c] = res;

      return res;
    }


};



//sol1, my cached dfs
class Solution {
private:
  vector<vector<int>> directions = { {1,2}, {2,1}, {1,-2},{-2,1},{-1,2},{2,-1},{-1,-2},{-2, -1} };
  unordered_map<string, double> m_probability;
public:
    double knightProbability(int N, int K, int r, int c) {
      if(K == 0) return 1;

      double prob = 0;
      for(vector<int> direc:directions){
        int x = r + direc[0], y = c + direc[1];
        if( x >= 0 && x < N && y >= 0 && y < N){
          string xy = to_string(x) + "," + to_string(y) + ","+to_string(K);
          if(m_probability.count( xy) == 0){
            m_probability[xy] = knightProbability(N, K-1, x, y);
          }
          prob += 1.0 / 8 * m_probability[xy];
        }
      }

      return prob;
    }
};


