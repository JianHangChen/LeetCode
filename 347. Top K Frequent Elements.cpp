// !!!! sol4, bucket sort, O(n), O(n), n is the size of nums
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> m;
        for(int num:nums) m[num]++;
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto& item:m){
            bucket[item.second].push_back(item.first);
        }
        for(int i = n ; i >= 0; i--){
            for(auto num:bucket[i]){
                res.push_back(num);
                k--;
                if(k == 0) return res;
            }
        }
        return res;        
    }
};



// sol5, from sol2, O(n), O(n), quick select
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int> res;
//         unordered_map<int, int> m;
//         for(int num:nums) m[num]++;
//         vector<int> numbers;
//         for(auto& item:m) numbers.push_back(item.first);
//         k = numbers.size() - k; // top k infrequent
        
//         quickselect(numbers, m, 0, numbers.size() - 1, k);
//         for(int i = k; i < numbers.size(); i++) res.push_back(numbers[i]);
//         return res;        
//     }
//     void quickselect(vector<int>& numbers, unordered_map<int, int>& m, int start, int end, int k){
//         if(start == end) return;
        
//         int pivot = partition(numbers, m, start, end);
        
//         if(pivot == k - 1) return; // find the top k infrequent
//         else if(pivot > k - 1) quickselect(numbers, m, start, pivot - 1, k);
//         else quickselect(numbers, m, pivot + 1, end, k);
//     }
    
//     int partition(vector<int>& numbers, unordered_map<int, int>& m, int start, int end){
//         int t = start + random() % (end - start + 1);
//         swap(numbers[start], numbers[t]);   
        
//         int pivot_val = m[numbers[start]];
//         int l = start + 1, r = end;
//         while(l <= r){
//             if(m[numbers[l]] > pivot_val && m[numbers[r]] <= pivot_val){
//                 swap(numbers[l++], numbers[r--]);
//             }
//             else if(m[numbers[l]] <= pivot_val) l++;
//             else r--;
//         }
//         swap(numbers[start], numbers[r]);
//         return r;
//     }
    
// };


// sol3, priority queue,  O(nlog(n-k)), O(n), n is the unique number in nums
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for(auto num: nums){
//             m[num]++;
//         }
//         int n = m.size();
//         vector<int> res;
//         priority_queue<vector<int> > pq;
//         for(auto& item:m){
//             pq.push({item.second, item.first});
//             if(pq.size() > n - k){
//                 res.push_back(pq.top()[1]);
//                 pq.pop();
//             }
//         }
//         return res;        
//     }
// };

//sol 2.1 my, bad, O(nlogn), O(n), map + sort for count array, n is the distinct number in the array
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> m;
//         for(int num:nums){
//             m[num]++;
//         }
//         vector<vector<int>> v;
//         for(auto& item:m){
//             v.push_back( {item.second, item.first});
//         }
//         sort(v.begin(), v.end() );
//         vector<int> res;
        
//         int count = 0, i = v.size() - 1; 
//         while(count < k){
//             res.push_back(v[i--][1]);
//             count++;
//         }
        
        
//         return res;       
        
//     }
// };





// sol2, priority queue, O(nlogn), O(n), n is the number of unique number
// class Solution{
// public:
//     vector<int> topKFrequent(vector<int>& nums, int K){
//         vector<int> res;
//         unordered_map<int, int> m;
//         priority_queue<vector<int>> pq;
//         for(auto num:nums) m[num]++;
//         for(auto iter:m) pq.push({iter.second, iter.first});
//         for(int i = 0; i < K; i++){
//             res.push_back( (pq.top())[1] ); pq.pop(); 
//         }
//         return res;

//     }
// };





//sol1, my, tree_map, O(nlogn), O(n), n is the number of unique number

// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         vector<int> res;
//         unordered_map<int, int> m;
//         map<int, vector<int>, greater <int> > ordered_m;

//         for(auto num:nums)  m[num]++;
        
//         for(auto element:m){
//             ordered_m[ element.second ].push_back( element.first); 
//         }        
//         for(auto element:ordered_m){
//             for(auto num:element.second){
//                 res.push_back(num);
//                 k--;                
//             }
//             if(k == 0){
//                 break;
//             }
//         }
        
//         return res;
//     }
