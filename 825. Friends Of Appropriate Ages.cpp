// !!!sol2, from gy2, O(n), O(120)

class Solution{
public:
    int numFriendRequests(vector<int>& ages){
        vector<int> count(121,0), presum = count;
        for(int age:ages) count[age]++;
        for(int i = 1; i <= 120; i++) presum[i] = presum[i-1] + count[i];
        int res = 0;
        for(int i = 1; i <= 120; i++){
            int min_idx = 0.5 * i + 7; //120 67, 119 66.5 118  65, 18 16, 17 15.5, 16 15,  15 14.5, 14 14, 13 13.5
            if(min_idx < i) res += count[i] * (presum[i] - presum[min_idx] - 1);
        }
        return res;
    }
};





// // my sol1, TLE, O(n^2) in worst case
// class Solution {
// public:
//     int numFriendRequests(vector<int>& ages) {
//         int res = 0;
//         sort(ages.begin(), ages.end());
//         for(int i = ages.size() - 1; i > 0; i--){
//             for(int j = i - 1; j >= 0; j--){
//                 if(ages[j] <= ages[i] * 0.5 + 7) break;
//                 else{
//                     if(ages[j]==ages[i]) res++;
//                     res++;                
//                 }
//             }
//         }
//         return res;
        
//     }
// };

