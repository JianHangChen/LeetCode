# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    
    
    # my sol1, binary search, log2(n), O(1)
#     def guessNumber(self, n):
#         """
#         :type n: int
#         :rtype: int
#         """
#         low = 1
#         high = n
        
#         while low <= high:
#             mid = (low+high)//2
#             if guess(mid) == 0: # got it
#                 return mid
#             elif guess(mid) == 1: # lower
#                 low = mid + 1
#             else:
#                 high = mid - 1
        
#         return None

    # sol2, ternary search, log3(n), O(1)
    # from solution
    #Since the value of \frac{2}{\log_2 3} is greater than one, Ternary Search does more comparisons than Binary Search in the worst case.
    def guessNumber(self, n):
        low = 1
        high = n
        
        while low <= high:
            mid1 = (high - low)//3 + low
            mid2 = (high - low)//3 * 2 + low
            
            res1 = guess(mid1)
            res2 = guess(mid2)
            if res1 == 0:
                return mid1
            if res2 == 0:
                return mid2
            if res1 == 1:
                if res2 == 1:
                    low = mid2 + 1
                else:
                    low = mid1 + 1
                    high = mid2 - 1
            else:
                high = mid1 - 1
        return None
