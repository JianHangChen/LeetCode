// !!! sol1, my, same as gy, O(n), O(n)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> exist(n+1, false);
        int count = 0;
        for(int i = 2; i < n; i++){
            if(!exist[i]){
                count++;
                for(int j = 2; i * j < n; j++){
                    exist[i * j] = true;
                }
                
            }
        }
        return count;
        
    }
};



class Solution:
    # sol2, fill out the none prime and skip it
    # https://leetcode.com/problems/count-primes/discuss/57595/Fast-Python-Solution
    def countPrimes(self, n: 'int') -> 'int':
        if n < 3:
            return 0
        primes = [True] * n
        primes[0] = primes[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                primes[i * i:n:i] = [False] * len(primes[i * i:n:i])
        return sum(primes)
        

        # my sol1, brute force, too slow
#     def __init__(self):
#         self.prime_list = []
#     def countPrimes(self, n: 'int') -> 'int':
#         i = 2
#         res = 0
#         while i < n:
#             if self.isPrime(i):
#                 res += 1
#             i += 1
#         return res
#     def isPrime(self, n):
#         # if n == 1:
#         #     return False
#         for p in self.prime_list:
#             if n % p == 0:
#                 return False
#         self.prime_list.append(n)
#         return True
       
        
        
    #test: 1 -> 0
    # 2 -> 0
    # 3 -> 1
