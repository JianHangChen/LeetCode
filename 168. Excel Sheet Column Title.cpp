class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        int mod = 26;
        while(n > 0){
            ans.push_back('A' + (n - 1) % mod);
            n = (n-1) / mod;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        # sol1
        # res = []
        # capitals = [chr(i) for i in range(ord('A'), ord('Z')+1)]
        # while n > 0:
        #     re = (n)%26
        #     res.append(capitals[re-1])
        #     n = (n-1)//26
        # res.reverse()
        # return ''.join(res)
        
        
        # sol2, oneline
        # https://leetcode.com/problems/excel-sheet-column-title/discuss/51398/My-1-lines-code-in-Java-C%2B%2B-and-Python
        
        return "" if n == 0 else self.convertToTitle((n-1)//26) + chr( (n-1)%26 + ord('A'))
