
// sol2, !!! O(n), O(n)

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m;
        vector<int> res;
        int n = S.size();
        for(int i = 0; i < n; i++) m[S[i]] = i;

        int start = 0, end = 0;
        for(int i = 0; i < n; i++){
          end = max(end, m[S[i]]);
          if(i == end){
            res.push_back(end-start+1);
            start = end+1;
          }
        }
        return res;
    }
};

//sol1, O(n), O(n)
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m;
        int n = S.size();
        vector<int> seg(n, 0);
        int part = 0;

        for(int i = 0; i < n; i++){
          if(m.count(S[i]) > 0){
            int start = m[S[i]];
            part = seg[start];
            for(int k = start; k <= i; k++){
              seg[k] = part;
            }
            m[S[i]] = i;
          }
          else{
            part++;
            m[S[i]] = i;
            seg[i] = part;
          }
        }

        vector<int> res(part,0);

        for(int i = 0; i < n; i++){
          res[seg[i]-1]++;
        }

        return res;

    }
};
