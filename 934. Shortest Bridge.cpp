//!!! my sol1, O(mn), O(mn) find and grow

class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
    int shortestBridge(vector<vector<int>>& A) {
        // visited  -1
        int m = A.size(), n = A[0].size(), step = 0;
        queue<vector<int>> q, q1;
        
        // mark first seen group -1 and push the first group to q
        bool marked = false;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(A[i][j] == 1){
                    mark(i, j, A, q, q1);
                    marked = true;
                    break;
                }
            }
            if(marked) break;
        }    
        
        
        // bfs expand the first group, return the step if we meet the second group
        while(!q.empty()){
            for(int k = q.size(); k > 0; k--){
                auto t = q.front(); q.pop();
                int x = t[0], y  = t[1], u, v;
                for(auto& dir:dirs){
                    u = x + dir[0];
                    v = y + dir[1];
                    if( 0 <= u && u < m && 0 <= v && v < n && A[u][v] != -1){
                        if(A[u][v] == 1) return step;
                        else{
                            A[u][v] = -1;
                            q.push({u, v});
                        }
                    }       
                }
            }
            step +=1;            
        }

        return step;
    }
    void mark(int i, int j, vector<vector<int>>& A, queue<vector<int>>& q, queue<vector<int>>& q1){
        q1.push({i,j}); q.push({i, j});
        A[i][j] = -1;
        int m = A.size(), n = A[0].size();
        
        while(!q1.empty()){
            auto a = q1.front(); q1.pop();
            int x = a[0], y = a[1], u, v;
            for(auto& dir:dirs){
                u = x + dir[0];
                v = y + dir[1];
                if( 0 <= u && u < m && 0 <= v && v < n && A[u][v] == 1){
                    A[u][v] = -1;
                    q1.push({u,v}); q.push({u, v});
                }
            }
        }
        
    }
};




//  [0,1]
//  [1,0]
 

// [0,1,0]
// [0,0,0]
// [0,0,1]


// [1,1,0]
// [0,0,0]
// [0,1,1]



// [1,1,1,1,1]
// [1,0,0,0,1]
// [1,0,1,0,1]
// [1,0,0,0,1]
// [1,1,1,1,1]


// [1,1,1,1,0]
// [1,1,1,1,0]
// [1,1,1,0,0]
// [1,1,1,0,0]
// [1,1,0,1,1]
