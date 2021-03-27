/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

//!!! sol2,from sol3, O(m+n), O(1)
class Solution {
public:
    int m , n;
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        m = dims[0]; n = dims[1];
        int i = 0, j = n - 1;
        int res = n;
        while(i < m && j >= 0){
            if(binaryMatrix.get(i, j) == 1){
                res = min(res, j);
                j--;
            }
            else{
                i++;
            }
        }
        if(res == n) return -1;
        return res;
    }
};

// !!! sol1.1, optimized sol1, O(mlogn),O(1)
class Solution {
public:
    int m , n;
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        m = dims[0]; n = dims[1];
        
        int ans = n;
        for(int i = 0; i < m; i++){
            ans = min(ans, getFirstIdx(binaryMatrix, i, ans-1));
        }
        if(ans < n) return ans;
        return -1;
    }
    int getFirstIdx(BinaryMatrix &binaryMatrix, int row, int colend){
        int i = 0, j = colend;
        while(i <= j){
            if(i == j && binaryMatrix.get(row, i) == 1) return i;
            
            int mid = i + (j - i) / 2;
            if(binaryMatrix.get(row, mid) == 1){
                j = mid;
            }
            else{
                i = mid + 1;
            }
        }
        return n;
    }
    
    
    
};


!! sol1, my O(mlogn), O(1), same as sol2
class Solution {
public:
    int m , n;
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        m = dims[0]; n = dims[1];
        
        int ans = n;
        for(int i = 0; i < m; i++){
            ans = min(ans, getFirstIdx(binaryMatrix, i));
        }
        if(ans < n) return ans;
        return -1;
    }
    int getFirstIdx(BinaryMatrix &binaryMatrix, int row){
        int i = 0, j = n - 1;
        while(i <= j){
            if(i == j && binaryMatrix.get(row, i) == 1) return i;
            
            int mid = i + (j - i) / 2;
            if(binaryMatrix.get(row, mid) == 1){
                j = mid;
            }
            else{
                i = mid + 1;
            }
        }
        return n;
    }
    
    
    
};

