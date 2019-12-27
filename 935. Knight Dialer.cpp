// sol1, my dp, O(N), O(1)
class Solution {
private:
    vector<vector<int>> neighbours = {{4,6}, {6,8},{7,9},{4,8},{3,9,0},{},{1,7,0},{2,6},{1,3},{2,4}};
public:
    int knightDialer(int N) {
        int res = 0, MOD = 1e9+7;
        vector<int> nums(10,1);
        for(int j = 1; j < N; j++){
            vector<int> temp(10,0);
            for(int i = 0; i < 10; i++){
                for(int nei:neighbours[i]){
                    temp[nei] = (temp[nei] + nums[i]) % MOD;
                }
            }
            nums = temp;
        }
        for(int i = 0; i < 10; i++){
            res = (res + nums[i]) % MOD;
        }
        return res;
    }
};
