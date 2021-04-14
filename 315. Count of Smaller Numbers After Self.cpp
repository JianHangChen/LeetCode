!!! sol3, bit similar template in reverse pair
https://leetcode.com/problems/reverse-pairs/
class Solution {
public:
    vector<int> bit;
    int Search(int idx){
        int i = idx + 1;
        int res = 0;
        while(i > 0){
            res += bit[i];
            i -= i & (-i);
        }
        return res;
    }
    void Insert(int idx){
        int i = idx + 1;
        while(i <= n){
            bit[i]++;
            i += i & (-i);
        }
    }

    int n;
    vector<int> countSmaller(vector<int>& nums) {
        n = nums.size();
        vector<int> sorted(nums), res(n, 0);
        sort(sorted.begin(), sorted.end());    
        bit.resize(n + 1, 0); 
        
        for(int i = n-1; i >= 0; i--){
            // find nums[i], idx is nums[i] index in sorted.
            int idx = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin();
            // how many smaller in the bit, so use idx -1, find how many number in bit <= sorted[idx-1]
            res[i] = Search(idx - 1);
            Insert(idx);
        }
        return res;
    }
};

!!! sol2, binary search tree, from gy,  O(nlogn) avg but O(n^2) in worst case, O(n)
tle, still a very good solution
https://leetcode.com/problems/count-of-smaller-numbers-after-self/discuss/76657/3-ways-(Segment-Tree-Binary-Indexed-Tree-Binary-Search-Tree)-clean-python-code
class Solution {
public:
    struct Nod{
        int val;
        int count = 1;  // count the number equals val
        int count_smaller = 0; // smaller nodes in the left side of current nod
        Nod* left = NULL, *right = NULL;
        Nod(int x):val(x){};
    };
    Nod* root = NULL;
    int InsertAndFindSmaller(int num, Nod*& cur){ // remember to use & for change previous current status
        if(cur == NULL){
            cur = new Nod(num);
            return 0;
        }

        if(num < cur->val){
            cur->count_smaller++;
            return InsertAndFindSmaller(num, cur->left);
        }
        else if(num == cur->val){
            cur->count++;
            return cur->count_smaller;
        }
        else{ // >
            return cur->count_smaller + cur->count + InsertAndFindSmaller(num, cur->right);
        }

    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        for(int i = n - 1; i >= 0; i--){
            count[i] = InsertAndFindSmaller(nums[i], root);
        }
        return count;
    }
};

!!! sol1, merge sort, O(nlogn), O(n)
https://www.youtube.com/watch?v=AeyUmjk4HGQ
[1,9,7,8,5]
1 0, 9 1, 7 2, 8 3, 5 4
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> data;
        for(int i = 0; i < n; i++) data.push_back(pair<int, int> {nums[i], i}); // pair here is much more fast than vector
        
        vector<int> count(n, 0);
        MergeSort(data, count, 0, n - 1);
        return count;
    }
    void MergeSort(vector<pair<int, int>>& data, vector<int>& count, int start, int end){
        if(start >= end) return;
        int mid = start + (end - start) / 2;
        MergeSort(data, count, start, mid);
        MergeSort(data, count, mid+1, end);
        Merge(data, count, start, mid, end);        
    }

    // 2 5 1 6
    void Merge(vector<pair<int, int>>& data, vector<int>& count, int start, int mid, int end){
        vector<pair<int, int>> tmp(end - start + 1);
        int cur = 0, i = start, j = mid + 1, k = 0;
        while(i <= mid && j <= end){
            if(data[i].first > data[j].first){
                cur++;
                tmp[k++] = data[j++]; 
            }
            else{
                count[data[i].second] += cur; // carefully add instead of = cur
                tmp[k++] = data[i++];
            }
        }
        
        while(i <= mid){ // !! remember to check i and j if they are not visited
            count[data[i].second] += cur;
            tmp[k++] = data[i++];
        }
        while(j <= end){
            tmp[k++] = data[j++];
        }
        
        for(k = 0; k < tmp.size(); k++){
            data[start + k] = tmp[k];
        }
    }
    
};

5 2 | 6 1
1 0 | 1 0

2 5 | 1 6
1 1   1 0

2 1   1 0
