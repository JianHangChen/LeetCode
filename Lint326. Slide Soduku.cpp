class Solution {
public:

    vector<bool> SlidingWindows(vector<vector<int>> &number) {
        int n = number[0].size();
        vector<bool> res(n-2, true);
        vector<int> count(10, 0);
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                count[number[i][j]]++;
            }
        }
        res[0] = check(count);
        
        for(int i = 1; i + 2 < n; i++){
            for(int j = 0; j < 3; j++){
                count[number[j][i+2]]++;
                count[number[j][i-1]]--;
            }
            res[i] = check(count);
        }
        return res;
    }
    bool check(vector<int>& count){
        for(int i = 1; i < count.size(); i++){
            if(count[i] != 1) return false;
        }
        return true;
        
    }
};


// [1,2,3,2,5,7],
// [4,5,6,1,7,6],
// [7,8,9,4,8,3]
