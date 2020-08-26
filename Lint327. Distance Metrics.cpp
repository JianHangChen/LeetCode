
//!!! sol2, dp, O(n), O(n)
class Solution {
public:
    vector<long long> getDistanceMetrics(vector<int> &a) {
        int n = a.size();
        vector<long long> res(n, 0);
        unordered_map<int, vector<int>> m;
        for(int i = 0; i < n; i++) m[a[i]].push_back(i);
        for(auto& item:m){
            vector<int> idxs = item.second;
            int k = idxs.size();
            vector<long long> pre(k, 0), pos(k, 0);
            
            for(int i = 1; i < k; i++){
                pre[i] = pre[i-1] + abs(idxs[i] - idxs[i-1]) * i;
            }
            for(int i = k - 2; i >= 0; i--){
                pos[i] = pos[i+1] + abs(idxs[i+1] - idxs[i]) * (k - (i+1));
            }
            for(int i = 0; i < k; i++){
                res[idxs[i]] = pre[i] + pos[i];
            }
        }
        return res;
    }
};



// sol1, brute force, O(n^2), O(n)
// class Solution {
// public:
//     vector<long long> getDistanceMetrics(vector<int> &a) {
//         unordered_map<int, vector<int>> m;
//         int n = a.size();
//         for(int i = 0; i < a.size(); i++){
//             m[a[i]].push_back(i);
//         }
//         vector<long long> res(n, 0);
//         for(auto& item:m){
//             for(int i = 0; i < item.second.size(); i++){
//                 for(int j = 0; j < item.second.size(); j++){
//                     res[item.second[i]] += abs(item.second[i] - item.second[j]);
//                 }
//             }
//         }
//         return res;
//     }
// };
