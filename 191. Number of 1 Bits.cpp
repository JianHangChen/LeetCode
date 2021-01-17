

// O(1), O(1)
// c++

// 32 bit signed: [-2^31, 2^31-1]
// 32 bit unsiged: [0, 2^32-1]
// one's and two's complement https://www.geeksforgeeks.org/1s-2s-complement-binary-number/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        while(n > 0){
            ones += (n & 1);
            n = n >> 1;
        }
        return ones;
    }
};








class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        # sol1, my zfill
        # res = 0
        # for i in bin(n)[2:].zfill(32):
        #     res += int(i)
        # return res
        
        # sol2, my format
        # bin = '{0:032b}'.format(n)
        # res = 0
        # for i in bin:
        #     res += int(i)
        # return res
        
        # sol3， use mask
        # from sol
        # mask = 1
        # bits = 0
        # for _ in range(32):
        #     if (n&mask):
        #         bits += 1
        #     mask = mask<<1
        # return bits
        
        # sol4, use n-1 & n, from sol
        bits = 0
        while n!=0:
            n = n&(n-1)
            bits += 1
        return bits
