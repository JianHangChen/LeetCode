// !!! only use int
class Solution{
public:
    int myAtoi(string s){
        int n = s.size(), i = 0, res = 0;
        bool isPositive = true;
        if(n == 0) return 0;
        while(i < n && s[i] == ' ') i++;
        if(i == n) return 0;
        
        if(s[i] == '+'){
            i++;
        }
        else if(s[i] == '-'){
            isPositive = false;
            i++;
        }
        
        while(i < n && isdigit(s[i])){
            if(isPositive){
                if(res > INT_MAX / 10 || res == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10 ){
                    return INT_MAX;
                }
                res = res * 10 + (s[i] - '0');
            }
            else{
                if(res < INT_MIN / 10 || res == INT_MIN / 10 && s[i] - '0' > INT_MAX % 10 + 1){
                    return INT_MIN;
                }
                res = res * 10 - (s[i] - '0');
            }
            i++;
        }
        return res;
        
    }
};



// my use long long
// class Solution {
// public:
//     int myAtoi(string s) {
//         int n = s.size(), i = 0, sign = 1;
//         if(n == 0) return 0;
//         while(i < n && s[i] == ' ') i++;
//         if(i == n) return 0;
        
//         if(s[i] == '+'){
//             i++;
//         }
//         else if(s[i] == '-'){
//             sign = -1;
//             i++;
//         }
//         long long res = 0;
//         while(i < n && isdigit(s[i])){
//             res = res * 10 + (s[i] - '0');
//             i++;
//             if(res > INT_MAX) break;
//         }
//         res = res * sign;
//         if(res > INT_MAX ) return INT_MAX;
//         if(res < INT_MIN ) return INT_MIN;
        
//         return res;
        
//     }
// };

class Solution {
public:
    int myAtoi(string str) {
        
        int res = 0;
        
        int i = str.find_first_not_of(' ');
        if (i >= str.size()){
            return res;
        }
                
        bool negative = false;

        if (str[i] == '+'){
            i++;
        }
        else if (str[i] == '-'){
            negative = true;
            i++;
        }
        else if (isdigit(str[i])){
           ;
        }
        else{
            return res;
        }

        if (!isdigit(str[i])){return res;}

        while(i < str.size() && isdigit(str[i])){
            int digit = (str[i] - '0');

            if (negative){
                if (res < INT_MIN / 10 || res == INT_MIN / 10 && digit > 8){
                    return INT_MIN;
                }
                res = res * 10 - digit;
            }
            else{
                if (res > INT_MAX / 10 || res == INT_MAX / 10 && digit > 7){
                    return INT_MAX;
                }
                res = res * 10 + digit;
            }

            i++;
        }
        return res;
    }
        
};


