// sol2, !!! prime factorization 
class Solution{
public:
    int minSteps(int n){
        int res = 0;
        int f = 2;
        while(n > 1){
            while(n % f == 0){
                res += f;
                n /= f;
            }
            f++;
        }      
        return res;
    }
};

// sol1, dp
class Solution {
public:
    int minSteps(int n) {
        vector<int> steps(n+1, 0);
        
        for(int i = 1; i <= n; i++){
            int base = steps[i];
            for(int j = 2; j * i <= n; j++){
                steps[j*i] = base + j;
            }
        }
        return steps[n];
    }
};
