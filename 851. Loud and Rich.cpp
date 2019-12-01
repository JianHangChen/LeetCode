// !sol3, bfs, from gy2
class Solution{
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet){
        int N = quiet.size();
        vector<int> res(N, -1), inOrder(N, 0);
        unordered_map<int, vector<int>> poorer;
        queue<int> q;
        
        for(auto rich:richer){
            poorer[rich[0]].push_back(rich[1]);
            inOrder[rich[1]]++;
        }
        
        for(int i = 0; i < N; i++){
            if(inOrder[i] == 0) q.push(i);
            res[i] = i;
        }
        
        while(!q.empty()){
            int richer = q.front(); q.pop();
            
            for(int poor:poorer[richer]){
                inOrder[poor]--;
                if(inOrder[poor] == 0) q.push(poor);
                
                if(quiet[richer] < quiet[poor]){
                    quiet[poor] = quiet[richer];
                    res[poor] = res[richer];
                }
            }
            
        }
        return res;
    }
    
};

//!!!! sol2, directed graph, dfs, from gy1, O(n), O(n)
class Solution{
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet){
        int N = quiet.size();
        vector<vector<int>> richer_map(N);
        vector<int> res(N, -1);
        for(auto& v:richer){
            richer_map[v[1]].push_back( v[0] );
        }
        
        for(int i = 0; i < N; i++){
            dfs(richer_map, i, quiet, res);
        }
        return res;
    }
    
    int dfs(vector<vector<int>>& richer_map, int source, vector<int>& quiet, vector<int>& res){
        if(res[source] != -1) return res[source];
        
        int idx = source;
        
        for(int richer:richer_map[source]){
            int idx_richer = dfs(richer_map, richer, quiet, res);
            if(quiet[idx] > quiet[idx_richer]){
                idx = idx_richer;
            }
        }
        res[source] = idx;
        return idx;        
    }
};


//sol1,  my dfs, TLE
// class Solution {
// public:
//     vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
//         int N = quiet.size();
//         vector<int> res(N);
//         for(int i = 0; i < N; i++) res[i] = i;

//         vector<vector<int>> poorer(N);
        
//         for(auto v:richer){
//             poorer[v[0]].push_back(v[1]);
//         }
        
//         for(int i = 0; i < N; i++){
//             dfs(poorer, i, i, res,  quiet);
            
//         }
//         return res;
//     }
    
//     void dfs(vector<vector<int>>& poorer, int source, int target, vector<int>& res, vector<int>& quiet){
//         if(quiet[source] <= quiet[target]){
//             if(quiet[source] < quiet[target]){
//                 quiet[target] = quiet[source];
//                 res[target] = source;                
//             }
//             for(int p:poorer[target]){
//                 dfs(poorer, source, p, res, quiet);
//             }
//         }
//     }
// };
