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
