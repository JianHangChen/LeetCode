// sol1, my, bfs
class Solution {
    
public:
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*>& graph) {
        vector<DirectedGraphNode*> topOrder;
        queue<DirectedGraphNode*> q;
        
        unordered_map<DirectedGraphNode*, int> in;
        
        for(auto node:graph){
            if(in.count(node) == 0) in[node] = 0;
            for(auto nei:(node->neighbors)){
                in[nei]++;
            }
        }
        for(auto node:graph){
            if(in[node] == 0){
                q.push(node);
            }
        }

        DirectedGraphNode* cur;
        while(!q.empty()){
            cur = q.front(); q.pop();
            topOrder.push_back(cur);
            for(auto neighbor:(cur->neighbors)){
                in[neighbor]--;
                if(in[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return topOrder;
    }
};
