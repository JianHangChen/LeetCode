// sol2, my,dfs with memo, O(n^2), O(n^2)
// n = stone.size();

class Solution {
public:
    unordered_set<int> s;
    int n;
    unordered_map<int,unordered_map<int, bool>> m;
    
    bool canCross(vector<int>& stones) {
        for(int stone:stones) s.insert(stone);
        n = stones.back();
        return dfs(0, 0);
    }
    
    bool dfs(int cur, int jump){
        if(m.count(cur) > 0 && m[cur].count(jump) > 0) return m[cur][jump];
        
        if(cur == n ) return true;
        
        for(int i = jump - 1; i <= jump + 1; i++){
            if(i <= 0) continue;
            int next = cur + i;
            if(s.count(next) == 0) continue;
            if( dfs(next, i)){
                return m[cur][jump] = true;
            }
        }
        return m[cur][jump] = false;        
    }
};



// sol1, my, tle
// class Solution {
// public:
//     unordered_set<int> s;
//     int n;
//     bool canCross(vector<int>& stones) {
//         for(int stone:stones) s.insert(stone);
//         n = stones.back();
//         if(s.count(1) > 0) return dfs(1, 1);
        
//         return false;
//     }
    
//     bool dfs(int cur, int jump){

//         if(cur == n ) return true;
        
//         for(int i = jump - 1; i <= jump + 1; i++){
//             if(i == 0) continue;
            
//             int next = cur + i;
//             if(s.count(next) == 0) continue;
//             if( dfs(next, i)) return true;            
//         }
//         return false;
        
//     }
// };

// [0,1,3,5,6,8,12,17]
//  o o x o x o o x o x x  x  o  x  x  x  x  o 
//  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17

// [0,1,2,3,4,8,9,11]
//  o o o o o x x x o o x  o
//  0 1 2 3 4 5 6 7 8 9 10 11
