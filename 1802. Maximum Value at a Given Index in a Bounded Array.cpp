

// n = 4, idx = 2, maxSum = 6
// [3 4 5 4]
// [2 3 4 3]
// [1 2 3 2] -> 8
// [1 1 2 1] -> 5

//n = 6, index = 1,  maxSum = 10
// [x 10 x x x x]
// [8 9 x x x x]
// [7 8 x x x x]
// [4 5 4 x x x]
// [3 4 3 x x x]

// [2 3 2 1 1 1] -> 10

// 1 <= n <= maxSum <= 10e9 always has a solution


// 9 3 16

// [x x x 16 x x x x x]
// [1 2 3 4 x x x x x]

// 4 2 6
// [x x 4 x]

// sol1, my, binary search, O(maxSum), O(1)
// https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/discuss/1119801/JavaC%2B%2BPython-Binary-Search
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        
        int leftLen = index, rightLen = n - index - 1;
            
        int l = 1, r = maxSum;
        while(l < r){
            int mid = l + (r - l + 1) / 2;
            int leftH = mid - 1 == 0 ? 1 : mid-1, rightH = leftH;
            long long leftArea = getArea(leftLen, leftH);
            long long rightArea = getArea(rightLen, rightH);
            
            if(leftArea + rightArea + mid == maxSum){ // a good answer
                return mid;
            }
            if(leftArea+rightArea+mid < maxSum){  // a possible good answer
                l = mid;
            }
            else{ // a bad answer
                r = mid - 1;
            }
        }
        return l;
        
    }
    
    // case 1: 4 3 
    // case2: 4 3 2 1 1 
    // given a rectangle or trapzoid 
    long long getArea(int length, int height){
        if(length <= 0) return 0;
        long long area;
        if(length < height){ //  trapzoid
            long long shortHeight = height - length + 1;
            area = length * (shortHeight + height) / 2; // trapzoid, h/2 * (height + short)  
        }
        else{
            long long triangle = (long long)(height + 1) * height / 2; // also trapzoid, h/2 * (height + short)  
            area = triangle + (length - height);
        }
        return area;
    }
};
