// real gg interview
// requirement: 1. nth root of x, 2. accuracy to 0.01, 3. fast power
// a = trunc( n-th root{x})
// find a s.t:
// a^n <= x < (a+0.01)^n
class Solution {
public:
    int mySqrt(double x, int n) {
        if(x == 0) return 0;
        bool sign = 1;
        if(x < 0){
            sign = -1;
            x = -x;
        }
        if(x <= 1){
            double low = x, high = 1;
        }
        else{
            double low = 1, high = x;
        }
        while(true){
            double mid = (low + high) / 2.0;
            double mid_pow = pow(mid, n);
            if(mid_pow == x){
                return mid * sign;
            }
            else if(mid_pow < x){
                if(pow(mid+0.01, n) > x) return mid * sign;
                else low = mid;
            }
            else{
                high = mid;
            }
        }
        return 0;
    }
    
    double power(double x, int n){ 
        if(n == 1) return x;
        if(n == 0) return 1;
        //?? n < 0
        if(n % 2 == 0){
            double res = power(x, n / 2);
            return res * res;
        }
        else{
            double res = power(x, n / 2);
            return res * res * x;
        }
    }
    
};

// sol3, newton, same as sol4, need explain proof by taylor
// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x == 0) return 0;
//         long long pre = x, next;
//         while(pre * pre > x){
//             next = (pre + x / pre) / 2;
//             pre = next;
//         }
//         return pre;
        
//     }
// };

// // !!! sol2, binary search, O(logn), O(1) , error easily
class Solution {
public:
    int mySqrt(int x) {
        long long l = 0, h = x;
        h++;
        while(l < h){
            long long mid = l + (h - l) / 2;
            if(mid * mid == x) return mid;
            else if(mid * mid > x){
                h = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return h - 1;
    }
};

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
