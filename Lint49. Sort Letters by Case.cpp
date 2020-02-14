
// sol1, my, O(n), O(1)
class Solution {
public:
    /*
     * @param chars: The letter array you should sort by Case
     * @return: nothing
     */
     
     // AbccD
    void sortLetters(string &chars) {
        int n = chars.size();
        int i = 0, j = n - 1;
        while(i < j){
            if('A' <= chars[i] && chars[i] <= 'Z' && 'a' <= chars[j] && chars[j] <= 'z'){
                swap(chars[i++], chars[j--]);
            }
            else if('a' <= chars[i] && chars[i] <= 'z'){
                i++;
            }
            else{
                j--;
            }
        }
    }
};
