// sol3, newton, same as sol4, need explain proof by taylor
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        long long pre = x, next;
        while(pre * pre > x){
            next = (pre + x / pre) / 2;
            pre = next;
        }
        return pre;
        
    }
};

// !!! sol2, binary search, O(logn), O(1) , error easily
// class Solution {
// public:
//     int mySqrt(int x) {
//         long long l = 0, h = x;
//         h++;
//         while(l < h){
//             long long mid = l + (h - l) / 2;
//             if(mid * mid == x) return mid;
//             else if(mid * mid > x){
//                 h = mid;
//             }
//             else{
//                 l = mid + 1;
//             }
//         }
//         return h - 1;
//     }
// };

// // sol1, my, O(sqrt(n)), O(1)
// class Solution {
// public:
//     int mySqrt(int x) {
//         long long res = 0;
//         while(res * res <= x){
//             if(res * res == x) return res;
//             res++;
//         }
//         return res - 1;
//     }
// // };
