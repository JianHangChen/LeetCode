// my, similar to sol3, O(n), O(n)
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> m;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]] = i;
        }
        for(auto& piece:pieces){
            if(m.count(piece[0]) < 1) return false;
            for(int j = 1; j < piece.size(); j++){
                if( m[piece[j-1]] + 1 != m[piece[j]]) return false;
            }
        }
        return true;
    }
};
