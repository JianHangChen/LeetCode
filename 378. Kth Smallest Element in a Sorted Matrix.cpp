//!!!! sol3, binary search in range x, count by sorted matrix property, by gy3, O(nlog(x)), O(1)

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



//!!!!! sol1.1, dijkstra
// similar to sol1
// klog(min(m, k)), O(k)
class Solution {
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}};
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        int count = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({matrix[0][0], 0, 0}); 
        matrix[0][0] = INT_MAX;
        while(!pq.empty()){
            auto cur = pq.top(); pq.pop();
            count++;
            if(count == k) return cur[0];
            int i = cur[1], j = cur[2];
            
            for(auto& dir:dirs){
                int x = i + dir[0], y = j + dir[1];
                if(isvalid(x, y, m, n, matrix)){
                    pq.push({matrix[x][y], x, y});
                    matrix[x][y] = INT_MAX;
                }
            }            
        }
        
        return -1;
    }
    bool isvalid(int x, int y, int m, int n, vector<vector<int>>& matrix){
        if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MAX) return false;
        return true;        
    }
};

// [[X,5|,9],
// [10|,11,13]
// [12,13,15]], k = 8 -> 13

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
