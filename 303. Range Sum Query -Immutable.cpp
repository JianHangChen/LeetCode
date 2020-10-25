

// !!! sol3,  from sol3, O(1), O(n)
class NumArray {
private:
    vector<int> pre;
    
public:
    NumArray(vector<int>& nums) { // O(n)
        pre.push_back(0);
        for(int num:nums){
            pre.push_back(pre.back() + num);
        }
    }
    
    int sumRange(int i, int j) {
        return pre[j+1] - pre[i];
    }
};


// sol1, my, O(n) for each new query, O(1) for existing query
// class NumArray {
// public:
//     vector<int> nums;
//     unordered_map<string, int> table;
//     NumArray(vector<int>& nums) {
//         this->nums = nums;
//     }
    
//     int sumRange(int i, int j) {
//         string s = to_string(i)+to_string(j);
//         if(table.find(s) == table.end()){
//             int res = 0;
//             while(i<=j){
//                 res += nums[i];
//                 i++;
//             }
//             table[s] = res;
//             return res;
//         }
//         return table[s];
//     }
// };


// sol2, bad idea from sol1, O(n^2), O(n^2) for precomputation
// class NumArray {
// public:
//     vector<int> nums;
//     unordered_map<string, int> table;
    
//     NumArray(vector<int>& nums) {
//         this->nums = nums;
//         int n = nums.size();
//         for(int i = 0; i < n; i++){
//             int s = 0;
//             for(int j = i; j < n; j++){
//                 s += nums[j];
//                 string pos = to_string(i) + to_string(j);
//                 table[pos] = s;
//             }
//         }
        
//     }
    
//     int sumRange(int i, int j) {
//         string pos = to_string(i) + to_string(j);
//         return table[pos];
//     }
// };


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
