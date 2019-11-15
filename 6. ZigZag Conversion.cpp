// !sol2.1, from sol2, better than me.

class Solution{
    public:
    string convert(string s, int numRows){
        if(numRows <= 1) return s;
        string res; int cyclen = 2 * (numRows - 1);
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j + i < s.size(); j += cyclen){
                res += s[j + i];
                if(i != 0 && i != numRows - 1 && j - i + cyclen < s.size()){
                    res += s[j - i + cyclen];
                }
            }
        }
        return res;
    }
};

// sol2, my, O(n), O(1), find math

// class Solution{
// public:
//     string convert(string s, int numRows){
//         if(numRows <= 1) return s;
//         string res; int idx = 0; int k = 0;
//         while(true){
//             idx = k * 2 * (numRows - 1);
//             if(idx >= s.size()) break;
//             res += s[idx]; k++;
//         }
        
//         for(int i = 1; i < numRows - 1; i++){
//             k = 0;    
//             while(true){
//                 idx = k * 2 * (numRows - 1) + i;
//                 if(idx >= s.size()) break;
//                 res += s[idx];
//                 idx = (k + 1) * 2 * (numRows - 1) - i;
//                 if(idx >= s.size()) break;
//                 res += s[idx]; k++;
//             }
//         }
//         k = 0;
//         while(true){
//             idx = k * 2 * (numRows - 1) + (numRows - 1);
//             if(idx >= s.size()) break;
//             res += s[idx]; k++;
//         }
//         return res;
//     }  
// };


// !!!!sol1.1, from sol1, improved by my sol1, use string to store each row, O(n), O(n)
class Solution{
public:
    string convert(string s, int numRows){
        if(numRows <= 1) return s;
        vector<string> m(numRows);
        bool isDown = true;
        int curRow = 0;
        for(auto c:s){
            m[curRow] += c;
            curRow += isDown ? 1 : -1;
            if(curRow == 0 || curRow == numRows - 1) isDown = !isDown;
        }
        
        string res;
        for(auto row:m) res += row;
        return res;
    }
};

// sol1, my boring solution. use a 2d array to store the zigzag matrix, the space will become O(mn)
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if(numRows <= 1) return s;
        
//         int numCols = s.size();
//         vector<vector<char>> m(numRows, vector<char>(numCols,'0'));
//         string res;
//         bool isDown = true;
        
//         int i = 0, j = 0;
//         for(int k = 0; k <numCols; k++){
//             m[i][j] = s[k];
            
//             if(isDown){
//                 if(i == numRows - 1){
//                     i--; j++;
//                     isDown = false;                
//                 }
//                 else{
//                     i++;
//                 }
//             }
//             else{//up
//                 if(i == 0){
//                     i++;
//                     isDown = true;
//                 }
//                 else{
//                     i--; j++;
//                 }
//             }
//         }
        
//         for(int i = 0; i < numRows; i++){
//             for(int j = 0; j < numCols; j++){
//                 if(m[i][j] != '0') res += m[i][j];
//             }
//         }
        
//         return res;
        
//     }
// };
