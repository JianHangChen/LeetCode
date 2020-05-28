class Solution {
public:
    //!!!, from sol1 of grandyang
    //test: [], [1]
    // [1], [2]
    // [1], []
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int m1 = findKth(nums1, nums2, 0, 0, (n + m + 1) / 2);
        int m2 = findKth(nums1, nums2, 0, 0, (n + m + 2) / 2);
        return double(m1 + m2) / 2 ;
    }
    
    int findKth(vector<int>& nums1, vector<int>& nums2, int i, int j, int k){
        if(i >= nums1.size()) return nums2[j + k - 1];
        if(j >= nums2.size()) return nums1[i + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int mid1, mid2, num1, num2;
        mid1 = i - 1 + k / 2;
        mid2 = j - 1 + k / 2;
        
        num1 = (mid1 >= nums1.size()) ? INT_MAX : nums1[mid1];
        num2 = (mid2 >= nums2.size()) ? INT_MAX : nums2[mid2];
        if( num1 > num2 ){
            return findKth(nums1, nums2, i, j + k/2, k - k/2);
        }
        else{
            return findKth(nums1, nums2, i + k/2, j, k - k/2);
        }
    }
};
