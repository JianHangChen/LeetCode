


// !!!sol1, O(log(n-k) + K), O(k)

// https://leetcode.com/problems/find-k-closest-elements/discuss/106426/JavaC%2B%2BPython-Binary-Search-O(log(N-K)-%2B-K)


// Note that, you SHOULD NOT compare the absolute value of abs(x - A[mid]) and abs(A[mid + k] - x).
// It fails at cases like A = [1,1,2,2,2,2,2,3,3], x = 3, k = 3


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low = 0, high = arr.size() - k;
        while(low < high){
            int mid = low + (high - low) / 2;

            if( x - arr[mid] > arr[mid + k] - x ){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        vector<int> res(arr.begin() + low, arr.begin() + low + k);
        
        return res;
        
    }
};


class Solution:
    
    # test: 1. []. no such one
    # 2. [1, 2] k=1, x = 3
    # 3. [1, 2, 6] k = 3  x = 2
    # 4. [1, 2] k=1, x = 1
    # 5. [1, 2] k = 1, x = 2
    
    # sol1,  binary search, from sol2, O(log(n)+k), O(k)
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        # if x <= arr[0]:
        #     return arr[0:k]
        # if x >= arr[-1]:
        #     return arr[-k:]
        
        # perform binary search to find element == x or nearest element > x
        low = 0
        high = len(arr)
        
        while low < high:
            mid = low + (high - low) // 2
            if arr[mid] >= x:
                high = mid
            else:
                low = mid + 1
        idx = low #idx of element == x or nearest element > x
        
        # strech out from idx to idx - (k - 1) and idx + (k - 1)
        
        left = max(0, idx - k)
        right = min( idx + (k - 1), len(arr) - 1)

        
        while right - left + 1 != k:
            if arr[right] - x >= x - arr[left]:
                right -= 1
            else:
                left += 1
        return arr[left: right+1]
                
    # sol2, excellent solution O(log(n-k)), O(k) space for return list
    # from https://leetcode.com/problems/find-k-closest-elements/discuss/106419/O(log-n)-Java-1-line-O(log(n)-%2B-k)-Ruby
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        low = 0
        high = len(arr) - k
        
        while low < high:
            mid = low + (high-low)//2
            if arr[mid+k] - x < x - arr[mid]:
                low = mid + 1
            else:
                high = mid
        return arr[low:low+k]
        
