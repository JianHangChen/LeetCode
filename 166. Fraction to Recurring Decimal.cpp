// sol2, modified from sol
//https://www.leetfree.com/problems/fraction-to-recurring-decimal.html?tab=solution

class Solution {
public:
    string fractionToDecimal(int num, int den) {
        string res;
        if(num == 0) return "0"; //!corner case;
        if(num < 0 ^ den < 0) res += "-";

        long long numerator = abs((long long) num), denominator = abs((long long) den);// !overflow

        long long integer = numerator / denominator;
        long long remain = numerator % denominator;
        res += to_string(integer);
        if(remain == 0) return res;
        
        res += ".";
        unordered_map<long long,int> m_remain;
        while(remain > 0){
            if(m_remain.count(remain) > 0){ // repeat
                res.insert(m_remain[remain],"(");
                res += ")";
                break;
            }
            m_remain[remain] = res.size();
            
            remain *= 10;

            res += to_string(remain / denominator);
            remain %= denominator;
        }
        
        return res;
    }
};

// class Solution {
// public:
//     string fractionToDecimal(int num, int den) {
//         string res;
//         if(num == 0) return "0"; //!corner case;
//         if(num < 0 ^ den < 0) res += "-";

//         long long numerator = abs((long long) num), denominator = abs((long long) den);// !overflow
        
//         bool repeat = false;
//         vector<int> floating;
//         unordered_map<long long,int> m_remain;
        
//         long long integer = numerator / denominator;
//         long long remain = numerator % denominator;
//         res += to_string(integer);
//         if(remain == 0) return res;
        
//         int index = 0;

//         while(remain > 0){
            
//             if(m_remain.count(remain) > 0){ // repeat
//                 repeat = true;
//                 break;
//             }
//             m_remain[remain] = index++;
//             remain *= 10;
            
//             if(remain / denominator == 0){
//                 floating.push_back(0);
//             }
//             else{
//                 int digit = remain / denominator;
//                 remain %= denominator;
//                 floating.push_back(digit);
//             }

//         }
        
//         res += ".";
//         if(repeat){
//             index = m_remain[remain];
//             for(int i = 0; i < index; i++){
//                 res += to_string(floating[i]);
//             }
//             res += "(";
//             for(int i = index; i < floating.size(); i++){
//                 res += to_string(floating[i]);
//             }
//             res += ")";
//         }
//         else{
//             for(int i = 0; i < floating.size(); i++){
//                 res += to_string(floating[i]);
//             }
//         }
//         return res;
//     }
// };
