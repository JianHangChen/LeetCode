

//!!! sol1.1, my, binary search, binary boundary from 9ch ans O(nlogn), O(1)
class Solution {
public:
    /**
     * @param m: m pillars of your temple.
     * @param woods: length of n different wood
     * @return: return the maximum height of the temple.
     */
    int buildTemple(int m, vector<int> &woods) {
        sort(woods.begin(), woods.end());
        int lo  = woods.front(), hi = woods.back(), ans;
        
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(verify(mid, m, woods)){
                lo = mid + 1;
                ans = mid;
            }
            else{
                hi = mid - 1;
            }
        }
        return ans;
    }
    bool verify(int val, int m, vector<int>& woods){
        int res = 0;
        for(int i = woods.size() - 1; i >= 0; i--){
            res += woods[i] / val;
            if(res >= m) return true;
        }
        return false;
        
    }
};



// sol1, my, binary search O(nlogn), O(1)
// class Solution {
// public:
//     /**
//      * @param m: m pillars of your temple.
//      * @param woods: length of n different wood
//      * @return: return the maximum height of the temple.
//      */
//     int buildTemple(int m, vector<int> &woods) {
//         sort(woods.begin(), woods.end());
//         int lo  = woods.front(), hi = woods.back();
        
//         while(lo < hi){
//             int mid = lo + (hi - lo) / 2;
//             if(verify(mid, m, woods)){
//                 lo = mid + 1;
//             }
//             else{
//                 hi = mid;
//             }
//         }
        
        
//         return lo - 1;
//     }
//     bool verify(int val, int m, vector<int>& woods){
//         int res = 0;
//         for(int i = woods.size() - 1; i >= 0; i--){
//             res += woods[i] / val;
//             if(res >= m) return true;
//         }
//         return false;
        
//     }
// };
