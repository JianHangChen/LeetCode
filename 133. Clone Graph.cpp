// !!! sol1.1, my, change from gy2, use Node* to Node* mapping
// use queue, O(E+V), O(V)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        q.push(node);
        Node* head = new Node(node->val);
        m[node] = head;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            auto new_node = m[cur];
            for(auto nei:cur->neighbors){
                if(m.count(nei) ==0 ){
                    m[nei] = new Node(nei->val);
                    q.push(nei);
                }
                new_node->neighbors.push_back(m[nei]);

            }
        }
        return head;
    }
};



// sol1, my, use queue, O(E+V), O(V)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        
        unordered_map<int, Node*> m;
        queue<Node*> q;
        q.push(node);
        Node* head = new Node(node->val);
        m[node->val] = head;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(auto nei:cur->neighbors){
                if(m.count(nei->val) ==0 ){
                    Node* new_nei = new Node(nei->val);
                    m[cur->val]->neighbors.push_back(new_nei);
                    m[nei->val] = new_nei;
                    q.push(nei);
                }
                else{
                    m[cur->val]->neighbors.push_back(m[nei->val]);
                }
            }
        }
        return head;
    }
};


import collections
"""
# Definition for a Node.
class Node:
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution:
    
    # sol1,dfs recursively
    def __init__(self):
        self.visited = {}
        
    def cloneGraph(self, node: 'Node') -> 'Node':
        visited = self.visited
        if node is None:
            return
        if node in visited:
            return visited[node]
        else:
            new_node = Node(node.val, [])
            visited[node] = new_node
            
        
        for neighbor in node.neighbors:
            new_node.neighbors.append( self.cloneGraph(neighbor) )
            
        
        
        return new_node
    
    # sol2, dfs iteratively
    def cloneGraph(self, node: 'Node') -> 'Node':
        visited = {}
        stack = []
        
        if node:
            stack.append(node)
            root_node = Node(node.val, [])
            visited[node] = root_node
        else:
            root_node = None
        
        while stack:
            cur = stack.pop()
            new_node = visited[cur]

            
            for neighbor in cur.neighbors:
                if neighbor in visited:
                    new_node.neighbors.append(visited[neighbor])
                else:
                    new_nei = Node(neighbor.val, [])
                    visited[neighbor] = new_nei
                    new_node.neighbors.append(new_nei)
                    stack.append(neighbor)
        return root_node
    
    # sol3, bfs iteratively
    def cloneGraph(self, node: 'Node') -> 'Node':
        visited = {}
        q = collections.deque([])
        
        if node:
            q.append(node)
            root_node = Node(node.val, [])
            visited[node] = root_node
        else:
            root_node = None
        
        while q:
            cur = q.popleft()
            new_node = visited[cur]

            
            for neighbor in cur.neighbors:
                if neighbor in visited:
                    new_node.neighbors.append(visited[neighbor])
                else:
                    new_nei = Node(neighbor.val, [])
                    visited[neighbor] = new_nei
                    new_node.neighbors.append(new_nei)
                    q.append(neighbor)
        return root_node
                
