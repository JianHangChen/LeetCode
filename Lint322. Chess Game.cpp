// !!! sol2, unordered_set, O(m+n), O(m+n)
class Solution {
public:
    vector<bool> isAttacked(vector<vector<int>> &queen, vector<vector<int>> &knight) {
        unordered_set<int> x, y, h, v;
        for(auto& q:queen){
            x.insert(q[0]);
            y.insert(q[1]);
            h.insert(q[1] - q[0]);
            v.insert(q[1] + q[0]);
        }
        int m = knight.size();
        vector<bool> res(m, false);
        for(int i = 0; i < knight.size(); i++){
            int a = knight[i][0], b = knight[i][1];
            if(x.count(a) > 0 || y.count(b) > 0 || h.count(b-a) > 0 || v.count(b+a) > 0) res[i] = true;
        }
        return res;
    }
};

// my sol1, O(M+N), O(max_coordinate), MLE, use array
// class Solution {
// public:

//     vector<bool> isAttacked(vector<vector<int>> &queen, vector<vector<int>> &knight) {
//         int max_coord = 1;
//         for(auto& q:queen){
//             max_coord = max(max_coord, q[0]);
//             max_coord = max(max_coord, q[1]);
//         }
//         for(auto& k:knight){
//             max_coord = max(max_coord, k[0]);
//             max_coord = max(max_coord, k[1]);
//         }
        
//         vector<bool> x(max_coord + 1, false), y = x;
//         vector<bool> h(2 * max_coord, false), v = h;
//         int d = max_coord-1;
        
//         for(vector<int>& q:queen){
//             x[q[0]] = true;
//             y[q[1]] = true;
//             h[q[1] - q[0] + d] = true;
//             v[q[0] + q[1] - 2] = true;    
//         }
//         int m = knight.size();
//         vector<bool> res(m, false);
//         for(int i = 0; i < m; i++){
//             int a = knight[i][0], b = knight[i][1];
//             if(x[a] || y[b] || h[b-a+d] || v[a+b-2]) res[i] = true;
//         }
//         return res;
//     }
// };
