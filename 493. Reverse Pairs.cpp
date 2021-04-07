// ! sol3, bit, O(nlogn), O(n) 
// from sol
class Solution {
private:
    vector<int> bit;
    int n;
public:
    int search(int index){
        int count = 0;
        int i = index + 1;
        while(i <= n){
            count += bit[i];
            i += i&(-i);
        }
        return count;
    }
    void update(int index){
        int i = index + 1;
        while(i > 0){
            bit[i] += 1; //increment 1
            i -= i&(-i); // 
        }
    }
    
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        bit.resize(n+1, 0);

        int res = 0;
        for(int i = 0; i < n; i++){
            int indexUpper = upper_bound(sortedNums.begin(), sortedNums.end(), 2L * nums[i]) - sortedNums.begin(); //logn           
            res += search(indexUpper); // return count of >= target,  logn
            
            int indexNum = lower_bound(sortedNums.begin(), sortedNums.end(), nums[i]) - sortedNums.begin();
            update(indexNum);
        }
        return res;
    }
};


// sol2, bst, tle
// O(nlogn) but O(n^2) in worst case, O(n) space
// from https://leetcode.com/problems/reverse-pairs/discuss/97268/general-principles-behind-problems-similar-to-reverse-pairs
// class Solution {
// public:
//     struct Nod{
//         Nod* left = NULL, * right = NULL;
//         int count = 1; // large or equal to, nod itself count 1
//         int val;
//         Nod(int x):val(x){}
//     };
//     Nod* root;
    
//     Nod* insert(int num, Nod* cur){
//         if(cur == NULL){
//             cur = new Nod(num);
//         }
//         else if(num < cur->val){
//             cur->left = insert(num, cur->left);
//         }
//         else if(num == cur->val){
//             cur->count++;
//         }
//         else{ // num > cur->val
//             cur->count++;
//             cur->right = insert(num, cur->right);
//         }
//         return cur;
//     }
//     int search(long num, Nod* cur){
//         if(cur == NULL) return 0;
//         if(num < cur->val){
//             return search(num, cur->left) + cur->count;
//         }
//         if(num == cur->val) return cur->count;
//         return search(num, cur->right);
//     }
    
//     int reversePairs(vector<int>& nums) {
//         int res = 0;
//         for(int num:nums){
//             res += search(2L * num + 1, root);
//             root = insert(num, root);
//         }
//         return res;
//     }
// };

// !!! sol1,  merge sort, O(nlogn), O(n)
// https://www.youtube.com/watch?v=TXOXKILPMVI

// TODO: https://leetcode.com/problems/reverse-pairs/discuss/97268/general-principles-behind-problems-similar-to-reverse-pairs
// https://www.cnblogs.com/grandyang/p/6657956.html
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergesort(nums, 0, n - 1);
    };
    // merge and get the reverse pairs
    int mergesort(vector<int>& nums, int start, int end){
        if(start >= end) return 0;
        int mid = start + (end - start) / 2;
        
        int res = mergesort(nums, start, mid);
        res += mergesort(nums, mid + 1, end);
        
        
        res += merge2(nums, start, mid, end);
        
        return res;
    }
    
    int merge2(vector<int>& nums, int start, int mid, int end){
        vector<int> tmp(end - start + 1);
        int i = start, j = mid + 1, k = 0;
        int res = 0;
        while(i <= mid && j <= end){
            if((long)nums[i] > 2 * (long)nums[j]){
                res += mid - i + 1;
                j++;
            }
            else i++;
        }
            
        // i = start; j = mid + 1;
        // [start ,.i... mid],  [mid+1, ..... end]
        while(i <= mid || j <= end){
            if(i > mid || j <= end && nums[i] >= nums[j]){
                tmp[k++] = nums[j++];// count += max(mid - i + 1, 0)
            }
            else{
                tmp[k++] = nums[i++];
            }
        }
        for(int t = 0; t < tmp.size(); t++){
            nums[start+t] = tmp[t];
        }
        return res;
    }
    
};


