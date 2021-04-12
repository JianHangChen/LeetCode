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
