
// sol1, my, O(logn)
// https://leetcode.com/problems/number-of-digit-one/submissions/
class Solution {
public:
    int digitsCount(int d, int low, int high) {
        if(low == 1) return count(high, d);
        return count(high, d) - count(low - 1, d);
    }
    int count(int x, int d){ // count range [1 x] has how many d 
        long long base = 1;
        int res = 0;
        while(x >= base){
            if(d == 0) res += (x / (base*10) - 1) * base + min(max(x%(10*base) - d*base + 1, 0LL), base);
            else res += x / (base*10) * base + min(max(x%(10*base) - d*base + 1, 0LL), base);
            base *= 10;
        }
        return res;
    }
};

// d = 0
// one's
// base = 1
// [1] -> 0
// [9] -> 0
// [10]-> 1
// [19]-> 1
// [20]-> 2
// [91]-> 9
// [100]-> 10
// 10 20 ... 100

// 10/10 * 1= 1   10%10-0+1 = 1
// 10/100*10 = 0   10%100-0+1 = 11


// ten's
// base = 10
// [10]-> 0
// [99]-> 0
// [100]-> 1

// (100/(10*base) - 1)*base = 0

// [200]-> 11
// 200 / (10*base)*base 

// d  = 3

// one's
// base = 1
// [1] -> 0
// [3] -> 1
// [12] -> 1
// [13] -> 2

// [143]
// 3 13 23 33 .. 93 103.. 133 -> 14 = 143 / (base*10) * base
// 143 -> 1 = min( max( (143 % (base*10) - d + 1), 0 ),  base)


// tens
// base = 10
// [143]
// 30 31 32 ... 39 -> 10 = 143 / (base*10) * base
// 130 131 132...139 -> 10 = min( max( (143 % (base*10) - d*base + 1), 0 ),  base)


// sol1, from ch9 digit count, TLE
// O(nlogn), O(1)
// class Solution {
// public:
//     int digitsCount(int d, int low, int high) {
//         int count = 0;
//         if(d == 0 && low == 0) count = 1;
//         for(int i = low; i <= high; i++){
//             int num = i;
//             while(num > 0){
//                 if(num % 10 == d) count++;
//                 num /= 10;
//             }
//         }
//         return count;
        
//     }
// };
