



//!!! sol1, gy1  , O(logP), O(1)
class Solution {
public:
    int mirrorReflection(int p, int q) {
        while(q % 2 == 0 && p % 2 == 0){
            p /= 2;
            q /= 2;
        }
        if(q % 2 == 0) return 0;
        else{
            if(p % 2 == 0) return 2;
            else return 1;
        }
        return -1;
    }
};


// sol2, gy3, gcd , O(logP) O(1)
// greatest common divisor

class Solution{
public:
    int mirrorReflection(int p, int q){
        return 1 - p / gcd(p, q) % 2 + q / gcd(p, q) % 2;
    }
    int gcd(int p, int q){
        if(q == 0) return p;
        return gcd(q, p % q);
    }
};



