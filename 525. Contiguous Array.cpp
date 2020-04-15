// !!! sol2, use accumulate count
// when the count is the same as previous i step, means from i + 1 to j, the sum is 0 
// from gy1 and sol3, O(n), O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 0, count = 0;
        unordered_map<int, int> m({{0,-1}});
        for(int i = 0; i < n; i++){
            if(nums[i] == 1) count++;
            else count--;
            if( m.count(count) > 0 ){
                res = max(res, i - m[count]);
            }
            else{
                m[count] = i;
            }
        }
        return res;        
    }
};


// my sol1, O(n^2), O(n)
// class Solution {
// public:
//     int findMaxLength(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> count0(n+1, 0), count1(n+1, 0);
//         for(int i = 1; i <= n; i++){
//             count0[i] = count0[i-1];
//             count1[i] = count1[i-1];
//             if(nums[i-1] == 0) count0[i]++;
//             else count1[i]++;  
//         }
//         int maxlen = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < n; j++){
//                 if(count1[j+1] - count1[i] == count0[j+1] - count0[i]){
//                     maxlen = max(2 * (count1[j+1] - count1[i]), maxlen);                
//                 }
//             }
//         }
//         return maxlen;
        
//     }
// };
