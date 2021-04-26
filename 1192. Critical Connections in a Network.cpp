
//!!! sol2, O(V+E), O(V+E)
// Tarjan's algorithm ( work for directed graph as well)
//https://www.youtube.com/watch?v=RYaakWv5m6o
// code     https://happygirlzt.com/code/1192.html
// strong connected component: scc
class Solution {
public:
    int index = 0;
    unordered_map<int, int> idx; // the index of node according to visiting order
    unordered_map<int, int> low;
    unordered_map<int, int> parent;
    vector<vector<int>> res;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> next(n);
        for(auto& c:connections){
            int a = c[0], b = c[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        DFS(0, next);
        return res;
    }
    // return the lowest value of the point of start
    void DFS(int cur, vector<vector<int>>& next){
        
        idx[cur] = low[cur] = index++;
        
        for(int nei:next[cur]){
            if(parent[cur] == nei) continue;  
            
            if(low.count(nei) == 0){ //not visited
                parent[nei] = cur;
                DFS(nei, next);
            }
            
            low[cur] = min(low[cur], low[nei]);
            if(idx[cur] < low[nei]) res.push_back({cur, nei});            
        }
        
    }
};


// sol1, my, tle delete each edge to see if it forms a connected graph O(e*(v+e)), O(e+v);
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> next(n), res;
        for(auto& c:connections){
            int a = c[0], b = c[1];
            next[a].push_back(b);
            next[b].push_back(a);
        }
        // delete connections i,j, see if we can visite all the nodes without this connection
        for(auto& c:connections){
            // delete connection

            if(!BFS(c, next, n)){
                res.push_back(c);
            }
        }
        return res;
    }
    bool BFS(vector<int> c, vector<vector<int>>& next, int n){
        queue<int> q;
        vector<bool> visited(n, false);
        
        q.push(c[0]);
        visited[c[0]] = true;
        int count = 1;
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int nei:next[cur]){
                if(cur == c[0] && nei == c[1] || cur == c[1] && nei == c[0]) continue;
                if(!visited[nei]){
                    q.push(nei);
                    visited[nei] = true;
                    count++;
                }
            }
        }
        return count == n;        
    }
};
