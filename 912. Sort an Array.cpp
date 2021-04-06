//!!! sol1, merge sort template
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }
    
    void mergesort(vector<int>& nums, int start, int end){
        if(start >= end) return;
        
        int mid = start + (end - start) / 2;
        mergesort(nums, start, mid);
        mergesort(nums, mid+1, end);
        merge2(nums, start, mid, end);
    }
    void merge2(vector<int>& nums, int start, int mid, int end){
        vector<int> tmp(end - start + 1);
        int k = 0, i = start, j = mid + 1;
        while(i <= mid || j <= end){
            if(i > mid || j <= end && nums[i] > nums[j]){
                tmp[k++] = nums[j++];
            }
            else{
                tmp[k++] = nums[i++];
            }
        }
        
        for(int i = 0; i < tmp.size(); i++){
            nums[start++] = tmp[i];
        }
    }
    
};
