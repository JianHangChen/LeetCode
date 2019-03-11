class Solution:
    
    # sol1, my, recursively divide by 2
    def isPowerOfTwo(self, n: int) -> bool:
        if n <= 0:
            return False
        if n == 1:
            return True
        if n % 2 == 0:
            return self.isPowerOfTwo(n//2)
        else:
            return False
    
    # sol2, use trick of n&(n-1), only 1 bit of power of 2 is 1
    # def isPowerOfTwo(self, n: int) -> bool:
    #     if n <= 0:
    #         return False
    #     else:
    #         return n&(n-1) == 0
    
    # sol3, iteratively divide by 2
    # from method 1 of https://leetcode.com/problems/power-of-two/discuss/63966/4-different-ways-to-solve-Iterative-Recursive-Bit-operation-Math
    # def isPowerOfTwo(self, n: int) -> bool:
    #     if n <= 0:
    #         return False
    #     while (n%2) == 0:
    #         n //= 2
    #     return n == 1
    
    # sol4, jave bitcount
    # form method 5 of above link
    
