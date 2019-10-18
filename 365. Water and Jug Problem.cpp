



//!! sol1, gcd: greatest common divisor
// from gy1 and https://leetcode.com/problems/water-and-jug-problem/discuss/83720/Clear-Explanation-of-Why-Using-GCD


class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return (z == 0) || (x + y >= z && z % gcd(x,y) == 0);
    }


    int gcd(int x, int y){
      if(y == 0) return x;
      return gcd(y, x % y);
    }

};

