




// !!!!!!!!!1 sol4, bucket sort, O(n)
class Solution{
public:
  vector<int> topKFrequent(vector<int>& nums, int K){
    int n = nums.size();
    vector<int> res;
    unordered_map<int, int> m;
    
    for(auto num:nums) m[num]++;
    vector<vector<int>> bucket(n + 1);
    
    for(auto iter:m){
      bucket[iter.second].push_back(iter.first);
    }
    
    reverse(bucket.begin(), bucket.end());
    
    for(int i = 0; i < n + 1; i++){
      for(int num:bucket[i]){
        res.push_back(num);
        K--;
        if(K == 0) return res;
      }
    }
    return res;
  }
  
};




//!!  sol3, priority queue, O(nlog(n-k) , O(n), n is the number of unique number
class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int K){
        
        vector<int> res;
        unordered_map<int, int> m;
        priority_queue<vector<int>> pq;
        for(auto num:nums) m[num]++;
        int n = m.size();
        for(auto iter:m){
            pq.push({iter.second, iter.first});
            if(pq.size() > n - K){
                res.push_back( pq.top()[1] ); pq.pop();
            }
        }
        return res;
    }
};







// sol2, priority queue, O(nlogn), O(n), n is the number of unique number
class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int K){
        vector<int> res;
        unordered_map<int, int> m;
        priority_queue<vector<int>> pq;
        for(auto num:nums) m[num]++;
        for(auto iter:m) pq.push({iter.second, iter.first});
        for(int i = 0; i < K; i++){
            res.push_back( (pq.top())[1] ); pq.pop(); 
        }
        return res;

    }
};





//sol1, my, tree_map, O(nlogn), O(n), n is the number of unique number

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        map<int, vector<int>, greater <int> > ordered_m;

        for(auto num:nums)  m[num]++;
        
        for(auto element:m){
            ordered_m[ element.second ].push_back( element.first); 
        }        
        for(auto element:ordered_m){
            for(auto num:element.second){
                res.push_back(num);
                k--;                
            }
            if(k == 0){
                break;
            }
        }
        
        return res;
    }
};
