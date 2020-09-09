
We will consider two strings close if one can be obtained from the other, using the following operations:

swap any two symbols in one of the strings,
swap occurrences of any two existing symbols in one of the strings (for example, if your string contains both as and bs, you can change all as to bs and all the bs to as).
Now you want to write a method that finds out whether the given strings are considered close, by the definition above.

Example

For A = "abbzccc" and B = "babzzcz", the output should be
closeNames(A, B) = true.

One possible way to transform "abbzccc" to "babzzcz" is this:

"abbzccc" (this string is className)
"babzccc" (swap positions of the first two characters)
"babczzz" (switch all c and z characters)
"babzzcz" (swap positions of the characters at indices 3 and 5; this string is now methodName)

For A = "abcbdb" and B = "bbbcca", the output should be closeNames(A, B) = false.


// https://leetcode.com/discuss/interview-question/506181/postmates-oa-2020-close-strings


class Sol{
public:
    bool exist(string s, string t){
        if(s.size() != t.size()) return false;
        unordered_map<char, int> ms, mt;
        for(char c:s) ms[c]++;
        for(char c:t) mt[c]++;
        for(auto& item:ms){
            char c = item.first;
            int count = item.second;
            
            int match = false;
            for(auto& it:mt){
                if(it.second == count){
                    it.second = -1;
                    match = true;
                    break;
                }
            }
            if(!match) return false;
        }
        return true;        
    }
};

int main() {
    Sol sol;
    
//     pp closeNames("abbzccc", "babzzcz") # true
// pp closeNames("abbbzcc", "babzzcz") # true
// pp closeNames("abbbzcf", "babzzcz") # false
// pp closeNames("abbzzca", "babzzcz") # false
    string A = "abbzzca", B = "babzzcz";
    cout << sol.exist(A, B) << endl;
    
}
