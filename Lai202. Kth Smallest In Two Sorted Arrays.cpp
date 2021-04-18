// median of two sorted array的前置题目
class Solution {
 public:
  int kth(vector<int> a, vector<int> b, int k) {
      return kth(a, b, k, 0, 0);  
  }
  int kth(vector<int>& a, vector<int>& b, int k, int sa, int sb){
      int na = a.size(), nb = b.size();
      if(sa >= na) return b[sb+k-1];
      if(sb >= nb) return a[sa+k-1];
      if(k == 1) return min(a[sa], b[sb]);
      int half = k / 2;

      if(sa + half > na){
          return kth(a, b, k-half, sa, sb+half);
      }
      if(sb + half > nb){
          return kth(a, b, k-half, sa+half, sb);
      }
      if(a[sa+half-1] >= b[sb+half-1]){
          return kth(a, b, k-half, sa, sb+half);
      }
      else{
          return kth(a, b, k-half, sa+half, sb);
      }
  }

};
