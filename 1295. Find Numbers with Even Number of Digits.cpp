class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto num:nums){
            int digit = get_digit(num);
            if(digit % 2 == 0) res++;
        }
        return res;
    }
    int get_digit(int num){
        int d = 0;
        while(num){
            d++;
            num /= 10;
        }
        return d;
        
    }
};
