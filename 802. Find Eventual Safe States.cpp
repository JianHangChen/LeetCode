//!!sol1, O(N+E), O(N)

class Solution{
private:
    unordered_map<string,int> color = {{"white",0}, {"gray",1}, {"black",2}}; //!!!use comma
public:
    bool dfs(int i, vector<vector<int>>& graph, vector<int> &status){
        if(status[i] == color["gray"]){
            return false;
        }
        if(status[i] == color["black"]){
            return true;
        }
        status[i] = color["gray"];
        for(auto j:graph[i]){
            if(dfs(j, graph, status) == false){
                return false;
            }          
        }
        status[i] = color["black"];
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph){
        int n = graph.size();
        vector<int> res;
        vector<int> status(n, color["white"]);
        
        for(int i = 0; i < n; i++){
            dfs(i, graph, status);
            if(status[i] == color["black"]){
                res.push_back(i);
            }
        }
        
        return res; 
    }
    
    
};
//sol2, reverse graph
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> results;
        vector<bool> safe(n, false);
            
        vector<unordered_set<int>> g(n, unordered_set<int>()), rev = g;//!!!
        queue<int> q;
        
        for(int i = 0; i < n; i++){
            if(graph[i].empty()){
                q.push(i);
            }
            for(auto j:graph[i]){
                g[i].insert(j);
                rev[j].insert(i);
            }
        }
        
        while(!q.empty()){ // queue should use q.empty()
            int i = q.front(); q.pop();
            safe[i] = true;
            for(auto j:rev[i]){
                g[j].erase(i); //!!!erase not rem
                if(g[j].empty()){
                    q.push(j); //push not spp
                }
            }
        }
        
        for(int i = 0; i < n; i++){
            if(safe[i]){
                results.push_back(i); //!!push_back not app
            }
        }
        return results;
        
    }
};
