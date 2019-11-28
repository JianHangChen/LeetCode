// ! sol2.1, hash_map from int to int, from gy3
// this is good for sparse matrix
// O(n^4), O(n^2)
class Solution{
public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B){
    int n = A.size();
    unordered_map<int, int> count_offset;
    vector<vector<int>> listA, listB;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(A[i][j]) listA.push_back({i, j});
        if(B[i][j]) listB.push_back({i, j});
      }
    }
    for(vector<int>& k:listA){
      for(vector<int>& t:listB){
        count_offset[(t[0] - k [0]) * 100 + (t[1] - k[1])]++; 
      }
    }
    int res = 0;
    for(auto& item:count_offset){
      res = max(res, item.second);
    }
    return res;
  }
};

// sol2, hash_map count for the diff of coordinates. from gy2. 
// this is good for sparse matrix
// O(n^4), O(n^2)
class Solution{
public:
  int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B){
    int n = A.size();
    unordered_map<string, int> count_offset;
    vector<vector<int>> listA, listB;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(A[i][j]) listA.push_back({i,j});
        if(B[i][j]) listB.push_back({i,j});
      }
    } // O(n^2)

    for(vector<int>& k:listA){ O(n^2)
      for(vector<int>& t:listB){ O(n^2)
        string offset = to_string(t[0] - k[0]) + "-" + to_string(t[1] - k[1]);
        count_offset[offset]++;
      }
    }

    int res = 0;
    for(auto& item:count_offset){ // O(n^2)
      res = max(res, item.second);
    }
    return res;
  }
};


//!!! sol1, my O(n^4), O(1)
class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int res = 0;
        for(int lx = -n + 1; lx < n; lx++){
          for(int ly = -n + 1; ly < n; ly++){
            res = max(res, checkOverlap(A, B, lx, ly) );
          }
        }
        return res;
    }

    int checkOverlap(vector<vector<int>>& A, vector<vector<int>>& B, int lx, int ly){
      int res = 0, n = A.size();
      for(int i = 0; i < n; i++){
        int int x = i + lx;
        if(x < 0 || x >= n ) continue;
        for(int j = 0; j < n; j++){
          int y = j + ly;
          if(y < 0 || y >= n) continue;
          if(A[i][j] == 1 && B[x][y] == 1) res += 1;
        }
      }
      return res;
    }
};
