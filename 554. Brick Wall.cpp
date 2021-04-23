// !!! sol2, count end time, O(w), O(width)
// total wall: w
// width: of the wall
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int rows = wall.size();
        unordered_map<int, int> m; // end time -> count
        for(int i = 0; i < rows; i++){
            int end = 0;
            for(int j = 0; j < wall[i].size() - 1; j++){
                end += wall[i][j];
                m[end]++;
            }
        }
        int least = rows;
        for(auto it:m){
            least = min(least, rows - it.second);
        }
        return least;
    }
};

// sol1, my, O(wlogw), O(row)
// total wall: w

class Solution {
public:
    int rows;
    int leastBricks(vector<vector<int>>& wall) {
        rows = wall.size();
        int least = rows;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < rows; i++){
            pq.push({wall[i][0], i, 0}); // {endtime, i, j}
        }
        int cur = 0;
        while(!pq.empty()){
            cur = pq.top()[0];
            vector<vector<int>> next;
            
            
            while(!pq.empty() && pq.top()[0] <= cur){
                int endtime = pq.top()[0], i = pq.top()[1], j = pq.top()[2];
                if(j+1 >= wall[i].size()) return least;
                next.push_back({endtime + wall[i][j+1], i, j + 1});
                pq.pop();
            }
                        
            least = min(least, (int)pq.size());
            if(least == 0) break;
            
            for(auto& v:next){
                pq.push(v);
            }            
        }
        return least;
        
    }
};
