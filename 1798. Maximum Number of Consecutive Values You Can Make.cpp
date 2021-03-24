// [1,1,1,4]
// we know we can make 0, ..., res - 1 from coins[0] to coins[t]
// check res
// if(coins[t+1] > res) cannot make res
// if(coins[t+1] <= res) make from coins[t+1], ..., res - 1 + coins[t+1], so we can make 0, ..., res-1 + coins[t+1]
// check res + coins[t+1]

//!!! sol2, O(nlogn), O(1)
// https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/discuss/1118770/JavaC%2B%2BPython-Accumulate-the-Coins
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int res = 1; // we can make 0, ..., res - 1
        for(int i = 0; i < n; i++){
            if(coins[i] > res) break;
            res += coins[i];
        }
        return res;        
    }
};

// sol1, my, tle, O(2^n), O(2^n)
// class Solution {
// public:
//     int getMaximumConsecutive(vector<int>& coins) {
//         int n = coins.size();
//         unordered_set<int> s, tmp;
//         s.insert(0);
        
//         for(int i = 0; i < n; i++){
//             for(auto num:s){
//                 tmp.insert(num+coins[i]);
//             }
//             for(auto num:tmp) s.insert(num);
//         }
//         int i = 0;
//         while(true){
//             if(s.count(i) > 0) i++;
//             else break;
//         }
//         return i;
//     }
// };
