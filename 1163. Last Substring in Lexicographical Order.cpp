
//!!! sol1, O(n), O(1)
// from https://leetcode.com/problems/last-substring-in-lexicographical-order/discuss/582703/C%2B%2B-SIMPLE-EASY-SOLUTION-WITH-EXPLANATION-CHEERS!!!
class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, k = 0;
        while(j + k < s.size()){
            if(s[i+k] == s[j+k]) k++;
            else if(s[i+k] > s[j+k]){
                j = j + k + 1;
                k = 0;
            }
            else{
                i = j++;
                k = 0;
            }
        }
        return s.substr(i);
    }
};


// explanation:
// // We use "j" to find a better starting index. If any is found, we use it to update "i"

// // 1."i" is the starting index of the first substring
// // 2."j" is the staring index of the second substring
// // 3."k" is related to substring.length() (eg. "k" is substring.length()-1)

// // Case 1 (s[i+k]==s[j+k]):
// // -> If s.substr(i,k+1)==s.substr(j,k+1), we keep increasing k.
// // Case 2 (s[i+k]<s[j+k]):
// // -> If the second substring is larger, we update i with j. (The final answer is s.substr(i))
// // Case 3 (s[i+k]>s[j+k]):
// // -> If the second substring is smaller, we just change the starting index of the second string to j+k+1.
//     //Because s[j]~s[j+k] must be less than s[i], otherwise "i" will be updated by "j". So the next possible candidate is "j+k+1".

