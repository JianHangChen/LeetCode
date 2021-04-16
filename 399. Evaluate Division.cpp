//!!! sol1, union find
// O((m+n)logA ), O(A)
// equation: m, query: n
// A is all the members
// https://www.youtube.com/watch?v=3b5v4db07VM
class Solution {
public:
    unordered_map<string, double> score;
    unordered_map<string, string> parent;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(auto& eq:equations){
            parent[eq[0]] = eq[0];
            score[eq[0]] = 1.0;
            parent[eq[1]] = eq[1];
            score[eq[1]] = 1.0;
        }
        for(int i = 0; i < values.size(); i++){
            uni(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> res;
        for(auto& q:queries){
            if(score.count(q[0]) == 0 || score.count(q[1]) == 0 || find(q[0]) != find(q[1])) res.push_back(-1.0); // remember to use find again!!! (find is to update the score of q[0], q[1])
            else res.push_back(score[q[0]] / score[q[1]]);
        }
        return res;
    }
    
    string find(string& a){
        if(parent[a] == a) return a;

        string originParent = parent[a];
        parent[a] = find(parent[a]); //!!!!!! update to new parent, now we don't know where the orignal parent is if we don't record original parent
        score[a] *= score[originParent]; //doing find will update the score of a
        return parent[a];
    }
    
    void uni(string& a, string& b, double val){
        string pa = find(a), pb = find(b);
        score[pa] = val * score[b] / score[a];
        parent[pa] = parent[pb];
    }
    
};
