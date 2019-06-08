
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


// class Solution {
// public:
//     /**
//      * @param k an integer
//      * @return all amicable pairs
//      */
//     vector<vector<int>> amicablePair(int k) {
//         vector<vector<int>> result;
//         for (int i = 1; i <= k; i++) {
//             int amicable = factorSum(i);
//             if (amicable <= i || amicable > k) {
//                 continue;
//             }
//             if (factorSum(amicable) == i) {
//                 vector<int> pair;
//                 pair.push_back(i);
//                 pair.push_back(amicable);
//                 result.push_back(pair);
//             }
//         }
        
//         return result;
//     }
    
//     int factorSum(int n) {
//         int i, sum = 1;
//         for (i = 2; i * i < n; i++) {
//             if (n % i == 0) {
//                 sum += i + n / i;
//             }
//         }
//         if (i * i == n) {
//             sum += i;
//         }
//         return sum;
//     }
// };
int main() 
{ 
    Solution s;
    vector<vector<int>> pairs = s.amicablePair(284);
    
    for(auto pair: pairs){
        cout << pair[0] << "," << pair[1] << endl;
    }
	return 0; 
} 
