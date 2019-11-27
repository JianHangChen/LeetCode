//sol4, !!!! gy2, dp, up and down, O(n), O(1)
class Solution{
public:
    int longestMountain(vector<int>& A){
        int n = A.size(), ans = 0;
        int up = 0, down = 0;
        for(int i = 1; i < n; i++){
            if(A[i-1] == A[i] || down > 0 && A[i-1] < A[i]){
                up = 0; down = 0;
            }
            if(A[i - 1] < A[i]) up++;
            else if(A[i-1] > A[i]) down++;

            if(up > 0 && down > 0) ans = max(ans, up + down + 1);
        }
        return ans;
    }  
};



// sol3, gy1, dp, up and down, O(n), O(n)
class Solution{
public:
    int longestMountain(vector<int>& A){
        int n = A.size(), ans = 0;
        vector<int> up(n, 0), down = up;
        
        for(int i = 1; i < n; i++){
            if(A[i] > A[i-1]) up[i] = up[i-1] + 1;
        }
        
        for(int i = n - 1; i > 0; i--){
            if( A[i-1] > A[i] ) down[i-1] = down[i] + 1;
        }
        
        for(int i = 0; i < n; i++){
            if(up[i] > 0 && down[i] > 0) ans = max(ans, up[i] + down[i] + 1);
        }
        return ans;
    }    
};



// !! sol2.1 from gy3, two pointer, similar to sol2 but clearer, O(n), O(1)
class Solution{
public:
    int longestMountain(vector<int>& A){
        int n = A.size(),ans = 0, start = 0, peak, end;
        while(start < n - 2){
            while(start < n - 2 && A[start] >= A[start + 1]) start++;
            peak = start;
            while(peak < n - 1 && A[peak] < A[peak + 1]) peak++;
            end = peak;
            while(end < n - 1 && A[end] > A[end+1]) end++;
            if(start < peak && peak < end) ans = max(ans, end - start + 1);
            start = max(end, start+1);
        }
        return ans;
    }  
};

// ! sol2, from sol1, two pointer, O(n), O(1), one pass

// class Solution{
//     public:
//     int longestMountain(vector<int>& A){
//         int n = A.size(), ans = 0;
//         int base = 0, end = 0;
        
//         while(base < n - 2){
//             end = base;
//             if(A[end] < A[end+1]){
//                 while(end + 1 < n && A[end] < A[end+1]){
//                     end++;
//                 } // find peak of left;
                
//                 if(end + 1 < n && A[end] > A[end+1]){
//                     while(end + 1 < n && A[end] > A[end+1]){
//                         end++;
//                     }// find peak of right;                    
//                     ans = max(ans, end - base + 1);
//                 }
//             }
//             base = max(end, base + 1);
//         }
//         return ans;
//     }
// };

// sol1, my, O(n), O(1), the same as gy4, but not one pass
// class Solution {
// public:
//     int longestMountain(vector<int>& A) {
//         int n = A.size();
//         int ans = 0;
//         for(int i = 1; i < n-1; i++){
//             if( A[i-1] >= A[i] || A[i] <= A[i+1]) continue;

//             int l = 1;
//             for(int j = i - 1; j >= 0; j--){
//                 if(A[j] >= A[j+1]){

//                     break;
//                 }
//                 l++;
//             }
//             for(int j = i;  j < n - 1; j++){
//                 if(A[j] <= A[j+1]){

//                     break;
//                 }
//                 l++;
//             }
            
//             ans = max(ans, l);
//         }
//         return ans;
//     }
// };

