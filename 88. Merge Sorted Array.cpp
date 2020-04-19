// !!!!! sol1.1, from gy, O(n+m), O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 && n > 0){
            if(nums1[m-1] > nums2[n-1]){
                nums1[m+n-1] = nums1[m-1];
                m--;
            }
            else{
                nums1[m+n-1] = nums2[n-1];
                n--;
            }            
        }
        while(n > 0){
            nums1[n-1] = nums2[n-1];
            n--;
        }
    }
};

my sol1, start from end, O(n+m), O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0) return;
        
        int i = m - 1, j = n - 1;
        
        while(i >= 0 || j >= 0){
            if(i>=0 && nums1[i] > nums2[j]){
                nums1[i+j+1] = nums1[i];
                i--;
            }
            else{
                nums1[i+j+1] = nums2[j];
                j--;
                if(j < 0) break;
            }
            
        }
        

    }
};
