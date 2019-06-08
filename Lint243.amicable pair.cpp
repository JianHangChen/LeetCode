
https://www.jiuzhang.com/solution/amicable-pair/#tag-highlight-lang-cpp
class Solution {
public:
    /**
     * @param k an integer
     * @return all amicable pairs
     */
    vector<vector<int>> amicablePair(int k) {
        vector<vector<int>> res;
        vector<int> pair;
        for(int i = 1; i <= k ; i++ ){
            int j = 0;
            int factor = 1;
            while(factor < i){
                if(i % factor == 0){
                    j += factor;
                    if(j > k){
                        break;
                    }
                }
                factor++;
            }
            if(factor == i){
                res.push_back({i, j});
            }
        }
        return res;
        
    }
};
