
#没什么意思的题目
class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """       

        # # sol1: my O(n*h)
        if needle == "":
            return 0
        hay_len = len(haystack)
        n_len = len(needle)
        for i in range(hay_len):
            for j in range(n_len):
                if i + j >= hay_len:
                    return -1
                if haystack[i+j] != needle[j]:
                    break
                if j == n_len-1:
                    return i
        return -1
        
        # sol2: using string list implementation, elegant. still O(n*h)
        
        for i in range(len(haystack)-len(needle)+1):
            if haystack[i:i+len(needle)] == needle:
                return i
        return -1
