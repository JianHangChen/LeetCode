// !!! sol1, my bfs, O(mn), O(min(m,n)) 
// the complexity analysis , fill with 1, run an example in a paper.
class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); if(m == 0) return 0;
        int n = grid[0].size();
        queue<vector<int>> q;
        int res = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n ;j++){
                if(grid[i][j] == '1'){
                    q.push({i, j});
                    res++;
                    grid[i][j] = 'v';
                    while(!q.empty()){
                        vector<int> cur = q.front(); q.pop();
                        for(auto& dir:dirs){
                            int x = cur[0] + dir[0], y = cur[1] + dir[1];
                            if( x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == '1'){
                                grid[x][y] = 2;
                                q.push({x,y});
                            }
                        }
                        
                    }
                    
                }
            }
        }
        return res;
        
        
    }
};


// import collections
// class Solution:
//     # test m = 0 or n = 0
    
//     # sol1, bfs
//     def numIslands(self, grid: List[List[str]]) -> int:
        
//         def getValidNeighbours(i, j, visited):
//             neighbours = []
//             for u, v in [(i, j+1), (i, j - 1), (i+1, j), (i-1, j)]:
//                 if (0 <= u < m) and (0 <= v < n) and (grid[u][v] == "1") and ((u, v) not in visited):
//                     neighbours.append((u, v))
//             return neighbours
        
//         def bfs(q, visited):
//             while q:
//                 i,j = q.popleft()
//                 neighbours = getValidNeighbours(i,j, visited)
//                 for neighbour in neighbours:
//                     visited.add(neighbour)
//                     q.append(neighbour)
        
//         visited = set()
//         m = len(grid)
//         if m == 0:
//             return 0
//         n = len(grid[0])
        
        
//         count = 0
//         q = collections.deque([],m*n)
        
//         for i in range(m):
//             for j in range(n):
//                 if grid[i][j] == "1" and (i, j) not in visited:
//                     count += 1
//                     q.append((i,j))
//                     visited.add((i, j))
//                     bfs(q, visited)
//         return count
    
//     # sol2, dfs, recursively
//     def numIslands(self, grid: List[List[str]]) -> int:
//         def getValidNeighbours(i, j, visited):
//             neighbours = []
//             for u, v in [(i, j+1), (i, j - 1), (i+1, j), (i-1, j)]:
//                 if (0 <= u < m) and (0 <= v < n) and (grid[u][v] == "1") and ((u, v) not in visited):
//                     neighbours.append((u, v))
//             return neighbours
        
//         def dfs(i,j, visited):
//             neighbours = getValidNeighbours(i,j, visited)
//             for neighbour in neighbours:
//                 visited.add(neighbour)
//                 dfs(neighbour[0],neighbour[1], visited)
        
//         visited = set()
//         m = len(grid)
//         if m == 0:
//             return 0
//         n = len(grid[0])
        
        
//         count = 0
        
//         for i in range(m):
//             for j in range(n):
//                 if grid[i][j] == "1" and (i, j) not in visited:
//                     count += 1
//                     visited.add((i, j))
//                     dfs(i,j, visited)
//         return count
        
