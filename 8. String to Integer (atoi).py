

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


