

//!!! my, sol1.1, hash+binarysearch
// get: O(logn)
// set: O(1)
// https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C%2B%2B-3-lines-hash-map-%2B-map
struct CMP{
    bool operator()(const pair<int, string>& a, const pair<int, string>& b){
        return a.first < b.first;
    }
} cmp;
#include <algorithm>
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector< pair<int, string> > > ts;    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ts[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(ts.count(key) == 0) return "";
        auto ub = upper_bound(ts[key].begin(), ts[key].end(), pair<int, string> (timestamp, ""), cmp);
        return ub == ts[key].begin() ? "" : prev(ub)->second; //!!check if it is begin
        
    }
};


// sol2, same as sol2
//https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C%2B%2B-3-lines-hash-map-%2B-map
// get: O(logn)
// set: O(logn)
// class TimeMap {
// public:
//     unordered_map<string, map<int, string> > ts;    
    
//     void set(string key, string value, int timestamp) {
//         ts[key][timestamp] = value;
//     }
    
//     string get(string key, int timestamp) {
//         if(ts.count(key) == 0) return "";
//         auto ub = ts[key].upper_bound(timestamp);
//         return ub == ts[key].begin() ? "" : prev(ub)->second;         //!!check if it is begin
//     }
// };



// my, sol1, hash+binarysearch
// get: O(logn)
// set: O(1)
// #include <algorithm>
// class TimeMap {
// public:
//     /** Initialize your data structure here. */
//     unordered_map<string, string> m;
//     unordered_map<string, vector<int>> ts;
    
//     TimeMap() {
        
//     }
    
//     void set(string key, string value, int timestamp) {
//         m[key+to_string(timestamp)] = value;
//         ts[key].push_back(timestamp);
//     }
    
//     string get(string key, int timestamp) {
//         if(ts.count(key) == 0) return "";
//         auto ub = upper_bound(ts[key].begin(), ts[key].end(), timestamp);
//         return ub == ts[key].begin() ? "" : m[key+to_string(*(ub - 1))]; //!!check if it is begin
        
//     }
// };

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
