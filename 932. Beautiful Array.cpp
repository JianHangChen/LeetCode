

// sol1, from sol1, O(nlogn), O(nlogn)
class Solution {
private:
    map<int, vector<int>> m={ {1,{1}} };
public:
        vector<int> beautifulArray(int N) {
        
        vector<int> res;
        if(m.count(N) > 0) return m[N];
        vector<int> even = beautifulArray(N/2), odd = beautifulArray((N+1)/2);
        for(int i = 0; i < odd.size(); i++){
            res.push_back(odd[i] * 2 - 1);
        }
        
        for(int i = 0; i < even.size(); i++){
            res.push_back(even[i] * 2);
        }
        m[N] = res;
        
        return res;
        
        
    }
};

