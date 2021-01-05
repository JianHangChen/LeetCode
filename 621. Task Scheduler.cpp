
//  sol2, from gy2, O(n), O(1)
// https://leetcode.com/problems/task-scheduler/discuss/104500/java-on-time-o1-space-1-pass-no-sorting-solution-with-detailed-explanation
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> count(26);
//         for(char task:tasks) count[task - 'A']++;
//         sort(count.begin(), count.end());
//         int mx = count[25], mxcount = 0;
//         for(int i = 25; i >= 0; i--){
//             if(count[i] == mx) mxcount++;
//             else break;
//         }
//         int parts = mx - 1;
//         int idle = max(0, n - (mxcount - 1));
//         int total_idle = idle * parts;
//         int remaining_tasks = tasks.size() - mx *mxcount;
//         int remaining_idle = total_idle - remaining_tasks;
        
//         if(remaining_idle <= 0) return tasks.size();
//         return tasks.size() + remaining_idle;
//     }
// };

// !!! sol1, from gy1, O(n), O(1)
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> frequency(26);
        for(char task:tasks) frequency[task - 'A']++;
        sort(frequency.begin(), frequency.end());
        int maxAppear = 0, maxFrequency = frequency[25];
        for(int i = 25; i >= 0; i--){
            if(frequency[i] == maxFrequency) maxAppear++;
            else break;
        }
        return max((int)tasks.size(), (n+1) * (maxFrequency - 1) + maxAppear ) ;
        
    }
};



// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         vector<int> v(26,0);
//         for(char task:tasks){
//             v[task-'A']++;
//         }
        
//         int max_step = 0;
//         int pre_step = -1;
//         while(true){
//             int max_idx = -1, m = 0;
//             int i = 0;
//             for(; i < 26; i++){
//                 if(v[i] > m){
//                     m = v[i];
//                     max_idx = i;
//                 }
//             }
//             if(i == 26) break;
//             while(v[i] != 0){
//                 step = 
//                 v[i]--;
//             }
            
//             max_step = max(max_step, )
//         }
        
        
//     }
// };
