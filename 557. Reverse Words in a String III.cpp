// O(n), O(1)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;
        while(j <= n){
            if(j == n || s[j] == ' '){
                reverseWord(s, i, j - 1);
                i = j + 1;
                j = i;
            }
            else{
                j++;
            }
        }
        return s;
        
    }
    void reverseWord(string& s, int left, int right){
        while(left < right){
            swap(s[left], s[right]);
            left++; right--;
        }
    }
};
