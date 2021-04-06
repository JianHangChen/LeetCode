class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    TreeNode* build(vector<int>& nums, int i, int j){
        if(i > j) return NULL;
        int mid = i + (j - i) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        if(i == j) return cur;
        cur->left = build(nums, i, mid-1);
        cur->right = build(nums, mid + 1, j);
        return cur;
    }
};
