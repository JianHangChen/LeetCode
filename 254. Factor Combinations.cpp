// !!!! sol1, backtracking, from gy1
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> factors;
        addFactors(n, 2, res, factors);
        
        return res;
    }
    
    void addFactors(int n, int start, vector<vector<int>>& res, vector<int>& factors){
        if(n == 1 && factors.size() > 1){
            res.push_back(factors);
            return;
        }
        for(int i = start; i <= n; i++){
            if(n % i == 0){
                factors.push_back(i);
                addFactors(n / i, i, res, factors);
                factors.pop_back();
            }
        }
        return;
    }
};


// sol2, use the same output order as the question, from gy3
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                vector<int> out = {i, n / i};
                res.push_back(out);
                vector<vector<int>> factors = getFactors(n / i);
                for(vector<int>& v:factors){
                    if(i <= v[0]){
                        v.insert(v.begin(),i);
                        res.push_back(v);
                    }
                }
            }
        }
        
        return res;
    }
};


