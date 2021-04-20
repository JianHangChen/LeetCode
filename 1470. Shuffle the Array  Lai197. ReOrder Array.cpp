// inplace, O(nlogn), O(logn)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        Shuffle(nums, 0, nums.size() - 1);
        return nums;
    }
    void Shuffle(vector<int>& nums, int start, int end){
        int l = end - start + 1;
        if(l <= 2) return;
        // [start, lm)  [lm, mid) [mid, rm) [rm, end]
        // 01234567
        // l = 8, lm = 2 mid = 4 rm = 6
        // 0|12|3|45
        // l / 4 = 1
        // l = 6, lm = 1 mid = 3 rm = 3+1 =4
        
        
        int mid = start + l / 2;
        int lm = start + l / 4, rm = mid + l / 4;

        reverse(nums.begin() + lm, nums.begin() + mid);
        reverse(nums.begin() + mid, nums.begin() + rm);
        reverse(nums.begin() + lm, nums.begin() + rm);

        Shuffle(nums, start, start + l/4 * 2 - 1);
        Shuffle(nums, start+l/4*2, end);
    }
    
};

// V    0 1 2 3 4 5
// nums 0 3 1 4 2 5
// i in V, idx in nums is:
// i <= mid i*2
// i > mid (i - mid - 1)* 2+1
// merge sort
// 0 A 1 B | 2  C 3 D
// 0 A | 1 B     2  C | 3 D
// 0 A      1 B     2  C   3 D
// 0 1  A B         2 3 C D

// 0 1 2 3 A B C D

Lai197. ReOrder Array


class Solution {
 public:
  vector<int> reorder(vector<int> array) {
      int n = array.size();
      reorder(array, 0, n - 1);
      return array;
  }
  void reorder(vector<int>& array, int start, int end) {
      int len = end - start + 1;
      // 0 1 |(2) 3 |(4) 5 |(6) 7
      
      // 0 1 |(2) 3| (4) 5 | (6) 7 8
      // 0 |(1) 2 | (3)| 4 5

      // 0 |(1) 2 |(3) |(4) 5 6
      int mid = start + len / 2; // 3 4 
      int lm = start + len / 4; // 1 2
      int rm = mid + len / 4; // 2 6

      if(len <= 3) return;
    
      reverse(array.begin() + lm, array.begin() + mid);
      reverse(array.begin() + mid, array.begin() + rm);
      reverse(array.begin() + lm, array.begin() + rm);
      reorder(array, start, start + len/4 * 2 - 1); // very easy to make mistake
      reorder(array, start + len/4 * 2, end);
  }

};
