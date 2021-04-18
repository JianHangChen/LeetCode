// sol1, my, O(nlogn), O(n)
// good code, can learn c++ https://leetcode.com/problems/single-threaded-cpu/discuss/1164008/C%2B%2B-min-heap
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<int> res;
        for(int i = 0; i < n; i++) tasks[i].push_back(i); // triple become {start, duration, index}
        
        sort(tasks.begin(), tasks.end()); // nlogn
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        int i = 0; long long t = 1;
        while(!pq.empty() || i < n){ // nlogn
            if(pq.empty()){
                t = max(t, (long long) tasks[i][0]);
            }
            while(i < n && t >= tasks[i][0]){
                pq.push({tasks[i][1], tasks[i][2]}); // processing time, index, {4, 1}, {2, 2}
                i++;
            }
            auto cur = pq.top(); pq.pop();
            int duration = cur[0], idx = cur[1];
            res.push_back(idx);
            t = t + duration; // 3  
        }
        return res;
    }
};

 // [[1,2],[2,4],[3,2],[4,1]]
// |1(1-2) 2| 3 4| 5 (4 1) | 6 7 8 9 (2 4)


//[[1,2],[2,4],[3,2],[4,1]]
// step 1, sort [1 2]. [2 4] [3 2] [4 1]
// step2 pq.empty() pq = {{2 0 1}} t = 1, i = 1
// step3 cur = 2 0 1, pq = {}, duration = 2, idx = 0, earliest = 1
//      res = {0} t>= 1, t = 1 + 2 = 3
// step4 pq.empty(), t = 3, pq = {4 1 2} i = 2,  pq = {412, 2 2 3} i = 3
// cur = pq.top 2 2 3, duration  = 2, idx = 2, earliest = 3
// res = {0, 2}, t = 3 + 3 = 6, pq = {4 1 2, 1 3 4}
// cur = 1 3 4, pq ={4 1 2}, duration = 1, idx = 3, earliest = 4, i = 4
// res = {0, 2, 3}, t = 6 + 1 = 7, 
// duration = 4, idx = 1, earliest = 2 res = {0 2 3 1}
// t = 7 + 4 = 11 pq = {}
//
