// !!! sol2, O(mn), O(n)
// robin karp, string match
// https://www.jiuzhang.com/solution/string-replace/
class Solution {
public:
    string stringReplace(vector<string> &a, vector<string> &b, string &s) {
        int n = s.size(), m = a.size();
        vector<vector<int>> v;
        for(int i = 0; i < m; i++) v.push_back({(int)a[i].size(), i});
        sort(v.begin(), v.end(), greater<vector<int>> ());
        unsigned long long seed = 31;
        vector<unsigned long long> ahash, shash, base;
        for(string& s:a){
            unsigned long long tmp = 0;
            for(char c:s) tmp = tmp * seed + c - 'a';
            ahash.push_back(tmp);
        }
        base.push_back(1); // base[i] is pow(base, i)
        shash.push_back(0);
        for(char c:s){
            shash.push_back(shash.back() * seed + c - 'a');
            base.push_back(base.back() * seed); // remember this
        }
        int i = 0;
        string res = "";
        while(i < n){ // O(n)
            bool found = false;
            for(int j = 0; j < m; j++){ // O(m)
                int aLen = v[j][0], aIdx = v[j][1];
                if(i + aLen > n) continue; // !!! skip early
                unsigned long long  h1 = ahash[aIdx];
                // [i, i+aLen)
                unsigned long long  h2 = shash[i+aLen] - shash[i] * base[aLen];
                if(h1 == h2 && s.substr(i, aLen) == a[aIdx]){ 
                    found = true;
                    res += b[aIdx];
                    i += aLen;
                    break;
                }
            }
            if(!found) res += s[i++];
        }
        return res;
    }
};

// sol1, my, O(N*A*L)
// A = A.size() 100, N = S.size() 50000, L = max(A[i].size())
class Solution {
public:
    string stringReplace(vector<string> &a, vector<string> &b, string &s) {
        vector<vector<int>> v;
        for(int i = 0; i < a.size(); i++){
            v.push_back({(int)a[i].size(), i});
        }
        string res;
        sort(v.begin(), v.end(), greater<vector<int>> ()); // O(AlogA)
        for(int i = 0; i < s.size(); i++){ // O(N)
            bool found = false;
            for(int j = 0; j < v.size(); j++){  // O(A)
                int len = v[j][0], idx = v[j][1];
                if(s.substr(i, len) == a[idx]){ // O(l)
                    res += b[idx];
                    i += a[idx].size() - 1;
                    found = true;
                    break;
                }
            }
            if(!found) res += s[i];
        }
        return res;
    }
};
