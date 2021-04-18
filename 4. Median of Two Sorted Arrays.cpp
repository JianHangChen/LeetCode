//!!!, from sol1 of grandyang
// O(log(m+n)), O(log(m+n))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        // 123-> 2th  (3+1)/2 = 2th and (3+2)/2 = 2th
        // 1234-> 2th and 3th  (4+1)/2 = 2th, (5+1)/2 = 3th
        int k1 = (n1 + n2 + 1) / 2, k2 = (n1 + n2 + 2) / 2; // !!! careful about the index
        double a1 = findkth(nums1, nums2, k1, 0, 0);
        double a2 = findkth(nums1, nums2, k2, 0, 0);
        return (a1+a2) / 2.0;
    }
    double findkth(vector<int>& nums1, vector<int>& nums2, int k, int s1, int s2){
        int n1 = nums1.size(), n2 = nums2.size();
        if(s1 >= n1) return nums2[s2 + k - 1];
        if(s2 >= n2) return nums1[s1 + k - 1];
        if(k == 1) return min(nums1[s1], nums2[s2]); // !!!important here about the exit condition
        
        int half = k / 2;
        if(s1 + half - 1 >= n1){ 
            // !!! very careful about this case, 
            // when s1 is not enough for half, the [s2, s2+half) is not the answer of kth element, delete it
            return findkth(nums1, nums2, k - half, s1, s2 + half);
        }
        if(s2 + half - 1 >= n2){
            return findkth(nums1, nums2, k - half, s1+half, s2);
        }
        
        if(nums1[s1 + half - 1] >= nums2[s2 + half - 1]){
            return findkth(nums1, nums2, k - half, s1, s2 + half);
        }
        else{
            return findkth(nums1, nums2, k - half, s1+half, s2);
        }
    }
};

