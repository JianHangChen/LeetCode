 // !!! sol2, my dp, O(mn^2), O(mn)
// dp[i][j] the  largest sum among j subarray for [0, i-1]  // i not included
// dp[i][j-1] the largest sum among j-1 subarray for [0, i-1]
// dp[i-1][j] the min of largest sum among j subarray for [0, i-2]
// dp[i-1][j-1] the min of largest sum among j-1 subarray for [0, i-2]


// case 1: element i-1 is in a seperate group
// [7 2 | 5 10 ] -> [7 2 | 5 10 | 8]
// dp[i][j] [min=] max(dp[i-1][j-1], nums[i])


// case 2: element i is in the last group (with previous element) [7,2 | 5,| 10  8]


// // dp[i-1][j] the min largest sum among j subarray for [0, i-2]
// i-1 [7,2 | 5,| 10] -> i [7,2 | 5,| 10 8] not working


// // dp[i-k][j-1] the min largest sum among j-1 subarray for [0, i-k-1]
// i-k [7,2 | 5 ] -> i [7,2 | 5,| 10 8]   i-k, i-k+2, ..., i-1 are in one new group
// max(dp[i-k][j-1], nums[i-1] + nums[i-2]... + nums[i-k])  // k =0, 1, 2..., i-1


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, INT_MAX));
        vector<int> presum(n+1, 0);
        for(int i = 0; i < n; i++) presum[i+1] = presum[i] + nums[i]; // presum[i]   [0, i-1]

        dp[0][0] = 0;
// // base case:
//     dp[0][0] = 0,  dp[0][1] = INT_MAX, ...
//     dp[1][0] = INT_MAX, dp[1][1] = nums[0], dp[1][2] = INT_MAX...
//     dp[2][0] = INT_MAX, dp[2][1] = nums[0] + nums[1], dp[2][2] = max(nums[0], nums[1]) = max(dp[1][1], nums[1])
//                         dp[3][1] = nums[0] + ... nums[2], ...

// max(dp[i-k][j-1], nums[i-1] + nums[i-1] + nums[i-2]... + nums[i-k])  // k =0, 1, 2..., i
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int k = 1; k <= i; k++){
                    dp[i][j] = min(dp[i][j], max(dp[i-k][j-1], presum[i] - presum[i-k]) );                
                }
            }
        }
        return dp[n][m];
    }
};


//!!! sol1, binary search, O(log(sum - max)), O(1)
// https://www.youtube.com/watch?v=Ksmmhee4lYE
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int maxi = 0, sum = 0;
        for(int i = 0; i < n; i++){
            maxi = max(maxi, nums[i]);
            sum += nums[i];
        }
        int l = maxi, r = sum;
        
        while(l < r){
            int mid = l + (r - l) / 2;
            int splits = getSplits(nums, mid);
            if(splits > m){ // cannot  split
                l = mid + 1;
            }
            else{ // can split
                r = mid;
            }
        }
        return l;     
    }
    int getSplits(vector<int>& nums, int upperbound){
        int splits = 1;
        int cumsum = 0;
        for(int i = 0; i < nums.size(); i++){
            cumsum += nums[i];
            if(cumsum > upperbound){
                splits++;
                cumsum = nums[i];
            }
        }
        return splits;
    }
};




 
 #binary search 

def splitArray(self, nums: List[int], m: int) -> int:
    def issplit(mid, m): # return if the nums can be split into m pieces where sum(piece) <= mid for every piece
        count = 0
        cur_sum = 0
        for i in range(len(nums)):

            cur_sum += nums[i]
            if cur_sum > mid:
                cur_sum = nums[i]
                count += 1

                if count == m:
                    return False


        return True




    l = max(nums)
    r = sum(nums)

    while l < r:
        mid = l + (r - l) // 2
        if issplit(mid, m):
            r = mid
        else:
            l = mid + 1

    return l
