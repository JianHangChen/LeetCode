// sol2, robin karp string search
class Solution {
 public:
  vector<int> getStartIdx(string& input, string& source){
    int n = input.size(), sn = source.size();
    long long MOD = 1e9+13;
    vector<int> idxs;
    long long ihash = 0, shash = 0, pow256 = 1;
    for(int i = 0; i < sn; i++){
      ihash = (ihash * 256 + input[i]) % MOD;
      shash = (shash * 256 + source[i]) % MOD;
      pow256 = (pow256 * 256) % MOD;
    }
    int pre = INT_MIN;
    for(int i = 0; i + sn <= n; i++){
      if(ihash == shash && i >= pre + sn){        
        if(input.substr(i, sn) == source){
          idxs.push_back(i);
          pre = i;
          // i = i + sn - 1; !!! cannnot directly skip because of hash value
        }
      }
      if(i + sn == n) break;
      int pre = input[i], next = input[i+sn];
      ihash = ( (ihash * 256 % MOD - pre * pow256 % MOD + MOD) % MOD + next) % MOD;
    }
    return idxs;
  }

  string replace(string input, string source, string target) {
      int n = input.size(), sn = source.size(), tn = target.size();
      auto idxs = getStartIdx(input, source);
      if(idxs.size() == 0) return input;
      if(sn >= tn){
        int s = 0, f = 0, i = 0;
        while(f < n){
          if(i < idxs.size() && f == idxs[i]){
            i++;
            for(int t = 0; t < tn; t++){
              input[s++] = target[t];
            }
            f = f + sn;
          }          
          else{
            input[s++] = input[f++];
          }
        }
        return input.substr(0, s);
      }
      else{ // sn < tn
        input += string((tn - sn) * idxs.size(), ' ');
        int f = n - 1, s = input.size() - 1, i = idxs.size() - 1;
        while(f >= 0){
            if(i >= 0 && f == idxs[i] + sn - 1){
                i--;
                for(int t = tn - 1; t >= 0; t--){
                    input[s--] = target[t];
                }
                f -= sn;
            }
            else{
              input[s--] = input[f--];
            }
        }
        return input;
      }
    }
};

// sol1, easy version
class Solution {
 public:
 
  vector<int> getEndIdx(string& input, string& source){
    int n = input.size();
    int i = 0;
    vector<int> idxs;
    while(i < n){
      if(input.substr(i, source.size()) == source ){
        idxs.push_back(i+source.size() - 1);
        i += source.size();
      }
      else{
        i++;
      }
    }
    return idxs;
  }

  string replace(string input, string source, string target) {
      int n = input.size(), sn = source.size(), tn = target.size();
      if(sn >= tn){
        int s = 0, f = 0;
        while(f < n){
          if(input.substr(f, sn) == source){
            for(int t = 0; t < tn; t++){
              input[s++] = target[t];
            }
            f = f + sn;
          }
          else{
            input[s++] = input[f++];
          }
        }
        return input.substr(0, s);
      }
      else{ // sn < tn
        auto idxs = getEndIdx(input, source);
        input += string((tn - sn) * idxs.size(), ' ');
        int f = n - 1, s = input.size() - 1;
        while(f >= 0){
            if(idxs.size() > 0 && f == idxs.back()){
                idxs.pop_back();
                for(int t = tn - 1; t >= 0; t--){
                    input[s--] = target[t];
                }
                f -= sn;
            }
            else{
              input[s--] = input[f--];
            }
        }
        return input;
      }
    }
};
