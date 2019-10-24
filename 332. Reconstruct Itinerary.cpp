
// sol1, dfs, from gy1
#include <algorithm>
class Solution{
private:
    vector<string> res;
    unordered_map<string, multiset<string>> m;
    
public:
  vector<string> findItinerary(vector<vector<string>>& itis){
    for(auto iti:itis){
      m[iti[0]].insert(iti[1]);  
    }
    
    
    string start = "JFK";
    
    dfs(start);
    reverse(res.begin(), res.end());
       
    return res;
    
  }

  int dfs(string start){
    while(!m[start].empty()){
        string next = *(m[start].begin()); m[start].erase(m[start].begin()); // carefull, erase string means erase all element with the same key 
        dfs(next);
    }
    res.push_back(start);
    return 0;
  }
  
};


//sol2, iteratively, gy2

class Solution{
public:
    vector<string> findItinerary(vector<vector<string>>& tickets){
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for(auto ticket:tickets) m[ticket[0]].insert(ticket[1]);
        stack<string> s;
        s.push("JFK");
        string start, next;
        while(!s.empty()){
            start = s.top();
            if(m[start].empty()){
                res.insert(res.begin(), start);
                s.pop();
            }
            else{
                next = *(m[start].begin());
                s.push(next);
                m[start].erase(m[start].begin());
            }
        }
        return res;
    }
};
