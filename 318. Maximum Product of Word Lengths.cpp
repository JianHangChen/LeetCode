// !!! sol1.1, mask, bit operation, from gy, O(n^2), O(n)
class Solution{
public:
    int maxProduct(vector<string>& words){
        int n = words.size(), res = 0;
        vector<int> mask(n, 0);
        for(int i = 0; i < n; i++){
            
            for(auto c:words[i]){
                mask[i] |= ( 1 << (c - 'a') );
            }

            for(int j = 0; j < i; j++){
                if( !(mask[i] & mask[j])){
                    int l1= words[i].size(), l2 = words[j].size();
                    res = max(res, l1 * l2);
                }
            }
        }
        return res;
    }
};


// sol1, my, sol1, O(n^2), O(n)
class Solution {
public:

int maxProduct(vector<string>& words){
    int n = words.size();

    vector<vector<int>> t(n, vector<int> (26, 0));
    for(int i = 0; i < n; i++){
        string word = words[i];
        for(auto c:word){
            t[i][c - 'a']++;
        }
    }
    int res = 0;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            
            bool overlap = false;
            for(int k = 0; k < 26; k++){
                if(t[i][k] > 0 && t[j][k] > 0){
                    overlap = true;
                }
            }

            if(!overlap){
                int l1 = words[i].size(), l2 = words[j].size();
                res = max(res, l1 * l2);
            }
        }
    }

    return res;

}

    
};










// sol2, hash, from gy, O(n^2), O(n)
class Solution{
    public:
        int maxProduct(vector<string>& words){
            int n = words.size(), res = 0;
            unordered_map<int, int> m; // map mask -> length
            for(auto word:words){
                int mask = 0, l1 = word.size();
                for(auto c:word){
                    mask |= (1 << (c - 'a'));
                }

                for(auto item:m){
                    int mask_m = item.first, l2 = item.second;
                    if( !(mask & mask_m)){
                        res = max(res, l1 * l2);
                    }
                }
                m[mask] = max(m[mask], l1); //!!! carefull here, in some case like "aaa", "aa" mask will be the same
            }
            return res;
        }
};
