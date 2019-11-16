//sol1.1 my, improved from sol1

class Solution{
public:
    vector<string> ambiguousCoordinates(string S){
        vector<string> res;
        S = S.substr(1, S.size() - 2); int n = S.size();
        for(int i = 1; i < n; i++){
            string str1 = S.substr(0, i), str2 = S.substr(i, n - i);
            vector<string> l1 = getValid(str1), l2 = getValid(str2);
            for(auto& ele1:l1){
                for(auto& ele2:l2){
                    res.push_back("(" + ele1 + ", " + ele2 + ")");
                }
            }
        }
        return res;
    }
    vector<string> getValid(string& s){
        vector<string> res; int n = s.size();
        for(int i = 1; i <= n; i++){
            string left = s.substr(0, i), right = s.substr(i, n - i);
            if( (left.front() != '0' || left == "0") && right.back() != '0'){
                res.push_back(left + (i == n ? "" : ".") + right);
            }
        }
        return res;
    }
};


// sol1, my, O(n^3), O(n^3)
// class Solution {
// public:
//     vector<string> ambiguousCoordinates(string S) {
//         vector<string> res;
//         S = S.substr(1,S.size() - 2);
//         // cout << S << endl;
//         int n = S.size();
        
//         for(int i  = 1; i < n; i++){
//             string str1 = S.substr(0, i); 
//             string str2 = S.substr(i, n - i);
//             vector<string> l1 = getValid(str1), l2 = getValid(str2);
//             for(auto ele1:l1){
//                 for(auto ele2:l2){
//                     res.push_back("(" + ele1 + ", " + ele2 + ")");
//                 }
//             }
//         }
       

//         return res;
//     }
//     vector<string> getValid(string s){
//         vector<string> res;
//         int n = s.size();
//         if(n == 0){return res;}
//         if(n == 1){res.push_back(s); return res;}
//         if(s[0] != '0'){res.push_back(s);}
        
//         for(int i = 1; i < n; i++){
//             string str1 = s.substr(0, i); int n1 = str1.size();
//             if(n1 == 0) continue;
//             if(n1 > 1 && str1[0] == '0') continue; 
//             string str2 = s.substr(i, n - i); int n2 = str2.size();
//             if(n2 == 0) continue;
//             if(str2[n2 - 1] == '0') continue;
//             res.push_back( str1 + "." + str2);
//         }
//         return res;
//     }
    
// };
