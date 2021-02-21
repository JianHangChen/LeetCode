
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
