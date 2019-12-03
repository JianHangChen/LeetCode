

//!!!! sol2, from gy1, binary search ,  O(NlogM),  M is the maximum value of pile
class Solution{
public:
    int minEatingSpeed(vector<int>& piles, int H){
        int lo = 1, hi = 1e9, mid;
        while(lo < hi){
            mid = lo + (hi - lo) / 2;
            int h = 0;
            for(int pile:piles){
                h += (pile - 1) / mid + 1;
                if(h > H) break;
            }
            if(h <= H){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }

        }
        return lo;
    }
};




// sol1, my TLE, O(NM) M is the maximum value of pile
// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int H) {
//         sort(piles.begin(), piles.end(), greater<int> ());

//         for(int K = 1; K < 1e9; K++){
//            int h = 0;
//            for(int pile:piles){
//             h += (pile - 1) / K + 1;
//             if(h > H) break;
//            }
//            if(h <= H) return K;
//         }
//         return 0;
//     }
// };
