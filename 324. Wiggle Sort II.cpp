
//!!! sol3, virtual index, O(n), O(1)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size(), m = (n-1)/2;        
        nth_element(nums.begin(), nums.begin()+m, nums.end());
        int median = nums[m];
        int lo = 0, mid = 0, hi = n-1;
        int idx_lo, idx_mid, idx_hi;
        while(mid <= hi){
            idx_lo = get_idx(lo, n);
            idx_mid = get_idx(mid, n);
            idx_hi = get_idx(hi, n);
            if(nums[idx_mid] < median){
                swap(nums[idx_mid], nums[idx_lo] );
                lo++;
                mid++;
            }
            else if(nums[idx_mid] > median){
                swap(nums[idx_mid], nums[idx_hi]);
                hi--;
            }
            else{
                mid++;
            }
        }
    }    
    int get_idx(int i, int n){
        int m = (n-1) / 2;
        
        if(i <= m){
            return (m-i)*2; // return (n - 1 - !(n%2) - 2 * i);
        }
        else{
            return 1 + 2 * (n-1-i); // return (n - 1 - (n%2) - 2 * (i-m-1));
        }
        
    }
    
};

// requirement: with O(1) extra space?
// !! sol2, insertion, O(n), O(1) 
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        nth_element(nums.begin(), nums.begin() + m, nums.end()); // find median
        
        int median = nums[m];
        int big = 1, small = n % 2 == 1 ? n - 1 : n - 2;
        int i = 0;
        while(i < n){
            if(nums[i] < median && (i%2 == 1 || i < small)){
                swap(nums[i], nums[small]);
                small -= 2;
                continue;
            }
            if(nums[i] > median && (i%2 == 0 || i > big)){
                swap(nums[i], nums[big]);
                big += 2;
                continue;
            }
            i++;
        }
    }
};

// sol1, sort, O(nlogn), O(n) extra
// proof https://leetcode.com/problems/wiggle-sort-ii/discuss/77678/3-lines-Python-with-Explanation-Proof
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> tmp = nums;
//         sort(tmp.begin(), tmp.end());
//         int mid = (n-1) / 2 , end = n - 1;
//         int i = 0;
//         while(i < n){
//             nums[i++] = tmp[mid--];
//             if(i < n) nums[i++] = tmp[end--];
//         }
        
//     }
// };
