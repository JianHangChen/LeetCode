// folloup return all courses
class Solution {
public:
    int n;
    vector<vector<int>> res = {};
    vector<vector<int>> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        unordered_set<int> s;
        vector<vector<int>> nextCourse(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        for(auto& pre:prerequisites){
            nextCourse[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) s.insert(i);
        }
        
        vector<int> path = {};
        
        dfs(s, nextCourse, inDegree, path);
        
        return res;
    }
    
    void dfs(unordered_set<int>& s, vector<vector<int>>& nextCourse, vector<int>& inDegree, vector<int>& path){
        if(path.size() == n) res.push_back(path);
        
        unordered_set<int> t(s);
        for(int cur:s){
            t.erase(cur);
            path.push_back(cur);
            for(int nei:nextCourse[cur]){
                inDegree[nei]--;
                if(inDegree[nei] == 0) t.insert(nei);
            }
            
            dfs(t, nextCourse, inDegree, path);
            for(int nei:nextCourse[cur]){
                inDegree[nei]++;
            }     
            path.pop_back();
            t.insert(cur);
        }
        
    }
};

void show(vector<vector<int>>& res){
    cout << "show" << endl;

    for(auto& a:res){
        for(int i:a){
            cout << i << ", ";
        }
        cout << endl;
    }
    cout << "show end" << endl;
}

int main(){
    vector<vector<int>> pres = {{1,0},{2,0},{3,1},{3,2}}; 
    // {{1, 0}, {0, 1}}; // 0 -> 1
    Solution sol;
    auto res = sol.findOrder(4, pres);
    show(res);
    
    return -1;
}

// sol1, my bfs, O(E+V), O(E+V)
// [0, 1] 1->0
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<vector<int>> nextCourse(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto& pre:prerequisites){
            nextCourse[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            res.push_back(cur);
            for(int nei:nextCourse[cur]){
                inDegree[nei]--;
                if(inDegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        if(res.size() == numCourses) return res;
        return {};        
    }
};
