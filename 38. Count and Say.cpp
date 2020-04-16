// sol1, analysis from sol1, O(2^n) = O(sum(2^0 + 2^1 + 2^2 + ... + 2^(n-1) ))
// every time, the length is doubled in the worst case, there are n-1 iteration
// O(2^(n-1)) space

class Solution {
public:
    string countAndSay(int n) {
        string s1 = "1", s2;
        while(n > 1){
            s2 = next(s1);
            s1 = s2;
            n--;
        }
        return s1;
        
    }
    
    string next(string& s1){
        string s2;
        int count = 1;
        for(int i = 0; i < s1.size(); i++){
            if(i + 1 >= s1.size() || s1[i] != s1[i+1]){
                s2 = s2 + to_string(count) + s1[i];
                count = 1;
            }
            else{
                count++;
            }
            
        }
        return s2;
        
    }
};


// class Solution:
//     def countAndSay(self, n):
//         """
//         :type n: int
//         :rtype: str
//         """
//         if n == 1:
//             return "1"
//         else:
//             final_say = ""
//             pre_say = self.countAndSay(n-1)
//             length = len(pre_say)
//             repeat = pre_say[0]
//             count = 1
//             i = 1
//             while(i < length):
//                 if pre_say[i] == repeat:
//                     count += 1
//                 else:
//                     final_say += ( str(count) + str(repeat) )
//                     count = 1
//                     repeat = pre_say[i]
//                 i += 1
//             final_say += ( str(count) + str(repeat) )
//         return final_say
