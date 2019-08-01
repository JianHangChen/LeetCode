//sol2,!!! 3D dp, O(n^2), O(n^2)

class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
      unordered_map<char, vector<string>> m;
      for(auto s:allowed){
        m[s[2]-'A'].push_back(s.substr(0,2));
      }

      int n = bottom.size();
      vector<vector<vector<bool>>> dp(n, vector<vector<bool>> (n, vector<bool> (7, false)));

      for(int j = 0; j < n; j++){
        int c = bottom[j] - 'A';
        dp[n-1][j][c] = true;
      }

      for(int i = n - 2; i >= 0; i--){
        for(int j = 0; j <= i; j++){
          for(int k = 0; k < 7; k++){
            for(string base:m[k]){
              int left = base[0]-'A', right = base[1]-'A';
              if(dp[i+1][j][left] && dp[i+1][j+1][right]){
                dp[i][j][k] = true;
                continue;
              }
            }
          }
        }
      }

      for(int k = 0; k < 7; k++){
        if(dp[0][0][k]) return true;
      }
      return false;

    }
};

// sol1, DFS  

//O(A^(N^2)) no cache, O(A^N) cache,
//space: O(N^2)
class Solution {

private:
  unordered_set<string> seen; //cache
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
      // unordered_map<pair{char, char}, vector<char>> m; //pair cannot be the key of map
      unordered_map<string, vector<char>> m;
      for(auto s:allowed){
        m[s.substr(0,2)].push_back(s[2]); // s.substr
      }

      return helpler(bottom, "", m);

    }

    bool helpler(string cur, string above, unordered_map<string, vector<char>> &m){
      if(cur.size() == 2 && above.size() == 1) return true;
      if(cur.size() == above.size() + 1) return helpler(above, "", m);

      int i = above.size();
      if(i == 0){ //cache
        if(seen.count(cur) > 0) return false;
        else{
          seen.insert(cur);
        }
      }

      if(m.count(cur.substr(i, 2)) > 0){
        for(auto c: m[cur.substr(i,2)]){
          if(helpler(cur, above + c, m)){
            return true;
          }
        }
      }
      return false;
    }
};

