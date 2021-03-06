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


class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        # sol1: reverse thinking, fucking smart O(m+n)
        # https://leetcode.com/problems/merge-sorted-array/discuss/29503/Beautiful-Python-Solution
        # while m>0 and n > 0:
        #     if nums1[m-1] < nums2[n-1]:
        #         nums1[m+n-1] = nums2[n-1]
        #         n -= 1
        #     else:
        #         nums1[m+n-1] = nums1[m-1]
        #         m -= 1
        # nums1[m:m+n] = nums2[:n]
        
        # sol2: shit, just for practice of sort
        nums1[m:m+n] = nums2
        nums1.sort()
        
