class Solution:
    # sol1
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        def reverse(i,j):
            if i >= j:
                return
            
            reverse(i+1,j-1)
            s[i], s[j] = s[j], s[i]
            
        reverse(0, len(s)-1)
        
        # sol2
        # s.reverse() # but we cannot use this
