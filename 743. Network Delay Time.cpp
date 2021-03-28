// sol2, bellman-ford with queue, O(EV) worst case, average O(E+V), O(V)

class Solution{
public:
    int networkDelayTime(vector<vector<int>> & times, int N, int K){
        queue<int> q;
        vector<bool> onqueue(N+1, false);
        
        vector<int> dists(N+1, INT_MAX);
        dists[K] = 0;
        
        unordered_map<int, vector<vector<int>> > edges;
        for(auto time:times){
            int u = time[0], v = time[1], w = time[2];
            edges[u].push_back({v,w});
        }

        q.push(K);
        onqueue[K] = true;
        
        for(int i = 0; i < N; i++){
            if(q.empty()) break;
            
            int l = q.size();
            for(int j = 0; j < l; j++){
                int u = q.front(); q.pop();
                onqueue[u] = false;
                for(vector<int>& edge:edges[u]){
                    int v = edge[0], w = edge[1];
                    if(dists[v] > dists[u] + w){ // sometimes carefull about INT_MAX + number;
                        dists[v] = dists[u] + w;
                        if(!onqueue[v]) q.push(v);
                    }
                }
            }       
        }
        
        int res = 0;
        for(int i = 1; i <= N; i++){
            if(dists[i] == INT_MAX) return -1;
            res = max(res, dists[i]);
        }
        return res;
    }
};


//!!! sol1, dijkstra, my
O(ElogV),  O(E+V)
https://leetcode.com/problems/network-delay-time/discuss/174339/c%2B%2B-Easy-to-understand-Dijkstra's-algorithm

class Solution {
public:
    struct CMP{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[1] > b[1]; // carefull!!
        }
    };
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        vector<bool> visited (N+1, false);
        
        unordered_map<int, vector< pair<int, int> > > edges;        
        for(auto& time:times){
            edges[time[0]].push_back( {time[1], time[2]} );
        }
        
        vector<int> distTo(N+1, INT_MAX);
        distTo[K] = 0;
        

        priority_queue<vector<int>, vector<vector<int>>, CMP> pq;
        
        pq.push({K, 0});
        
        while(!pq.empty()){
            int v = pq.top()[0]; pq.pop();
            if(visited[v]) continue;
            visited[v] = true;
            
            for(auto& edge: edges[v]){
                int u = edge.first, w = edge.second;
                if(distTo[u] > distTo[v] + w){
                    distTo[u] = distTo[v] + w;
                    pq.push({u, distTo[u]});
                }
            }
            
        }
        
        int res = 0;
        for(int i = 1; i <= N; i++){
            if(distTo[i] == INT_MAX) return -1;
            res = max(res, distTo[i]);   
        }
        return res;
    }
};




// sol2, bad, from sol2, pure dfs + sort
// O(N^N+ElogE), O(N+E)
class Solution {
private:
    struct{
        bool operator()( vector<int> & a,  vector<int> & b){
            return a[1] < b[1];
        }
        
    } cmp;
    vector<int> dists;
    unordered_map<int, vector< vector<int> > > edges;

public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        
        dists.resize(N+1, INT_MAX);
        
        for(vector<int>& time:times){
            edges[time[0]].push_back({time[1],time[2]});
        }
        
        dfs(K,0);
        
        int res = 0;
        for(int i = 1; i <= N; i++){
            if(dists[i] == INT_MAX) return -1;
            res = max(res, dists[i]);
        }
        return res;

    }
    void dfs(int K, int update_time){
        if(update_time >= dists[K]) return;
        dists[K] = update_time;
        
        sort(edges[K].begin(), edges[K].end(), cmp); // sort will speed up
        
        for(vector<int>& edge:edges[K]){
            int u = edge[0], w = edge[1];
            dfs(u, w+dists[K]);
        }        
    }
};


