

// sol2.1, !!! from sol2, O(n), O(1)


class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int left = 0, product = 1;
        int ans = 0;
        for(int right = 0; right < n; right++){
            product = nums[right] * product;
            while(product >= k){
                product /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};



// sol2, my, after hint, O(n), O(n)

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        
        vector<int> pos(n, -1);
        int product = nums[0];
        
        if(nums[0] < k){
            pos[0] = 0;
        }
        
        for(int i = 1; i < n; i++){
            if(pos[i-1] == -1){
                product = nums[i];
                if(product < k) pos[i] = i;
                continue;
            }
            
            product *= nums[i];
            for(int j = pos[i-1]; j <= i; j++){
                if(product < k){
                    pos[i] = j;
                    break;
                }
                else{
                    product /= nums[j];
                }
            }
        }
        

        for(int i = 0; i < n; i++){
            if(pos[i] == -1) continue;
            count +=  i - pos[i] + 1;            
        }
        return count;
    }
};

// sol1, brute force, TEL
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i < n; i++){
            int product = 1;
            for(int j = i; j < n; j++){
                product *= nums[j];
                if(product < k) count++;
                else break;
            }
        }
        return count;
    }
};


#include <math.h>
// sol3,  binary search
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        double lk = log(k); // careful
        
        int n = nums.size();
        vector<double> pre(n+1,0);
        for(int i = 0; i < n; i++){
            pre[i+1] = pre[i] + log(nums[i]);

        }
        
        int res = 0;
        
        for(int i = 0; i < n; i++){

            auto lb = lower_bound(pre.begin() + i + 1, pre.end(), pre[i] + lk  ); // lower_bound

            res += (lb - pre.begin()) - i - 1;
        }
        
        return res;        
    }
    
};
