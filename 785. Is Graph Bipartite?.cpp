// // sol3, union find
class Solution{
public:
    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> root(n);
        for(int i = 0; i < n; i++) root[i] = i;
        for(int i = 0; i < n; i++){
            if(graph[i].size() == 0) continue;
            int x = find(root, i), y = find(root, graph[i][0]);
            for(int j = 1; j < graph[i].size(); j++){
                int parent = find(root, graph[i][j]);
                if(parent == x) return false;
                root[parent] = y;
            }
        }
        return true;        
    }
    
    int find(vector<int>& root, int i){
        return root[i] == i ? i : find(root, root[i]);
    }
};


//sol2, bfs, from gy2, O(N+E), O(N)

class Solution{
public:
    bool isBipartite(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> colors(n, 0);
        for(int i = 0; i < n; i++){
            queue<int> q;
            if(colors[i] != 0) continue;
            q.push(i);
            colors[i] = 1;
            while(!q.empty()){
                int cur = q.front(); q.pop();
                
                for(int nei:graph[cur]){
                    if(colors[nei] == colors[cur]) return false;
                    if(colors[nei] == 0){
                        colors[nei] = -colors[cur];
                        q.push(nei);                    
                    }
                }
            }
        }
        return true;     
    }
};


// sol1, !!! dfs, from gy1, dye, O(N+E), O(N)
// N is the number of nodes, E is the number of edges
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> groups(n, 0);
        
        //!!!
        for(int i = 0; i < n; i++){
            if(groups[i] ==0 && !setGroup(groups, i, 1, graph)) return false;
        }
        
        return true;
    }
    
    bool setGroup(vector<int>& groups, int node, int group, vector<vector<int>>& graph){
        if(groups[node] != 0){
           if(groups[node] != group) return false;
        }
        else{
            groups[node] = group;
            for(auto nei:graph[node]){
                if(!setGroup(groups, nei, -group, graph)) return false; 
            }
        }
                
        return true;   
        
    }
    
};
