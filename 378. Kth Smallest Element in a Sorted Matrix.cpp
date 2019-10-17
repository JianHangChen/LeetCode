//!!!! sol3, binary search in range x, count by sorted matrix property, by gy3, O(nlog(x))

class Solution{
public:
  int kthSmallest(vector<vector<int>>& matrix, int k){
    int n = matrix.size();
    if(n == 0) return 0;

    int left = matrix[0][0], right = matrix.back().back(), mid;

    while(left < right){
      mid = left + (right - left) / 2;
      if(count_less_equal(matrix, mid) >= k){
        right = mid;
      }
      else{
        left = mid + 1;
      }
    }
    return left;
  }

  int count_less_equal(vector<vector<int>>& matrix, int val){
    int count = 0;
    int n = matrix.size();
    int i = n - 1, j = 0; 
    while(i >= 0 && j < n){
      if(matrix[i][j] > val){
        i--;
      }
      else{
        count += i + 1;
        j++;
      }
    }
    return count;
  }
};




// sol2, binary search in range x, binary serach for count, by gy2, O(nlog(x)log(n))
class Solution{
public:
int kthSmallest(vector<vector<int>>& matrix, int k){
  int n = matrix.size();
  if(n == 0) return 0;
  int left = matrix[0][0], right = matrix[n-1][n-1], mid;
  while(left < right){
    mid = left + (right - left) / 2;

    int count = 0;
    for(int i = 0; i < n; i++){
      count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
    }
    if(count >= k){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  return left;
}

};


// sol1, priority queue n^2log(k)
class Solution{
public:
int kthSmallest(vector<vector<int>>& matrix, int k){
  priority_queue<int> pq;
  for (vector<int> v:matrix){
    for(int element:v){
      pq.push(element);
      if(pq.size() > k){
        pq.pop();
      }

    }
  }
  return pq.top();
}

};
