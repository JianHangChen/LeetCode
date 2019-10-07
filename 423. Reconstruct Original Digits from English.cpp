// sol2, gy2, O(n)
class Solution {
public:
    string originalDigits(string s) {
        string res;
        unordered_map<char, int> m;
        vector<int> count(10,0);
        
        for(auto c:s) m[c]++;
        
        count[0] = m['z'];
        count[6] = m['x'];
        count[8] = m['g'];
        count[4] = m['u'];
        count[7] = m['s'] - count[6];
        count[5] = m['f'] - count[4];
        count[3] = m['r'] - count[0] - count[4];
        count[2] = m['t'] - count[3] - count[8];
        count[1] = m['o'] - count[0] - count[2] - count[4];
        count[9] = (m['n'] - count[1] - count[7]) / 2;

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < count[i]; j++){
                res += ('0' + i);
            }
        }
        
        return res;
    }
    

    
};


// // sol1, my after gy1, O(n)
// class Solution {
// private:

// public:
//     string originalDigits(string s) {
//         string res;
//         unordered_map<char, int> m;
//         vector<int> count(10,0);
        
//         for(auto c:s){
//             m[c]++;            
//         }

        
//         helpler('z', 0, "zero", m, count);
//         helpler('x', 6, "six", m, count);
//         helpler('g', 8, "eight", m, count);
//         helpler('u', 4, "four", m, count);
                
//         helpler('s', 7, "seven", m, count);
       
//         helpler('f', 5, "five", m, count);
//         helpler('r', 3, "three", m, count);
                
//         helpler('t', 2, "two", m, count);
//         helpler('o', 1, "one", m, count);
//         helpler('e', 9, "nine", m, count);
        
//         for(int i = 0; i < 10; i++){
//             for(int j = 0; j < count[i]; j++){
//                 res += to_string(i);
//             }
//         }
//         return res;
//     }
    
//     void helpler(char a, int num, string str, unordered_map<char, int>& m, vector<int>& count){
//         int t = m[a];
//         count[num] += t;
//         for(auto c:str){
//             m[c] -= t;
//         }        
//     }
    
// };
