// my
// code can still improve
// klogk, k
class Solution {
 public:
  int GetSquare(int x, int y, int z){
    return x*x+y*y+z*z;
  }
  int na, nb, nc;
  set<vector<int>> visited;
  vector<int> closest(vector<int> a, vector<int> b, vector<int> c, int k) {
      priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
      pq.push({GetSquare(a[0], b[0], c[0]), 0, 0, 0});
      na = a.size(); nb = b.size(); nc = c.size();
      
      visited.insert({0, 0, 0});

      auto cur = pq.top();
      for(int i = 0; i < k; i++){
          cur = pq.top(); pq.pop();
          int dist = cur[0], x = cur[1], y = cur[2], z = cur[3];
          
          if(Valid(x+1, y, z)){
            pq.push({GetSquare(a[x+1], b[y], c[z]), x+1, y, z});
            visited.insert({x+1, y, z});
          }
          if(Valid(x, y+1, z)){
            pq.push({GetSquare(a[x], b[y+1], c[z]), x, y+1, z});
            visited.insert({x, y+1, z});
          }
          if(Valid(x, y, z+1)){
            pq.push({GetSquare(a[x], b[y], c[z+1]), x, y, z+1});
            visited.insert({x, y, z+1});
          }
      }
      return {a[cur[1]], b[cur[2]], c[cur[3]]};
  }
  bool Valid(int x, int y, int z){
    if(x >= na || y >= nb || z >= nc || visited.count({x, y, z}) > 0) return false;
    return true; 
  }
};
