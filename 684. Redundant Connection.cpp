

// sol1.1,  my Union Find modified by gy, O(n), O(n)
class Solution {
private:
  unordered_map<int, int> root;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        for(auto edge:edges){
         int root0 = find(edge[0]), root1 = find(edge[1]);
         cout<< root0 << "," << root1 << endl;
         if(root0 == root1){
            return edge;
          }
          else{
            root[root1] = root0; // union
          }
        }
        return {};
    }

    //template1!!!
    int find(int p){
      while(root.count(p) > 0){
        p = root[p];
      }
      return p;
    }
};








// sol1, !!!!!!! my Union Find, O(n), O(n)
class Solution {
public:
    unordered_map<int, int> root;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto& e:edges){
            root[e[0]] = e[0];
            root[e[1]] = e[1];
        }
        for(auto& e:edges){
            if(find(e[0]) == find(e[1])) return e;
            uni(e[0], e[1]);
        }
        return {};
        
    }
    int find(int a){
        if(root[a] == a) return a;
        return root[a] = find(root[a]);
    }
    void uni (int a, int b){
        root[find(a)] = root[find(b)];
    }
};



// sol2. DFS, O(n^2), O(n), from gy

class Solution {
private:
  unordered_map<int, unordered_set<int> > m;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      for(auto edge:edges){
        int v = edge[0], u = edge[1];
        if(hasCycle(v, u, -1)) return edge;
        else{
          m[v].insert(u);
          m[u].insert(v);
        }
      }
      return {};
    }

    bool hasCycle(int v, int u, int prev){
      if(m[v].count(u) > 0) return true;

      for(auto s:m[v]){
        if(s == prev) continue; //!!
        if( hasCycle(s, u, v) ) return true;
      }
      return false;
    }
};


// sol3, dfs, using queue
class Solution {
private:
  unordered_map<int, unordered_set<int> > m;
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      for(auto edge:edges){
        int v = edge[0], u = edge[1];
        
        queue<vector<int>> q;
        int prev = -1;
        while(v != -1 || !q.empty()){
          if(v == -1){
            v = q.front()[0];
            prev = q.front()[1];
            q.pop();
          }

          if(m[v].count(u) > 0) return edge;
          for(auto s:m[v]){
            if(s == prev) continue;
            q.push({s, v});
          }
          v = -1;
        }
        v = edge[0], u = edge[1];
        m[v].insert(u);
        m[u].insert(v);
      }

      return {};
    }
};


