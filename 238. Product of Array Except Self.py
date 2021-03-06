// !!! sol2, from sol2, O(n), O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n,1);
        for(int i = n - 2; i >= 0; i--){
            output[i] = output[i+1] * nums[i+1];
        }

        int left = 1;
        for(int i = 0; i < n; i++){
            output[i] = left * output[i];
            left = left * nums[i];
        }
        return output;       
    }
};


//! sol1, from sol1, before and after, O(n), O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1), right = left, output = left;
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] * nums[i-1];
        }
        for(int i = n - 2; i >= 0; i--){
            right[i] = right[i+1] * nums[i+1];
        }
        for(int i = 0; i < n; i++){
            output[i] = left[i] * right[i];
        }
        return output;       
    }
};


// sol1, from sol1, O(n), O(n)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n), right(n), res(n);

    left[0] = 1;
    right[n - 1] = 1;
    for(int i = 0; i < n - 1; i++){
        left[i+1] = left[i] * nums[i];
        right[n-i-2] = right[n-i-1] * nums[n-i-1];

    }
    for(int i = 0; i < n; i++){
        res[i] = left[i] * right[i];
    }
    return res;
}

// sol2, from sol2, O(n), O(1)
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);

    res[0] = 1;
    for(int i = 0; i < n - 1; i++){
        res[i+1] = res[i] * nums[i];            
    }

    int r = 1;
    for(int i = n - 1; i >= 0; i--){
        res[i] = res[i] * r;
        r = r * nums[i];
    }

    return res;
}
