class Solution:


# my sol1, using dict
#     def __init__(self):
#         self.dic = set()
#     def isHappy(self, n):
#         """
#         :type n: int
#         :rtype: bool
#         """
#         if n == 1:
#             return True

#         if n in self.dic:
#             return False
#         else:
#             self.dic.add(n)
#         res = 0
#         while n > 0:
#             res += (n % 10)**2
#             n = n // 10
#         return self.isHappy(res)
    
# sol 1.1 using dict, but more elegant(no recursion)
#from https://leetcode.com/problems/happy-number/discuss/56915/My-Python-Solution
#         def isHappy(self, n):
#             dic = set()
#             while n!= 1:
#                 n = sum( (int(i) ** 2) for i in str(n))
#                 if n in dic:
#                     return False
#                 else:
#                     dic.add(n)
            
#             return True


# sol2, not using dict, Floyd Cycle detection algorithm
# from https://leetcode.com/problems/happy-number/discuss/56917/My-solution-in-C(-O(1)-space-and-no-magic-math-property-involved-)


        
        def isHappy(self, n):
            def square_sum( n):
                res = 0
                while n > 0:
                    res += (n % 10) ** 2
                    n = n // 10
                return res
            slow = n
            fast = square_sum(n)
            while( slow != fast ):
                slow = square_sum(slow)
                fast = square_sum(square_sum(fast))
            if slow == 1:
                return True
            else:
                return False

            
# math proof of repeat in this problem
#https://leetcode.com/problems/happy-number/discuss/56919/Explanation-of-why-those-posted-algorithms-are-mathematically-valid
