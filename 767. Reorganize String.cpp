
// my, sol1, O(nlogA), O(A), A is the size of alphabet 
// https://leetcode.com/problems/rearrange-string-k-distance-apart/submissions/
class Solution {
public:
    string reorganizeString(string S) {
        unordered_map<char, int> count;
        for(char c:S) count[c]++;
        priority_queue<pair<int, char>> pq;
        for(auto& item:count) pq.push({item.second, item.first});
        string res;
        while(!pq.empty()){
            int cnt = min(2, int(S.size() - res.size()));
            vector<pair<int, char>> temp;
            for(int i = 0; i < cnt; i++){
                if(pq.empty()) return "";
                auto p = pq.top(); pq.pop();
                res.push_back(p.second);
                if(--p.first > 0) temp.push_back(p);
            }
            for(auto& ele:temp) pq.push(ele);
        }
        return res;
    }
};
