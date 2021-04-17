
// sol1, my, two pass 
// O(n+q), O(n)
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> left(n, vector<int> (4));
        vector<vector<int>> right(n, vector<int> (4));
        vector<int> lefti(4, n), righti(4, n); // lefti[c] the most recent visited index for color c
        for(int i = 0; i < n; i++){
            lefti[colors[i]] = i;
            for(int color = 1; color <= 3; color++){
                left[i][color] = lefti[color];
            }
        }
        for(int i = n-1; i >= 0; i--){
            righti[colors[i]] = i;
            for(int color = 1; color <= 3; color++){
                right[i][color] = righti[color];
            }
        }
        vector<int> res;
        for(auto& q:queries){
            int i = q[0], color = q[1];
            int d1 = left[i][color] == n ? n : i - left[i][color];
            int d2 = right[i][color] == n ? n: right[i][color] - i;
            int d;
            if(d1 == n && d2 ==n) d = -1;
            else d = min(d1, d2);
            res.push_back(d);
        }
        return res;        
    }
};
