
//!!! sol1, very hard, remember it, from ch9 and gy
// 
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
