
// sol2, O(NlogN), min_heap
// https://leetcode.com/problems/minimum-cost-to-connect-sticks/discuss/365865/Python-Greedy-Solution
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
        int res = 0;
        while(pq.size() > 1){
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            int xy = x + y;
            res += xy;
            pq.push(xy);
        }
        return res;       
    }
};

//sol1, my O(n^2), TLE
// class Solution {
// public:
//     int connectSticks(vector<int>& sticks) {
//         int res = 0;
//         sort(sticks.begin(), sticks.end());
        
//         while(sticks.size() > 1){
//             int xy = sticks[0] + sticks[1];
//             res += xy;
//             int n = sticks.size();
//             vector<int> temp(n-1);
//             int j = 0;
//             for(int i = 2; i < sticks.size(); i++){
                
//                 if(xy != 0 && sticks[i] > xy){
//                     temp[j++] = xy;
//                     xy = 0;
//                     temp[j++] = sticks[i];
//                 }
//                 else{
//                     temp[j++] = sticks[i];
//                 }
//             }
//             if(xy != 0) temp[j] = xy;
//             sticks = temp;
//         }
//         return res;
//     }
// };
