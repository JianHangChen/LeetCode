
// sol2, from gy2, memo
class Solution {
private:
    unordered_map<string, vector<int>> m;
public:
    vector<int> diffWaysToCompute(string input) {
        if(m.count(input) > 0) return m[input]; 
        vector<int> res, left, right;
        for(int i = 0; i < input.size(); i++){
            if(input[i] == '-' || input[i] == '*' || input[i] == '+'){
                left = diffWaysToCompute( input.substr(0, i) );
                right = diffWaysToCompute( input.substr(i+1, input.size() - i - 1) );
                for(auto l:left){
                    for(auto r:right){
                        if(input[i] == '-') res.push_back(l - r);
                        else if(input[i] == '+') res.push_back(l+r);
                        else if(input[i] == '*') res.push_back(l*r);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(input));
        m[input] = res;
        return res;        
    }
};


// sol1, from gy
// class Solution {
// public:
//     vector<int> diffWaysToCompute(string input) {
//         vector<int> res, left, right;
//         for(int i = 0; i < input.size(); i++){
//             if(input[i] == '-' || input[i] == '*' || input[i] == '+'){
//                 left = diffWaysToCompute( input.substr(0, i) );
//                 right = diffWaysToCompute( input.substr(i+1, input.size() - i - 1) );
//                 for(auto l:left){
//                     for(auto r:right){
//                         if(input[i] == '-') res.push_back(l - r);
//                         else if(input[i] == '+') res.push_back(l+r);
//                         else if(input[i] == '*') res.push_back(l*r);
//                     }
//                 }
//             }
//         }
//         if(res.empty()) res.push_back(stoi(input));
//         return res;        
//     }
// };
