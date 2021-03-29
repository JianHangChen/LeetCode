// ! sol4.1, optimized bfs, dijikstra, O(KE), O(v^2)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        vector<vector<vector<int>>> edges(n); 
        for(auto& flight:flights){
            int u = flight[0], v = flight[1], w = flight[2];
            edges[u].push_back({v, w});            
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > q;
        q.push({0, src});
        
        while(!q.empty() && K >= 0){
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > qNew;
            for(int t = q.size(); t > 0; t--){
                auto cur = q.top(); q.pop();
                int d = cur[0], u = cur[1];
                for(auto& edge:edges[u]){
                    int v = edge[0], w = edge[1];
                    if(d + w < dist[v]){
                        dist[v] = d + w;
                        qNew.push({dist[v], v});
                    }
                }
            }
            q = qNew;
            K--;
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
        
    }
};


// !!!!! sol4,  my, bfs, O(KE), O(V^2)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        vector<vector<vector<int>>> edges(n); 
        for(auto& flight:flights){
            int u = flight[0], v = flight[1], w = flight[2];
            edges[u].push_back({v, w});            
        }
        queue<vector<int>> q;
        q.push({src, 0});
        
        while(!q.empty() && K >= 0){
            for(int t = q.size(); t > 0; t--){
                auto cur = q.front(); q.pop();
                int u = cur[0], d = cur[1];
                for(auto& edge:edges[u]){
                    int v = edge[0], w = edge[1];
                    if(d + w < dist[v]){
                        dist[v] = d + w;
                        q.push({v, dist[v]});
                    }
                }
            }
            K--;
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
        
    }
};



//sol3, !!! bellman ford O(K*E), O(n)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        for(int i = 1; i <= K + 1; i++){
            vector<int> newDist = dist;
            for(auto& e:flights){
                int u = e[0], v = e[1], w = e[2];         
                newDist[v] = min(dist[u] + w, 
                                 min(newDist[v], dist[v]));
            }
            dist = newDist;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
    

//sol2, !!! bellman ford O(K*E), O(n*E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> dist(K+2, vector<int> (n, 1e9));
        dist[0][src] = 0;
        
        for(int i = 1; i <= K + 1; i++){
            for(auto& e:flights){
                int u = e[0], v = e[1], w = e[2];         
                dist[i][v] = min(dist[i-1][u] + w, 
                                 min( dist[i][v], dist[i-1][v]));
            }
        }
        return dist[K+1][dst] == 1e9 ? -1 : dist[K+1][dst];
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
