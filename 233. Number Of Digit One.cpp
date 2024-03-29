
// sol1, from sol1
// math solution, this one is very hard

// 1's place:
// 1 1
// 10 1
// 100 1, 11, 21, 31, ..., 91   10
// 1000 1, 11, 21...,91, 101, 111, 121...991   100
// 1001 1, 11, 21...,91, 101, 111, 121...991, 1001   101
// 100x 1, 11, 21...,91, 101, 111, 121...991, 1001,   101
// 1010 101
// 1011 102
// 101x 102
// (n / 10) * 1 + min(max( ((n % 10) - 1 )+ 1, 0), 1)


// ten's place:
// 1 0
// 10 1
// 100 10, 11, 12,...19  10
// 1000 10, 11, 12,...19, 110, 111,...119, 210, ..210...919  100
// 1010 10, 11, 12,...19, 110, 111,...119, 210, ..210...919,1010  100 + 1
// 101x 10, 11, 12,...19, 110, 111,...119, 210, ..210...919,1010,  100+x+1
// 102x 10, 11, 12,...19, 110, 111,...119, 210, ..210...919,1010,1011,...1019  100 + 10

// (n / (ten * 10)) * ten + min(max(n % (10ten)-ten + 1, 0 ), ten )



class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for(long long i = 1; i <= n; i *= 10){
            count += n / (10 * i) * i + min(max(n % (10 * i) - i + 1, 0LL), i);
        }
        return count;
    }
};


// 100

// base = 1
// [1]
// 1   -> 1

// [10]
// 1 -> 1

// [1x] -> 2 (x>=1)
// 1 11

// [100]
// 1 11 21 31 ... 91 -> 10

// [1000]
// 1 11 21 .......91
// 101............191
// ...
// 901 ...........991 -> 100

// [1001] -> 101
// [100x] -> 101  (x >= 1)
// [1010] -> 101
// [1011] -> 102 
// [101x] -> 102 
// 101 = 101x / (10*base)
// 1 = min(101x % (10*base) - base + 1, 1) =min( x - 1 + 1, 1) = min(x, 1) 

// n / (base * 10) + 1 if ( n % (base * 10) >= 1 )


// base = 10

// [1] -> 0

// [10] -> 1

// [100] -> 10
// 10 11 12 ...19

// [110] -> 11
// 10 11 12 ...19 10
// 110

// [11x] -> 10 + x
// 10 ...19            10  = 11x / (10 * base) * base = 10
// 110 111 ... 11x      x + 1  = min(11x % (10 * base)  - base + 1, base)  = min(x + 1, base)


// 0 1 2 3 4 5 6 7 8 9 10 11 12 13
// x / 10
//     + 
// min(max(x % 10 - 1 + 1, 0), 1)
    
// min(max(x % 1000 - 100 + 1, 0), 100)


// 160
// one's base = 1
// 1 11 21 31 41 51 61  ... 91   10
// 101 .............160 6
// 161
// 161 / (base*10) = 16
// 161 % (base*10) = 1   


// ten's base = 10
// 160 
// 10 11 12 13 14 15 .. 19   10
// 110 111 ............ 119  10
//
// 160 / base*10 = 1  ... 60
// 160 % base*10  = 60
// 60 - 10 + 1 = 51

// hundred's base = 100
// 1160 
// 100 101 102 .... 199  100
// 100 .....160 -> 61

// 1160 / base*10 = 1 of 100
// 1160 % base*10  = 160

// min( max( (1160 % base*10 - base + 1), 0), base) = min(61 , 100) = 61
