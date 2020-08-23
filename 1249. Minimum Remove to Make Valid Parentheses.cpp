class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string temp, res;
        int left = 0, right = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') left++;
            else if(s[i] == ')') right++;
            if(left < right){
                right--;
                continue;
            }
            else{
                temp.push_back(s[i]);
            }
        }
        left = 0; right = 0;
        for(int i = temp.size() - 1; i >= 0; i--){
            if(temp[i] == '(') left++;
            else if(temp[i] == ')') right++;
            if(left > right){
                left--;
                continue;
            }
            else{
                res.push_back(temp[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
