50. Pow(x, n), 
Recursive: carefull about n = INT_MIN, k^(−3)=k^(−1)∗k^(−1)  ∗1/k, k^3=k^1∗k^1∗k, 
Iteratively: x^n = x^(b1∗2^0 )∗…∗ x^(b_k∗2^(k−1)  ), 同时注意n <0的时候，t =1/t

// !!! sol3, iteratively, from gy2 and sol3, O(logn), O(1)
class Solution {
public:
    double myPow(double x, int n) {
        
        double ans = 1;
        double t = x;
        if(n < 0) t = 1/t;
        
        
        while(n != 0){
            if(n % 2 != 0){
                ans *= t;
            }
            t = t * t;
            n /= 2;
        }
        return ans;
        
    }
};



//!! sol2, recursively from gy1, O(logn), O(logn)
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1) return x;
        if(n == 0) return 1;
        
        
        if(n%2 == 0) return  myPow(x*x, n/2);
        else{
            if(n > 0) return myPow(x * x, n/2) * x;
            else return myPow(x*x, n/2) / x;
        }
        
    }
};



//my sol1, TLE, out of int
// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(n == 1) return x;
//         if(n == 0) return 1;
        
//         if(n < 0){
//             x = 1/x;
//             n = -n;
//         }
//         double ans = 1;
        
//         ans = myPow(x, n / 2);
//         ans = ans * ans;
//         if(n % 2 == 1) ans *= x;
        
//         return ans;
        
//     }
// };


// -n out of int
// class Solution:
//     def myPow(self, x: float, n: int) -> float:
//         if n == 0:
//             return 1
        
//         if n < 0:
//             n = -n
//             x = 1/x
//         if n == 1:
//             return x
//         if n % 2 == 0:
//             return self.myPow(x*x, n//2)
//         else:
//             return self.myPow(x*x, n//2) * x
        
