
// sol1, my, same as sol3 but path compression
// O(N^2), O(N) amortized find
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        for(int i = 0; i < n; i++) parent[i] = i;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]){
                    uni(i, j);
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < n; i++){
            if(find(i) == i) res++;
        }
        return res;
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

