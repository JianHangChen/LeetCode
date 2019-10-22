#include <iostream>

#include <vector>
using namespace std;

//!!!!! sol2, two pointer,O(n), O(1)

class Solution{
public:
    bool increasingTriplet(vector<int>& nums){
      int min1 = INT_MAX, min2 = min1;
      for(int num:nums){
        if(num > min2) return true;
        else if(num <= min1) min1 = num;
        else min2 = num;
      }
      return false;
    }
};




// ! sol3, forward and backward, also a nice solution, from gy3, O(n), O(n)

class Solution{
public:
    bool increasingTriplet(vector<int>& nums){
        int n = nums.size();
        if(n <= 2) return false;
        vector<int> forward(n), backward(n);
        
        forward[0] = nums[0];
        for(int i = 1; i < n; i++){
            forward[i] = min(forward[i-1], nums[i]);
        }

        backward[n-1] = nums[n-1];
        for(int i = n - 2; i >= 0; i--){
            backward[i] = max( backward[i+1], nums[i]);
        }

        for(int i = 0; i < n; i++){
            if( forward[i] < nums[i] && nums[i] < backward[i]) return true;
        }
        return false;
    }
};



// sol1, my brute force, TLE
class Solution{
  
public:
  bool increasingTriplet(vector<int>& nums){
    int n = nums.size();
    for(int i = 0; i < n; i++){
      for(int j = i + 1; j < n; j++){
        for(int k = j + 1; k < n; k++){
        
          if(nums[i] < nums[j] && nums[j] < nums[k]) return true;
        }
      }
    }
    return false;
  }

};

// To execute C++, please define "int main()"
int main() {
  
  Solution sol;

  
  //test 1
  //[1,2,3,4,5]
  // true
  
  
  vector<int> nums = {1,2,3,4,5};
  
  cout << sol.increasingTriplet(nums) << endl;  
  
  
  //test 2
  //[2,5,1,3]
  // false

  nums = {2,5,1,3};
  
  cout << sol.increasingTriplet(nums) << endl;  

  
  
  //test3
  //[2,5,1,6]
  //true
  
  nums = {2,5,1,6};
  
  cout << sol.increasingTriplet(nums) << endl;    
  
  return 0;
}
