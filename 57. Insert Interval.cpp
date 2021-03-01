// !sol3, binary search, O(n+logn), O(n)
// a good way to practice binary search
class Solution{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        int n = intervals.size();
        vector<vector<int>> res;
        if(n == 0){
            res.push_back(newInterval);
            return res;
        }
        // find the  leftIdx which has the intervals[1] >= newInterval[0]
        int l = 0, h = n;
        
        // 1 3 5 6 9
        // start = 5.5
        while(l < h){ // intervals[mid].end >= new.start
            int mid = l + (h - l) / 2;
            if(newInterval[0] <= intervals[mid][1] ){
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }
        int leftIdx = l;
        // find the rightIdx which has the intervals[0] <= new.end
        // 1 3 5 6 9
        // end = 4
        l = -1; h = n - 1;
        while(l < h){
            int mid = l + (h - l + 1) / 2;
            if(intervals[mid][0] <= newInterval[1]){
                l = mid;
            }
            else{
                h = mid - 1;
            }
        }
        int rightIdx = l;
        
        if(leftIdx != n) newInterval[0] = min(newInterval[0], intervals[leftIdx][0]);
        if(rightIdx!= -1) newInterval[1] = max(newInterval[1], intervals[rightIdx][1]);
        
        int i = 0;
        while(i < leftIdx) res.push_back(intervals[i++]);
        res.push_back(newInterval);
        i = rightIdx+1;
        while(i < n) res.push_back(intervals[i++]);
        
        return res;
    }
};


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
