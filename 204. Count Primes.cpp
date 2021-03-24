//!! sol2.1, O(sqrt(n)log(logn)), O(n)
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> isPrime(n, true);
        int notPrime = 0;
        for(int i = 2; i * i < n; i++){
            if(isPrime[i]){
                for(int j = 2; i * j < n; j++){
                    if(isPrime[i*j]){
                        isPrime[i * j] = false;
                        notPrime++;
                    }
                }
            }
        }
        return n-2 - notPrime;
    }
};



// 2 3 4 5 6 7 8 9 10 11 12 13
// 2 3 x 5 x   x   x   

// 10
// 3 x 3  = 9

//!!! sol2, O(nlog(logn)), O(n)
// analysis https://leetcode.com/problems/count-primes/discuss/473021/Time-Complexity-O(log(log(n)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isprime(n, true);
        int res = 0;
        for(int i = 2; i < n; i++){
            if(isprime[i]){
                res++;
                for(int j = 2; i * j < n; j++){
                    isprime[i * j] = false;
                }
            }
        }
        return res;
    }
};


!sol1.1, isprime, O((nsqrt(n))), O(1)
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        for(int i = 2; i < n; i++){
            if(isprime(i)) res++;
        }
        return res;
    }
    bool isprime(int i){
        for(int j = 2; j * j <= i; j++){
            if(i % j == 0) return false;
        }
        return true;
    }
    
};


sol1, brute force, O((n^2)), O(n)
class Solution {
public:
    int countPrimes(int n) {
        vector<int> primes;
        for(int i = 2; i < n; i++){
            int j = 0;
            while(j < primes.size()){
                if(i % primes[j] == 0) break;
                j++;
            }
            if(j == primes.size()){
                primes.push_back(i);
            }
        }
        return primes.size();
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
