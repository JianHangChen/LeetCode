//!!! sol2, from ch9, O(n), O(n)

class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        vector<vector<int>> res;
        int i = 0;
        while(i < intervals.size() && intervals[i][0] < newInterval[0]) i++;
        intervals.insert(intervals.begin() + i, newInterval);  // get an interval list sorted by the first element

        for(auto& interval:intervals){
            if(res.empty() || res.back()[1] < interval[0]){
                res.push_back(interval);
            }
            else{
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        return res;
    }
};

//! sol1.1, from gy1 O(n), O(n), three steps, 1. find no change < newInterval[0], 2. after find change, update smallest and largest, 
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size(), i = 0;
        while(i < n && intervals[i][1] < newInterval[0]) res.push_back(intervals[i++]);
        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back({newInterval[0], newInterval[1]});
        while(i < n) res.push_back(intervals[i++]);
        return res;
    }
};


//sol1, from gy1 O(n), O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();

        int i = 0, start = newInterval[0], end = newInterval[1];
        
        while(i < n){
            if( intervals[i][1] < newInterval[0]){
                res.push_back(intervals[i]);
            }
            else{
                start = min(newInterval[0], intervals[i][0]);
                break;
            }
            i++;
        }

        while(i < n){
            if(newInterval[1] < intervals[i][0]){
                break;
            }
            else if(newInterval[1] < intervals[i][1]){
                end = intervals[i][1];
                i++;
                break;
            }
            i++;
        }
        res.push_back({start, end});
        while(i < n){
            res.push_back(intervals[i++]);
        }

        return res;

    }
};
