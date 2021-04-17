// !!! sol2, using buildin upper bound
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ub = upper_bound(letters.begin(), letters.end(), target);
        if(ub == letters.end()) return letters[0];
        return *ub;        
    }
};


// !!! sol1.1, new template
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n - 1;

        while(l < r - 1){
            int mid = l + (r - l) / 2;
            if(letters[mid] == target){
                l = mid;
            }
            else if(letters[mid] > target){
                r = mid;
            }
            else{
                l = mid;
            }
        }
        if(letters[l] > target) return letters[l];
        if(letters[r] > target) return letters[r];
        return letters[0];
    }
};

// sol1, my old version
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(letters[mid] > target){
                r = mid;
            }
            else if(letters[mid] == target){
                l = mid + 1;
            }
            else{
                l = mid + 1;
            }
        }
        if(l == n) return letters[0];
        return letters[l];        
    }
};


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
