// lower 8 upper 15
//   1        1
// 6 2 5 | 3 4 6
// [i, j] = presum[j + 1]-presum[i] 
//0 6 8 13 16 20 26
// !!! sol2, merge sort, O(nlogn), O(n)
// https://www.youtube.com/watch?v=PmgNJcbmpxg

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> presum(n+1, 0);
        for(int i = 0; i < n; i++) presum[i+1] = presum[i] + nums[i];
        return mergesort(presum, lower, upper, 0, n);
    }
    int mergesort(vector<long long>& presum, int lower, int upper, int start, int end){ 
        //[start, end) = [start, end-1] = presum[end] - presum[start]
        if(start >= end) return 0;
        
        int count = 0;
        int mid = start + (end - start)/2;

        count += mergesort(presum, lower, upper, start, mid);
        count += mergesort(presum, lower, upper, mid+1, end);
        count += merge2(presum, lower, upper, start, mid, end);

        return count;
    }
    int merge2(vector<long long>& presum, int lower, int upper, int start, int mid, int end){

        // 1. count
        int count = 0;
        int startIdx = mid+1, endIdx = mid+1;
        // lower <= presum[k] - presum[i] <= upper
        for(int i = start; i <= mid; i++){ //carefull!!!, i should start from start, not 0
            while(startIdx <=end && presum[startIdx] - presum[i] < lower){ // [i, startIdx-1]
                startIdx++;
            }
            while(endIdx <= end && presum[endIdx] - presum[i] <= upper){
                endIdx++;
            }
            count += endIdx - startIdx;
        }
        // 2.0 merge
        vector<long long> tmp(end - start + 1, 0);
        int i = start, j = mid+1, k = 0;

        while(i <= mid && j <= end){
            if(presum[i] <= presum[j]) tmp[k++] = presum[i++];
            else tmp[k++] = presum[j++];
        }
        while(i <= mid) tmp[k++] = presum[i++];
        while(j <= end) tmp[k++] = presum[j++];
        // 2.1 copy
        for(int t = 0; t < tmp.size(); t++) presum[start + t] = tmp[t];
        
        return count;
    }  
};




//!!! sol1, use multiset
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> s;
        long long presum = 0, count = 0;
        s.insert(0);
        // pre[k]-upper <= pre[i] <= pre[k]-lower
        for(int num:nums){
            presum += num;
            count += distance(s.lower_bound(presum - upper), s.upper_bound(presum - lower));
            s.insert(presum);
        }
        return count;
    }
};
