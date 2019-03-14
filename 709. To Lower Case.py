class Solution:
    def toLowerCase(self, str: str) -> str:
        # my sol1
        return str.lower()
    
        # my sol2
        ans = []
        for i in str:
            if ord('A') <= ord(i) < ord('a'):
                ans.append( chr(ord(i) - ord('Z') + ord('z') ) ) #32
            else:
                ans.append(i)
        
        return ''.join(ans)
