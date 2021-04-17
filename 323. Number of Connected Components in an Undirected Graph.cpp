// sol1, my, union find, O(elogv), O(v)
class Solution {
public:
    vector<int> parent;
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) parent.push_back(i);
        for(auto& e:edges){
            uni(e[0], e[1]);
        }
        int count = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i) count++;
        }
        return count;
    }
    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void uni(int a, int b){
        parent[find(a)] = parent[find(b)];
    }
};
