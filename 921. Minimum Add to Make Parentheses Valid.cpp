// my, sol1, O(n), O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        int i = 0;
        int countLeft = 0, res = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                countLeft++;
            }
            else{
                if(countLeft > 0){
                    countLeft--;
                }
                else{
                    res++;
                }
            }
        }
        return res + countLeft;
    }
};
