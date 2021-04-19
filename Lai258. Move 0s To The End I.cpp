// O(n), O(1)
// 易错，一定要注意双指针的位置
class Solution {
 public:
  vector<int> moveZero(vector<int> array) {
      int i = 0, j = array.size() - 1, t = 0;
      while(t <= j){
          if(array[t] == 0){
            swap(array[t], array[j--]);
          }
          else{
            swap(array[t++], array[i++]);
          }
      }
      return array;
  }
};
