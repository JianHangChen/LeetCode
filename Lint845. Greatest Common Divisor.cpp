//!sol1, O(logn), O(logn)
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
// 公式 gcd(a, b) = gcd(b, a % b) 其实这个公式是符合交换律的， 
// 也就是说， 正确性来讲： gcd(a, b) = gcd(a % b, b) = gcd(a, b%a) 
// 但是， 我们要保证每次去下一步的时候， 都是前面更大， 后面更小，
//  不然就死循环了， 所以用了上面那个公式， 所以就辗转相除了

// 至于为什么会有这个公式呢？ 设a = kb + c(c < b)，那么其实c = a % b, 
// 假设d是a,b的公约数，那b % d = 0，a % d = 0，那么c % d肯定还是0 (不然等式不成立了）

// 10 15

// 15-10 = 5, 10
// 10 -5 = 5
// 5

// 30 15
// 15, 

//!!!!! sol2, iteratively, O(logn), O(1)
// https://www.youtube.com/watch?v=c4PQrLFj9Cw
class Solution {
public:
    int gcd(int a, int b) {
        // if(a < b) swap(a, b);完全不需要swap，因为a < b时候得到的新一轮c会等于a，下一轮自动变成a>b
        while(b != 0){
            int c = a % b;
            a = b;
            b = c;            
        }
        return a;
    }
};
