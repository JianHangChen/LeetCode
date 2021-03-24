//!! sol2, my, O(sqrt(n)loglogn), O(n)

class Solution {
public:
// 2->1, 3->2, 5->3
    int kthPrime(int n) {
        if(n <= 1) return 0;
        int notprime = 0;
        vector<int> isprime(n+1, true);
        int res = 0;
        for(int i = 2; i * i <= n; i++){
            if(isprime[i]){
                res++;
                for(int j = 2; j * i <= n; j++){
                    if(isprime[i*j]){
                        notprime++;
                        isprime[i*j] = false;
                    }
                }
            }
        }
        return n - 1 - notprime;
    }
};

//!!! sol1, my, O(nloglogn), O(n)
class Solution {
public:
// 2->1, 3->2, 5->3
    int kthPrime(int n) {
        if(n <= 1) return 0;
        vector<int> isprime(n+1, true);
        int res = 0;
        for(int i = 2; i <= n; i++){
            if(isprime[i]){
                res++;
                for(int j = 2; j * i <= n; j++){
                    if(isprime[i*j]){
                        isprime[i*j] = false;
                    }
                }
            }
        }
        return res;
    }
};
