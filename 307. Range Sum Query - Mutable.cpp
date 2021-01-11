//!!! sol4, segment tree, space O(n), build O(n), update O(logn), get O(logn)
class SegTreeNode{
public:
    SegTreeNode* left, *right;
    int start, end, val;
    SegTreeNode(int i, int j, int x):start(i), end(j), val(x){
    }
};
class NumArray {
public:
    SegTreeNode* segTreeRoot;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        segTreeRoot = buildSegTree(0, n-1, nums);
    }
    SegTreeNode* buildSegTree(int left, int right, vector<int>& nums){
        if(left > right) return NULL;
        SegTreeNode* root = new SegTreeNode(left, right, nums[left]);
        if(left == right){
            return root;
        }
        int mid = left + (right - left) / 2;
        root->left = buildSegTree(left, mid, nums);
        root->right = buildSegTree(mid+1, right, nums);
        root->val = root->left->val + root->right->val;
        return root;        
    }
    void update(int i, int val) {
        update(segTreeRoot, i, val);
    }
    void update(SegTreeNode* root, int i, int val){
        if(root->start == root->end && root->start == i){
            root->val = val; return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        if(i <= mid){
            update(root->left, i, val);
        }
        else{
            update(root->right, i, val);
        }
        root->val = root->left->val + root->right->val;        
    }
    int sumRange(int i, int j) {
        return sumRange(segTreeRoot, i, j);
    }
    int sumRange(SegTreeNode* cur, int i, int j){
        if(i > cur->end || j < cur->start || i > j) return 0;
        if(i<= cur->start && cur->end <= j) return cur->val;
        int mid = cur->start + (cur->end - cur->start) / 2;
        if(j <= mid) return sumRange(cur->left, i, j);
        if(i > mid) return sumRange(cur->right, i, j);
        return sumRange(cur->left, i, mid) + sumRange(cur->right, mid+1, j);
    }
};

// sol1,  update(O(sqrt(n)), sum O(sqrt(n))
// this solution is to separate n into sqrt(n) blocks, when you want to sum for [i,j], 
// just calculate the related block, block_start, block_end.
// final_sum = sum([block_start:block_start_end] , sum(block_start+1, block_end-1), [block_end_start:block_end])
class NumArray {
private:
    vector<int> block, data;
    int n, len;
public:
    NumArray(vector<int> nums) {
        data = nums;
        n = nums.size();
        
        double root = sqrt(n);
        len = ceil(root);
        block.resize(len, 0);

        for(int i = 0; i < n; i++){
            block[i/len] += data[i];
        }
    }
    
    void update(int i, int val) {
        block[i/len] += val - data[i];
        data[i] = val;
    }
    
    int sumRange(int i, int j) {
        int start = i/len, end = j/len;
        int s = 0;
        if(start == end){
            for(int k = i; k <= j; k++){
                s += data[k];
            }
            return s;
        }
        for(int k = i; k < (start + 1) * len; k++){
            s += data[k];
        }
        for(int k = start + 1; k < end; k++){
            s += block[k];
        }
        for(int k = end * len; k <= j; k++){
            s += data[k];
        }
        return s;
        
    }
};

// sol2, by Binary Indexd Tree (BIT), update O(logn),get O(logn) pace O(n)
// BIT is a relative complicated tree structure, we could use an array bit with size n+1 to store it.
// the position of bit index is i + 1 respectively
// when get sum of i, index = i+1, add bit[index] to sum and index -= (index&(-index)) when index > 0
// when update i, val , index = i+1, add off_set to bit[index] and index += (index&(-index)) when index <= n;
class NumArray{
private:
    vector<int> bit;
    vector<int> data;
    int n;
public:
    void update(int i, int val){
        int offset = val - data[i];
        data[i] = val;
        for(int index = i + 1; index <= n; ){
            bit[index] += offset;
            index += index&(-index);
        }
    }
    
    NumArray(vector<int> nums){
        n = nums.size();
        data.resize(n);// !!! data should not be nums because of update step
        bit.resize(n + 1, 0);
        for(int i = 0; i < n; i++){
            update(i, nums[i]);
        }
    }
    int getSum(int i){
        int s = 0, index = i + 1;
        while( index > 0){
            s += bit[index];
            index -= index&(-index); // carefully about bit manipulation has lower priority
        }
        return s;
    }
    
    int sumRange(int i, int j){
        return getSum(j) - getSum(i-1);
    }

};


// sol3, segment tree, update O(logn), get O(logn)
// use segment tree data structure
//1. create a st[] array with size of 2*n
// st[n:2n] = nums[0:n]
// st[i] = st[i*2]+st[i*2+1] when i < n, st[0] is the dummy point
// 2. when we want to get sum from i to j
// st[n+i], st[n+j] is the related nums[i],nums[j]
// if n+i, is in the left and n+j in the right side of the tree,
// their sum has already been calculated in their upper level (n+i)/2, (n+j)/2 respectively
// when they are not in the desired left or right position,
// for example, i in right position, add st[i] to sum and move i to i-1
// 3. for update of i, val
// just need to update their ancestors
// update i, and st[i/2] = st[i] + st[i ^ 1]
// here i^1 is the pair point of i, i.e. if i is left point 4, i ^ 1 = 5 is the right point in a pair

class NumArray{
private:
    int n;
    vector<int> st;
    vector<int> data;
public:
    // void update(int i, int val){
    //     int offset = val - data[i];
    //     data[i] = val;
        
    //     for(i += n; i > 0; i/=2){
    //         st[i] += offset;
    //     }
    // }
    
    void update(int i, int val){
        
        for(st[i+=n] = val; i > 0; i /= 2){
            st[i/2] = st[i] + st[i ^ 1];
        }
    }

    NumArray(vector<int> nums){
        data = nums;
        n = nums.size();
        st.resize(2*n, 0);
        for(int i = 0; i < n; i++){
            st[i+n] = nums[i];
        }
        for(int i = n - 1; i > 0; i--){
            st[i] = st[i*2] + st[i*2 + 1];
        }
    }
    
    int sumRange(int i, int j){
        int s = 0;
        for(i += n, j += n; i <= j; i /= 2, j /= 2){ //!!!
            if((i & 1) == 1){
                s += st[i];
                i++;
            }
            if((j & 1) == 0){
                s += st[j];
                j--;
            }
        }
        return s;
    }
};

