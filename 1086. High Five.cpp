class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, priority_queue<int, vector<int>, greater<int>>> m; // carefully about min priority queue: use greater<int>
        for(auto& item:items){
            int id = item[0], score = item[1];
            m[id].push(score);
            if(m[id].size() > 5) m[id].pop();
        }
        vector<vector<int>> res;
        for(auto& item:m){
            res.push_back({item.first, 0});
            while(!item.second.empty()){
                (res.back())[1] += item.second.top();
                item.second.pop();
            }
            (res.back())[1] /= 5;
        }
        return res;
    }
};
