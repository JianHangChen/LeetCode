主要掌握 merge sort和n^2 sort的方法
// !!! sol3, O(nlogn), O(n)
// merge sort
class Solution {
 public:
  void sort(stack<int>& s1) {
      stack<int> s2;
      stack<int> s3;
      sort(s1, s2, s3, s1.size());
  }
  void sort(stack<int>& s1,stack<int>& s2, stack<int>& s3, int len) {
    if(len <= 1) return;
    int mid1= len / 2, mid2 = len - mid1;
    for(int i = 0; i < mid2; i++){
      s2.push(s1.top()); s1.pop();
    }
    sort(s1, s2, s3, mid1);
    sort(s2, s1, s3, mid2);
    int i = 0, j = 0;
    while(i < mid1 && j < mid2){
      if(s1.top() < s2.top()){
        s3.push(s1.top()); s1.pop();
        i++;
      }
      else{
        s3.push(s2.top()); s2.pop();
        j++;
      }
    }
    while(i <mid1){
        s3.push(s1.top()); s1.pop();
        i++;
    }
    while(j <mid2){
        s3.push(s2.top()); s2.pop();
        j++;
    }
    while(len > 0){
      s1.push(s3.top()); s3.pop();
      len--;
    }
  }
};


// !!sol2.1, O(n^2), O(n)
// https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/
class Solution {
 public:
  void sort(stack<int>& s1) {
      stack<int> s2;
      while(!s1.empty()){
        int tmp = s1.top(); s1.pop();
        while(!s2.empty() && s2.top() > tmp){
          s1.push(s2.top()); s2.pop();
        }
        s2.push(tmp);
      }
      while(!s2.empty()){
        s1.push(s2.top()); s2.pop();
      }
  }
};

sol2, O(n^2), O(n)
my, using two stack
class Solution {
 public:
  void sort(stack<int>& s1) {
      stack<int> s2;
      int n = s1.size();
      for(int i = n; i > 0; i--){
        int maxval = INT_MIN;
        for(int j = 0; j < i; j++){
          maxval = max(maxval, s1.top());
          s2.push(s1.top());  s1.pop();
        }
        s1.push(maxval);
        while(!s2.empty()){
          if(s2.top() == maxval){
            maxval = INT_MIN;
          }
          else{
            s1.push(s2.top());
          }
          s2.pop();
        }
      }
  }
};

sol1, O(n^2), O(n)
my, using three stack
class Solution {
 public:
  void sort(stack<int>& s1) {
      stack<int> s2;
      stack<int> s3;
      while(!s1.empty()){
        int minval = INT_MAX; 
        while(!s1.empty()){
            s2.push(s1.top());
            minval = min(minval, s1.top()); s1.pop();
        }
        s3.push(minval);
        while(!s2.empty()){
            if(s2.top() != minval){
              s1.push(s2.top());  
            }
            else{
              minval = INT_MAX;
            }
            s2.pop();
        }
      }
      while(!s3.empty()){
        s1.push(s3.top()); s3.pop();
      }

  }
};
