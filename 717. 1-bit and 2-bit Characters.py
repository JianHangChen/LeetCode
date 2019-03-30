class Solution:
    # sol1, my pointer
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        
        l = len(bits)
        i = 0
        
        while i < l - 1:
            if bits[i] == 1:
                i += 2
            else:
                i += 1
        return i == l-1
    
    # sol2, greedy, from sol2
    # check the number of "1" between last and second-last "0"
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        parity = 0
        i = len(bits) - 2
        while i >=0 and bits[i]:
            parity ^= bits[i]
            i -= 1
        return parity == 0
