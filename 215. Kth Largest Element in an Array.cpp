//!!!!! sol3.1 revise sol3 from gy3, O(n), O(1)
// worst case O(n^2)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while(true){
            int pivot = partition(nums, left, right);
            if(pivot == k - 1){
                return nums[pivot];
            }
            else if(pivot > k - 1){
                right = pivot - 1;
            }
            else{
                left = pivot + 1;
            }
        }
        return -1;
    }
    
    int partition(vector<int>& nums, int start, int end){
        int pivot = start + rand() % (end - start + 1); // !!! important to randomize the pivot element to ensure everage O(n) speed
        swap(nums[pivot], nums[start]);
        
        int i = start + 1, j = end;
        while(i <= j){
            if(nums[i] < nums[start] && nums[j] > nums[start]){
                swap(nums[i++], nums[j--]);
            }
            else if(nums[i] >= nums[start]){
                i++;
            }
            else{ // nums[j] <= nums[start]
                j--;
            }            
        }
        swap(nums[start], nums[j]);
        return j;
    }
    
};

// // sol3, O(n), O(n), selection sort, O(n) space because of recursive space

// // [3,2,1,5,6,4] and k = 2
// // O(n), pivot 3, left: 2 1, right: 5,6,4
// // avg O(n/2) right: 5,6,4 pivot: 5, left 4, right 6
// // return 5

// // [3,2,3,1,2,4,5,5,6] and k = 4
// // 4
// // O(n) pivot 3, left 1 2 2  right 3, 4, 5, 5, 6
// // O(n/2)  pivot 3 left: [] right: 4, 5, 5, 6
// //  pivot 4, left:[] right:5,5,6  left_count = k - 1
// // return 4


// // n + n/2 +...n/2^k =  n( 1 + 1/2 + 1/2^k) = n*1*(1 - (1/2)^k)/(1-(1/2)) = 2n
// // O(n)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k, 0, nums.size() - 1);
    }
    
    int findKthLargest(vector<int>& nums, int k, int start, int end){
        
        int pivot = partition(nums, start, end);
        int left_len = pivot - start, right_len = end - pivot;
        if(right_len == k - 1){
            return nums[pivot];
        }
        else if(right_len > k - 1){
            return findKthLargest(nums, k, pivot + 1, end);
        }
        else{
            return findKthLargest(nums, k - right_len - 1, start, pivot - 1);
        }     
    }
    int partition(vector<int>& nums, int start, int end){
        int i = start, j = end + 1;
        while(true){
            while(i != end && nums[++i] < nums[start]){}
            while(j != start && nums[--j] > nums[start]){}
            if(i >= j) break;
            swap(nums[i], nums[j]);
        }
        swap(nums[start], nums[j]);
        return j;
    }
    
};


// sol2, multiset, O(nlog(k)), O(k)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int> s;
        for(auto num:nums){
            s.insert(num);
            if(s.size() > k){
                s.erase(s.begin());
            }
        }
        return *(s.begin());
    }
};