//sol3, !!! bellman ford O(K*E), O(n)

class Solution {
public:
  int findCheapestPrice(int n, vector< vector<int> >& flight, int src, int dst, int K){

    vector<int> bf(n, 1e9), new_bf;
    bf[src] = 0;
    
    

    for(int i = 1; i <= K+1; i++){
      new_bf = bf;

      for(auto f:flight){
        new_bf[f[1]] = min( bf[f[0]] + f[2], new_bf[f[1]]);
      }
      bf = new_bf;
    }
    return bf[dst] == 1e9 ? -1 : bf[dst];
  }
};

    

//sol2, !!! bellman ford O(K*E), O(n*E)
class Solution {
public:
  int findCheapestPrice(int n, vector< vector<int> >& flight, int src, int dst, int K){
    vector<vector<int>> bf(K+2, vector<int> (n, 1e9));

    bf[0][src] = 0;

    for(int i = 1; i <= K+1; i++){
      bf[i][src] = 0;

      for(auto f:flight){
        bf[i][f[1]] = min( bf[i-1][f[0]] + f[2], bf[i][f[1]]);
      }

    }
    return (bf[K+1][dst] == 1e9) ? -1 : bf[K+1][dst];
  }
};



//sol1, dfs, O()
// Making the graph takes O(E)

class Solution {
private:
  int cheapest = INT_MAX;
  unordered_map<int, vector< pair<int, int> > > f;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        for(auto e:flights){
          f[e[0]].push_back({e[1], e[2]});
        }

        helpler(0, src, dst, K);

        return (cheapest < INT_MAX)? cheapest : -1;

    }

    void helpler(int price, int src, int dst, int K){

      if(price>=cheapest) return;

      if(src == dst){
        cheapest = price;
        return;
      }

      if( K>= 0){
        for(auto p:f[src]){
          helpler(price + p.second, p.first, dst, K-1);
        }
      }

    }

};
