// !!!sol1.1, O(nlogn), O(n)
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue
// n is events.size()
//  [[1,2],[1,2],[3,3],[1,5],[1,5]]
// [[1,2],[1,2],[1,5],[1,5], [3,3]]

// [[1,2],[2,3],[3,4]]

//  [[1,1],[1,1] [2,3],[5,6],] -> 3
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int count = 0;
        sort(events.begin(), events.end());
        int i = 0; // event index
        multiset<int> s; // end date
        int day = 1;
        while(!s.empty() || i < events.size()){
            if(s.empty()) day = events[i][0];
            
            // add valid event
            while(i < events.size() && day == events[i][0]){
                s.insert(events[i++][1]);
            }

            // remove invalid event (endday expire)
            while( !s.empty() && *s.begin() < day ) s.erase(s.begin());
            
            // attend the current day for event with earliest end day
            if(!s.empty()){
                s.erase(s.begin());
                count++;
            }
            else if(i == events.size()) break;
            day++;
        }
        return count;
    }
};




// sol1, O(d+nlogn), O(n)
// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue
// d is the range of events
// n is events.size()
//  [[1,2],[1,2],[3,3],[1,5],[1,5]]
// [[1,2],[1,2],[1,5],[1,5], [3,3]]

// [[1,2],[2,3],[3,4]]

//  [[1,1],[1,1] [2,3],[3,4],] -> 3
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int count = 0;
        sort(events.begin(), events.end());
        int i = 0; // event index
        multiset<int> s; // end date
        for(int day = 1; day <= 1e5; day++){
            // add valid event
            while(i < events.size() && day == events[i][0]){
                s.insert(events[i++][1]);
            }
            // remove invalid event (endday expire)
            while( !s.empty() && *s.begin() < day ) s.erase(s.begin());
            // attend the current day for event with earliest end day
            if(!s.empty()){
                s.erase(s.begin());
                count++;
            }
            else if(i == events.size()) break;
        }

        return count;
    }
};

