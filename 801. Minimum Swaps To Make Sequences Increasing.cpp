
// sol1.1, O(n), O(n), small modification, from grandyang
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
    	int n = A.size();
    	vector<int> has_swap(n, n);
        vector<int> no_swap(n, n);
        has_swap[0] = 1;
        no_swap[0] = 0;
        for(int i = 1; i < n; i++){
	    if(A[i-1] < A[i] && B[i-1] < B[i]){
		has_swap[i] = has_swap[i-1] + 1;
		no_swap[i] = no_swap[i-1];
	    }
            
            if(A[i-1] < B[i] && B[i-1] < A[i]){
                has_swap[i] = min(has_swap[i], no_swap[i-1] + 1);
                no_swap[i] = min(no_swap[i], has_swap[i-1]);
            }

        }
        return min(has_swap[n-1], no_swap[n-1]);
    }
};

//!!! sol1.2, O(n), O(1), dp
class Solution {
public:
    int n;
    int minSwap(vector<int>& A, vector<int>& B) {
        n = A.size();
        // carefull about initialization, it should be big number since we want a min answer
        //noswap[i]: without swap A[i] B[i], the minimum swap required for [0:i] become valid
        int noswap = n, pre_noswap = 0;
        int swap = n, pre_swap = 1;
        for(int i = 1; i < n; i++){
            noswap = n; swap = n;
            if(A[i] > A[i-1] && B[i] > B[i-1]){
                noswap= pre_noswap;
                swap = pre_swap + 1;
            }
            if(A[i] > B[i-1] && B[i] > A[i-1]){
                noswap = min(noswap, pre_swap);
                swap = min(swap, pre_noswap + 1);
            }
            pre_noswap = noswap;
            pre_swap = swap;
        }
        return min(noswap, swap);
    }
};
};
