// sol3, !!! linear scan from grand yang, fix the last, also very good O(n^2), O(logn)

class Solution{
public:
  int triangleNumber(vector<int>& nums){
    int count = 0, n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = n - 1; i >= 2; i--){
      int left = 0, right = i - 1;
      while(left < right){
        if(nums[left] + nums[right] > nums[i]){
          count += right - left;
          right--;
        }
        else{
          left++;
        }
      }
    }
    return count;
  }
};



// sol2, !!!! linear scan, from sol3 O(n^2), O(logn)

class Solution{
public:
  int triangleNumber(vector<int>& nums){
    int count = 0, n = nums.size();
    sort(nums.begin(), nums.end());

    for(int i = 0; i < n - 2; i++){
      for(int j = i + 1, k = j + 1; j < n - 1; j++){
        if(j == k) k++; // !!!!
        while(k < n && nums[i] + nums[j] > nums[k]){
          k++;
        }
        count += k - j - 1;
      }
    }
    return count;
  }
};






// my sol1, O(n^2logn), O(logn) [sort]

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0, n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0; i < n - 2; i++){
          for(int j = i + 1; j < n - 1; j++){
            auto lb = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);

            count += lb - nums.begin() - j - 1;


          }
        }

        return count;
    }
};

