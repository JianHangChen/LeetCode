// sol2, bfs
class Solution {

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        if(n == 0) return true;
        queue<int> q({0});
        unordered_set<int> visited({0});

        while(!q.empty()){
            int key = q.front(); q.pop();
            for(int k:rooms[key]){
                if(visited.count(k) == 0){
                    q.push(k);
                    visited.insert(k);
                }
            }

        }
        return visited.size() == n;

    }

};

// sol1, dfs
class Solution {
private:
    unordered_set<int> visited;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        dfs(0, rooms);
        return visited.size() == n;
    }
    void dfs(int room,  vector<vector<int>>& rooms){
        if(visited.count(room)) return;
        visited.insert(room);
        for(int key:rooms[room]){
            dfs(key, rooms);
        }
        return;
    }
};

class Solution:
    
    # sol1, dfs recursive
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        N = len(rooms)
        visited = [False] * N
        visited[0] = True
        
        def dfs(room):
            for key in rooms[room]:
                if not visited[key]:
                    visited[key] = True
                    dfs(key)
        dfs(0)
        if False in visited:
            return False
        return True
    
    # sol2, dfs iterative
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        N = len(rooms)
        visited = [False] * N
        visited[0] = True
        
        stack = [0]
        while stack:
            room = stack.pop()
            for key in rooms[room]:
                if not visited[key]:
                    visited[key] = True
                    stack.append(key)
        return all(visited) 
