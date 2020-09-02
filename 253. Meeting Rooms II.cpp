
//!!! my sol1, same as wp sol2, O(nlogn), O(n) sort
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0;
        vector<vector<int>> schedule;
        for(auto& interval:intervals){
            schedule.push_back({interval[0], 1});
            schedule.push_back({interval[1], 0});
        }
        sort(schedule.begin(), schedule.end());
        int cur = 0;
        for(auto& s:schedule){
            if(s[1] == 1) cur++;
            else cur--;
            res = max(cur, res);
        }
        return res;
        
    }
};
// sol2,  sort and priority queue, from wp sol1, O(nlogn), O(n)
class Solution {
public:
    struct CMP{
        bool operator()(const vector<int>& a, const vector<int>& b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] > b[1];
        }
    } cmp;
    int minMeetingRooms(vector<vector<int>>& intervals) {     
        priority_queue<vector<int>, vector<vector<int>>, CMP> pq;
        int i = 0;
        int res = 0;
        sort(intervals.begin(), intervals.end());
        while(i < intervals.size()){
            if(pq.empty() || pq.top()[1] > intervals[i][0]) pq.push(intervals[i++]);
            else pq.pop();
            res = max(res, (int)pq.size());
        }
        return res;
    }
};
