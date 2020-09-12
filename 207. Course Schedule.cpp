// sol1, O(E+V), O(E+V)
// follow up: how to get the minimum semesters we want to take
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // prerequisite[1]should take before pre[0]
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses);
        for(auto& pre:prerequisites){
            g[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        
        int validcourse = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            validcourse++;
            for(int i:g[cur]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
            
        }
        
        return validcourse == numCourses;
    }
};
