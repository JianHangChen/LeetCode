

// sol1, !!! union find, from grandyang, O(A), O(A)
class Solution {
public:
    unordered_map<string, string> parent;
    unordered_map<string, string> email2name;
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, set<string>> m;

        for(auto& acc:accounts){
            for(int i = 1; i < acc.size(); i++){
                parent[acc[i]] = acc[i];
                email2name[acc[i]] = acc[0];
            }
        }
        
        for(auto& acc:accounts){
            for(int i = 2; i < acc.size(); i++){
                uni(acc[1], acc[i]);
            }
        }
        
        for(auto& acc:accounts){
            for(int i = 1; i < acc.size(); i++){
                m[find(acc[i])].insert(acc[i]);
            }
        }
        
        for(auto& item:m){
            string root = item.first;
            string name = email2name[root];
            vector<string> v(item.second.begin(), item.second.end()); //!!!vectorize a set
            v.insert(v.begin(), name);
            res.push_back(v);
        }
        
        return res;
        
    }
    string find(string& a){
        if(parent[a] == a) return a;
        parent[a] = find(parent[a]); // important
        return parent[a];
    }
    void uni(string& a, string& b){
        parent[find(a)] = parent[find(b)];
    }
    
};
