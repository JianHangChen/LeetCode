// sol1, my, same as sol3 but path compression
// O(N^2), O(N) amortized find
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 1;
        
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    uni(i, j);
                }
            }
        }
        unordered_set<int> s;
        
        for(int i = 0; i < n; i++){
            s.insert(find(i));
        }
        return s.size();
    }
    
    unordered_map<int, int> parent;
    
    
    int find(int i){
        if(parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }
    void uni(int x, int y){
        parent[find(x)] = parent[find(y)];
    }
    
};

// 1 1 0
// 1 1 0
// 0 0 1
