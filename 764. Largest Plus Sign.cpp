// sol2, dp,  O(N^2), O(N^2)
class Solution {
private:
    vector<vector<int>> m;
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int order = 0;
        m.resize(N, vector<int> (N, 1));
        for(auto v:mines){
          m[v[0]][v[1]] = 0;
        }

        vector<vector<int>> dp (N, vector<int> (N,0));
        
        for(int i = 0; i < N ; i++){
          int count = 0; //left
          for(int j = 0; j < N; j++){
            count = (m[i][j] == 0) ? 0 : count + 1;
            dp[i][j] = count;
          }
          count = 0; //right
          for(int j = N-1; j >= 0; j--){
            count = (m[i][j] == 0) ? 0 : count + 1;
            if(count < dp[i][j]) dp[i][j] = count;
          }

        }

        
        for(int j = 0; j < N ; j++){
          int count = 0;//down
          for(int i = N-1; i >= 0; i--){
            count = (m[i][j] == 0) ? 0 : count + 1;
            if(count < dp[i][j]) dp[i][j] = count;
          }

          count = 0;
          for(int i = 0; i < N; i++){
            count = (m[i][j] == 0) ? 0 : count + 1;
            if(count < dp[i][j]) dp[i][j] = count;
            if(order < dp[i][j]) order = dp[i][j];
          }

        }
        return order;
    }
};


// sol1,  brute force, TEL , O(N^3)
class Solution {
private:
    vector<vector<int>> m;
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int order = 0;
        m.resize(N, vector<int> (N, 1));
        for(auto v:mines){
          m[v[0]][v[1]] = 0;
        }



        for(int i = 0; i < N ; i++){
          for(int j = 0; j < N; j++){
            order = max(order, getOrder(i,j,N));
          }
        }
        return order;
    }
    int getOrder(int i, int j, int N){
      int order = 0;
      while(i - order >= 0 && j - order >= 0 && i + order < N && j + order < N && m[i - order][j] && m[i+order][j] && m[i][j-order] && m[i][j+order]){
        order++;
      }
      return order;

    }

};

