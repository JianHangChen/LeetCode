// sol4, union find

class Solution{
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes){
        vector<vector<int>> graph(N+1);
        for(auto dislike:dislikes){
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        vector<int> root(N+1);
        for(int i = 1; i <= N; i++) root[i] = i;
        for(int i = 1; i <= N; i++){
            if(graph[i].size() == 0) continue;
            int x = find(root, i), y = find(root, graph[i][0]);
            if(x == y) return false; // !!!
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

// sol3, bfs

// [2,3], [1,3], [1,2]
class Solution{
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes){
        vector<vector<int>> graph(N+1);
        for(auto& dislike:dislikes){
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        vector<int> colors(N+1, 0);
        for(int i = 1; i <= N; i++){
            queue<int> q;
            if(colors[i] == 0){
                q.push(i);
                colors[i] = 1;
            }
            while(!q.empty()){
                int cur = q.front(); q.pop();
                for(auto nei:graph[cur]){
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


//!!! sol2, my, after finish 785, dfs and build graph, O(N + E), O(N+E)

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1);
        for(auto& dislike : dislikes){
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        vector<int> groups(N + 1, 0);
        for(int i = 1; i <= N; i++){
            if(groups[i] == 0 && !dfs(graph, i, groups, 1)) return false;      
        }
        return true;
    }
    bool dfs(vector<vector<int>>& graph, int i, vector<int>& groups, int group){
        groups[i] = group;
        for(int nei:graph[i]){
            if(groups[nei] == groups[i]) return false;
            if(groups[nei] == 0 && !dfs(graph, nei, groups, -group)) return false;
                        
        }        
        return true;
    }
};

// sol1, my wrong, not considering the following example, the adjunct matrix in sol2 solve this problem
// 
// example:  [1,2],  [3,4], [1,5], [4,5]
// group1[1,3], group[2,4,5]
// but it could be like [1,4] [2,3,5]
// class Solution {
// public:
//     bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
//         unordered_set<int> group1, group2;
//         for(auto& dislike:dislikes){
//             if(group1.count(dislike[0]) > 0 && group1.count(dislike[1]) > 0 || group2.count(dislike[0]) > 0 && group2.count(dislike[1]) > 0) return false;
//             if(group2.count(dislike[0]) > 0){
//                 group1.insert(dislike[1]);
//             }
//             else if(group1.count(dislike[0]) > 0){
//                 group2.insert(dislike[1]);
//             }
//             else{
//                 if(group2.count(dislike[1] > 0)){
//                     group1.insert(dislike[0]);
//                 }
//                 else if(group1.count(dislike[1]) > 0){
//                     group2.insert(dislike[0]);
//                 }
//                 else{
//                     group1.insert(dislike[0]);
//                     group2.insert(dislike[1]);
//                 }                   
//             }
//         }
//         return true;
//     }
// };
