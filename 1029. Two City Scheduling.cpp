//!!! sol1.1, O(nlogn), O(1)

class Solution {
public:
    struct CMP{
        bool operator()(const vector<int>& a, const vector<int>& b){
            return a[0] - a[1] < b[0] - b[1];
        }
    } cmp;
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        sort(costs.begin(), costs.end(), cmp);
        int res = 0;
        for(int i = 0; i < n; i++){
            if(i < n / 2) res += costs[i][0];
            else res += costs[i][1];
        }
        return res;
    }
};


// sol1, my, O(nlogn), O(n)
// class Solution {
// public:
//     int twoCitySchedCost(vector<vector<int>>& costs) {
//         int n = costs.size();
//         vector<vector<int>> diff(n, vector<int> (2));
//         for(int i = 0; i < n; i++){
//             diff[i][0] = costs[i][0] - costs[i][1];
//             diff[i][1] = i;
//         }
//         sort(diff.begin(), diff.end());
//         int res = 0;
//         for(int i = 0; i < n; i++){
//             if(i < n / 2){
//                 res += costs[diff[i][1]][0];
//             }
//             else{
//                 res += costs[diff[i][1]][1];
//             }
//         }
//         return res;
//     }
// };
