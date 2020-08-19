
//!!! sol1, very hard, remember it, from ch9 and gy
// O(n), O(1)
// I feel that the running time of this algorithm is O(n). The reason is that the only possible characters in the string are lower case letters, which makes the maximum size of the priority queue 26. We are doing one push and pop from the priority queue for each character in the string, which is O(n * (2 * log(26))). This reduces to O(n).
// This is similar to how the other array based solution looks like it would be O(n^2), but it is not because they are doing a linear scan of a constant sized array.


class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k <= 1) return s;
        unordered_map<char, int> count;
        for(char c:s) count[c]++;
        priority_queue<pair<int, char>> pq;
        for(auto& item:count) pq.push({item.second, item.first});
        int l = s.size();
        string res;
        while(!pq.empty()){
            int cnt = min(k, l);
            vector<pair<int, char>> v;
            for(int i = 0; i < cnt; i++){
                if(pq.empty()) return "";
                auto remain = pq.top(); pq.pop();
                res.push_back(remain.second);
                l--;
                if(--remain.first > 0) v.push_back(remain);
            }
            for(auto& item:v) pq.push(item);
        }
        return res;
    }
};
