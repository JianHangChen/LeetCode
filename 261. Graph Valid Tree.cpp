
// graph theory
// a tree has the following three properties:
// 1. connected 2. no cycle 3. n-1 edges
// any of the above two conditions could lead to a tree!!!


// sol4, union find, 
// use property 1 and 2
class Solution {
public:
    vector<int> father;
    int find(int i){
        if(i == father[i]) return i;
        return father[i] = find(father[i]);
    }
    bool unionij(int i, int j){
        int rooti = find(i), rootj = find(j);
        if(rooti == rootj) return false;
        father[rootj] = rooti;
        return true;
    }
    bool validTree(int N, vector<vector<int>>& edges) {
        if(edges.size() != N-1) return false;
        for(int i = 0; i < N; i++) father.push_back(i);
        for(auto& edge:edges){
            if(!unionij(edge[0], edge[1])) return false;
        }        
        return true;
    }
};


// !!! sol3, from sol2 O(V), O(V)
// E = V - 1, for advanced graph theory, there should only be V-1 edges
// using property of 1 and 3, don't care about the cycle, no need to erase for trival cycle compare to my sol2
// adjacency list + bfs
class Solution {
public:
    bool validTree(int N, vector<vector<int>>& edges) {
        if(edges.size() != N - 1) return false;
	    vector<unordered_set<int>> g(N);//change to adjacency list
	    for(auto& edge:edges){
	        g[edge[0]].insert(edge[1]); 
            g[edge[1]].insert(edge[0]);
        }
        queue<int> q({0});
        unordered_set<int> visited({0});

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int nei:g[cur]){
                if(visited.count(nei) > 0) continue;
                q.push(nei);
                visited.insert(nei);
            }            
        }
        
        return visited.size() == N;        
    }
};


// ! sol2, from sol1, O(V), O(V), adjacency list + bfs, similar to sol1
// E = V - 1, for advanced graph theory, there should only be V-1 edges
// class Solution {
// public:
//     bool validTree(int N, vector<vector<int>>& edges) {
//         if(edges.size() != N - 1) return false;
// 	    vector<unordered_set<int>> g(N);//change to adjacency list
// 	    for(auto& edge:edges){
// 	        g[edge[0]].insert(edge[1]); 
//             g[edge[1]].insert(edge[0]);
//         }
//         queue<int> q({0});
//         unordered_set<int> visited({0});

//         while(!q.empty()){
//             int cur = q.front(); q.pop();
//             for(int nei:g[cur]){
//                 if(visited.count(nei) > 0) return false; // find cycle
//                 q.push(nei);
//                 visited.insert(nei);
//                 g[nei].erase(cur);
//             }            
//         }
        
//         return visited.size() == N;        
//     }
// };


// my sol1, O(V^2) for final not connected check, O(V^2)
// cons: 1. using adjacency matrix is inefficient 2. extra step for single point case
// class Solution {
// public:
//     bool validTree(int N, vector<vector<int>>& edges) {
// 	    vector<vector<int>> g(N, vector<int> (N, 0) );
// 	    for(auto& edge:edges){
// 	        g[edge[0]][edge[1]] = 1;
//             g[edge[1]][edge[0]] = 1; // adjacency matrix
//         }
//         for(int i = 0; i < N; i++) g[i][i] = 1;
        
        
//         queue<int> q;
//         vector<bool> visited(N, false);
//         visited[0] = true;
//         q.push(0);

//         while(!q.empty()){
//             int cur = q.front(); q.pop();
//             for(int i = 0; i < N ; i++){
//                 if(i == cur) g[i][i] = -1;
                
//                 if( g[cur][i] == 1){
//                     if(visited[i]) return false; // find cycle
//                     g[cur][i] = -1; g[i][cur] = -1;
//                     q.push(i);
//                     visited[i] = true;
//                 }
//             }
//         }
        
//         for(int i = 0; i < N; i++){
//             for(int j = 0; j < N ; j++){
//                 if(g[i][j] == 1) return false; // find connected or not
//             }
//         }
        
//         return true;        
//     }
// };
