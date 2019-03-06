# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        # my sol1, using template2 and EXTRA if
#         low = 1
#         high = n + 1
        
#         while low < high:
#             mid = (low + high) // 2
#             if isBadVersion(mid):
#                 if mid > 1 and isBadVersion(mid-1):
#                     high = mid
#                 else:
#                     return mid
#             else:
#                 low = mid + 1
                
        # sol2, using template1, improve from sol
        low = 1
        high = n
        while low < high:
            mid = low + (high - low) // 2
            
            if isBadVersion(mid):
                high = mid
            else:
                low = mid + 1
        return low
    
