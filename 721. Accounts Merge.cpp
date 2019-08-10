// sol1, !!! union find, from grandyang, O(A)
class Solution{

private:
  unordered_map<string, string> root;
  unordered_map<string, string> owner;
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    
    
    unordered_map<string, set<string>> m;

    for(auto& account:accounts){
      for(int i = 1; i < account.size(); i++){
        root[account[i]] = account[i];
        owner[account[i]] = account[0];
      }
    }

    for(auto& account:accounts){
      auto p = find(account[1]); //!!!
      for(int i = 2; i < account.size(); i++){
        root[find(account[i])] = p;
      }
    }

    for(auto& account:accounts){
      for(int i = 1; i < account.size(); i++){
        m[find(account[i])].insert(account[i]);
      }
    }

    vector<vector<string>> ans;

    for(auto& item:m){
      vector<string> account(item.second.begin(), item.second.end());  //!!!vectorize a set
      account.insert(account.begin(), owner[item.first]);
      ans.push_back(account);
    }
    return ans;

  }
  string find(const string& s){
    return (root[s] == s)? s:find(root[s]);
  }
};






// sol2, bfs, from gy O[ sum(a_i*LOG(a_i)) ] , O( sum(a_i) )
class Solution{
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
    vector<vector<string>> ans;
    unordered_map<string, vector<int>> m;

    int n = accounts.size();
    for(int i = 0; i < n; i++){
      for(int j = 1; j < accounts[i].size(); j++){
        m[accounts[i][j]].push_back(i);
      }
    }
    
    vector<int> visited(n, false);

    for(int i = 0; i < n; i++){
      if(visited[i]) continue;
      
      set<string> res;

      queue<int> q({i});
      visited[i] = true;

      while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int j = 1; j < accounts[cur].size(); j++){
          res.insert(accounts[cur][j]);
          for(int idx:m[accounts[cur][j]]){
            if(!visited[idx]){
              q.push(idx);
              visited[idx] = true;
            }
          }
        }

      }


      vector<string> v(res.begin(), res.end());
      v.insert(v.begin(), accounts[i][0]);
      ans.push_back(v);
    }
    return ans;
  }
};

