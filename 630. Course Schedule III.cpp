// !!! sol3, from sol6, priority_queue
// O(nlogn), O(n)
struct CMP{
    bool operator()(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
} cmp;
class Solution {
public:
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<vector<int>> pq;
        int n = courses.size();
        int curTime = 0;
        for(int i = 0; i < n; i++){
            int t = courses[i][0], d = courses[i][1]; // duration, deadline
            if(curTime + t <= d){ // this course i is ok
                curTime += t;
                pq.push(courses[i]);
            }
            else{
                if(!pq.empty()){
                    int t0 = pq.top()[0]; 
                    if(t0 > t){
                        pq.pop();
                        curTime += -t0 + t;
                        pq.push(courses[i]);                        
                    }
                }
            }
        }
        return pq.size();
    }
};

// sol2, memorized dfs, from sol1, O(n*d), O(n*d) -> 10^* tle
// d is maximum value of the end day
// struct CMP{
//     bool operator()(vector<int>& a, vector<int>& b){
//         return a[1] < b[1];
//     }
// } cmp;
// class Solution {
// public:
//     vector<unordered_map<int, int>> memo;
    
//     int scheduleCourse(vector<vector<int>>& courses) {
//         int n = courses.size();
//         memo.resize(n);
//         sort(courses.begin(), courses.end(), cmp);
//         return helper(courses, 0,  1);
        
//     }
    
//     int helper(vector<vector<int>>& courses, int i, int curtime){ // howmany courses can be taken starting from ith with curtime
//         if(i == courses.size()){
//             return 0;
//         }

//         if(memo[i].count(curtime) > 0) return memo[i][curtime];
        
//         int res = helper(courses, i+1, curtime);
        
//         int t = courses[i][0], d = courses[i][1];
//         if(curtime + t - 1 <= d){ // ok to take course i
//             res = max(res, 1 + helper(courses, i+1, curtime+t));            
//         }
               
//         memo[i][curtime] = res;
//         return res;
//     }
    
    
    
// };


// 1~100th day course1 [100 200] -> start [1 100]th day
// 101~1100th days course3 [1000 1250] -> start [1 250]thday
// 1101~1300th days cours2 [200 1300] -> start [1 1100]th day
// 1301~3301tgdats cannot finish course 4 [2000 3200] -> start [1, 1200]th day


// 1~100th day course1 [1100 1200] -> start [1 100]th day
// 101~1100th days course3 [80 980] -> start [1 900]thday
// 1101~1300th days cours2 [200 1300] -> start [1 1100]th day
// 1301~3301tgdats cannot finish course 4 [2000 3200] -> start [1, 1200]th day



// sol1, my, dfs, tle, O(n!), O(n*n!)

// class Solution {
// public:
//     int res = 0;
//     int scheduleCourse(vector<vector<int>>& courses) {
//         int n = courses.size();
//         unordered_set<int> toTake;
//         for(int i = 0; i < n; i++) toTake.insert(i);
//         helper(courses, toTake,  1, 0);
//         return res;
//     }
//     void helper(vector<vector<int>>& courses, unordered_set<int>& toTake, int curtime, int totalcourse){
//         res = max(res, totalcourse);
//         unordered_set<int> s(toTake);
//         for(int i:toTake){
//             int t = courses[i][0], d = courses[i][1];
//             if(curtime + t - 1 <= d){ // ok to take course i
//                 s.erase(i);
//                 totalcourse++;
//                 helper(courses, s, curtime+t, totalcourse);    
//                 totalcourse--;
//                 s.insert(i);
//             }
//             else{
//                 s.erase(i); // i is not eligible for next round
//             }
//         }
//     }
// };
