// sol3, from https://github.com/wisdompeak/LeetCode/tree/master/Recursion/780.Reaching-Points
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if(sx > tx || sy > ty) return false;        
        if(sx == tx && (ty - sy) % tx == 0) return true; // !!!!
        if(sy == ty && (tx - sx) % ty == 0) return true;
        
        // if tx % ty == 0 , then after reduction tx = 0, ty = ty, in this case, because we know ty != sy, so it will never match 
        // or if you assume sx, sy match tx ty after some reduction(tx%ty == 0), then tx ty could become ty, ty or (0, ty). those will never match (sx, sy) because sy < ty 
        if(tx > ty) return reachingPoints(sx, sy, tx%ty, ty);
        else return reachingPoints(sx, sy, tx, ty%tx);
    }
};


// sol2, using relationship of tx, ty, compare them to retrieve orignal one
// class Solution {
// public:
//     bool reachingPoints(int sx, int sy, int tx, int ty) {
//         if(sx == tx && sy == ty) return true;
//         else if(tx == ty || tx < sx || ty < sy) return false;
//         else if(tx > ty) return reachingPoints(sx, sy, tx-ty, ty);
//         else return reachingPoints(sx, sy, tx, ty-tx);
//     }
// };

// my sol1, TLE
// 35
// 13
// 455955547
// 420098884
// class Solution {
// public:
//     bool reachingPoints(int sx, int sy, int tx, int ty) {
//         if(sx == tx && sy == ty) return true;
//         else if(sx > tx || sy > ty) return false;
//         else{
//             return reachingPoints(sx+sy, sy, tx, ty) || reachingPoints(sx, sx+sy, tx, ty);
//         }
//     }
// };
