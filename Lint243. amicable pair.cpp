
https://www.jiuzhang.com/solution/amicable-pair/#tag-highlight-lang-cpp
// C++ code to demonstrate 2D vector 
#include <iostream> 
#include <vector> // for 2D vector 
using namespace std; 

class Solution {
public:
    /**
     * @param k an integer
     * @return all amicable pairs
     */
    vector<vector<int>> amicablePair(int k) {
        vector<vector<int>> res;
        for(int i = 1; i <= k ; i++ ){
            int j = factorsum(i);
            
            if(j > k || j <= i){
                continue;
            }
            
            if(factorsum(j) == i){
                res.push_back({i, j});
            }
        }
        return res;
        
    }
    
    int factorsum(int i){
        int s = 1;
        int factor = 2;
        while(factor * factor < i){
            if(i % factor == 0){
                s += factor + i / factor;
            }
            factor++;
        }
        if(factor * factor == i){
            s += factor;
        }
        return s;
    }
};

int main() 
{ 
    Solution s;
    vector<vector<int>> pairs = s.amicablePair(284);
    
    for(auto pair: pairs){
        cout << pair[0] << "," << pair[1] << endl;
    }
	return 0; 
} 
