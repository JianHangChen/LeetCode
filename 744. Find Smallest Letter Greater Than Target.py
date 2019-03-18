class Solution:
    
 # sol1, my O(logN) O(1)
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        
        low = 0; high = n
        
        while low < high:
            mid = low + (high - low) // 2
            
            if ord(letters[mid]) > ord(target):
                high = mid
            else:
                low = mid + 1
        return letters[high%n]

#  sol2, from sol3, the same, using built in library
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        index = bisect.bisect(letters, target)
        return letters[index%len(letters)]
