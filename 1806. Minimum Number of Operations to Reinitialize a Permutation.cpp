// !!! sol2, simulation, O(n), O(1)
// https://leetcode-cn.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/solution/shu-xue-on-suan-fa-by-arsenal-591-xatz/


// value[new_idx] = value[old_idx / 2]
// old_idx -> 2 * old_idx % (n-1)

// i -> f(i) -> f[f(i)] ... -> i for all i


// i -> 2 * i % (n-1) -> 2 *(2 * i % (n-1)) % (n-1) = 2^2 * i % (n-1)

// from i,  

// f^k(i) = 2^k * i % (n-1) -> i
// (17) * i = (15)
// f^k(1) = 2^k % (n-1) -> 1

// a b  a^k % b = 1,  k = phi(b) ~ O(b)
// 2, (n-1)

// [0 1 2 ... 9]
// f^k(3) -> 3 

// [0 1 2 3 4 5]
// [0 3 1 4 2 5]
// i = i * 2
// i = i * 2 % (n-1) = 3 x 2 % 5 = 1

// [0 1 2 3]
// [0 2]
// arr[0] = perm[i/2]
// arr[1] = perm[n / 2 + (1 - 1)/2] = perm[n / 2] = perm[2]
class Solution {
public:
    int reinitializePermutation(int n) {
        if(n == 2) return 1;
        int i = 1, count = 0; 
        while(true){ // O(n)
            i = (2 * i) % (n - 1);
            count++;
            if(i == 1) return count;
        }
        return -1;
    }
};

// sol1, my, simulation, O(nk), O(n) where k is the total permutation, where k <= n
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> arr;
        for(int i = 0; i < n; i++) arr.push_back(i);
        
        int count = 0;
        while(true){ // O(n)
            arr = permute(arr, n); 
            count++;
            if(check(arr)) return count; // O(n)
        }
        
        return -1;
    }
    bool check(vector<int>& arr){
        for(int i = 0; i < arr.size() - 1; i++){
            if(arr[i] + 1 != arr[i+1]) return false;
        }
        return true;
    }
    vector<int> permute(vector<int> arr, int n){
        vector<int> arr_ = arr;
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) arr_[i] = arr[i / 2];
            else arr_[i] = arr[n / 2 + (i - 1) / 2];
        }
        return arr_;
    }
};


// i = i * 2  - n + 1 if(i * 2 >= n)

// if i == n / 2 -> new_i = 1
// i = i * 2 % (n - 1)

// 6->4
// [0 1 2 3 4 5]
// [0 2 4 1 3 5]
// [0 4 3 2 1 5]
// [0 3 1 4 2 5]
// [0 1 2 3 4 5]

// 8 -> 3
// [0 1 2 3 4 5 6 7]
// [0 2 4 6 1 3 5 7] 
// [0 4 1 5 2 6 3 7]
// [0 1 2 3 4 5 6 7]
