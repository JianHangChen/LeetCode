



// sol1, my, dfs, O( (n-1)!), O(E)

class Solution {
public:
    /**
     * @param n: The number of points
     * @param G: The description of graph
     * @param S: The point S
     * @param T: The point T
     * @return: output all the paths from S to T
     */
    vector<vector<int>> getPath(int n, vector<vector<int>> &G, int S, int T) {
        vector<vector<int>> graph(n), res;
        unordered_set<int> visited;
        for(auto v:G){
            graph[v[0]].push_back(v[1]);
            graph[v[1]].push_back(v[0]);
        }
        
        for(auto& v:graph){
            sort(v.begin(), v.end());
        }
        
        vector<int> path;
        dfs(graph, res, visited, S, T, path);
        return res;
    }
    
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, unordered_set<int>& visited, int S, int T, vector<int>& path){
        
        visited.insert(S);
        path.push_back(S);

        if(S == T){
            res.push_back(path);
        }
        else{
            for(auto nei:graph[S]){
                if(visited.count(nei) == 0){
                    dfs(graph, res, visited, nei, T, path);
                }
            }
        }
            
        path.pop_back();
        visited.erase(S);
        return;
        
    }
};
