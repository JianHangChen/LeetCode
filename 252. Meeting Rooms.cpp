

// sol1, my, O(nlogn), O(1)
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return true;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size() - 1; i++){
            if(intervals[i][1] > intervals[i+1][0]) return false;
        }
        return true;
    }
};
