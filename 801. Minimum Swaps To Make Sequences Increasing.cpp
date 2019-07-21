
sol1.1, O(n), O(n), by dp
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
    	int n = A.size();
    	vector<int> has_swap(n, n);
        vector<int> no_swap(n, n);
        has_swap[0] = 1;
        no_swap[0] = 0;
        for(int i = 1; i < n; i++){
        	if(A[i-1] >= A[i] || B[i-1] >= B[i]){
	        	has_swap[i] = no_swap[i-1] + 1;
	        	no_swap[i] = has_swap[i-1];
        	}
        	else if(A[i-1] < B[i] && B[i-1] < A[i]){
        		no_swap[i] = min(no_swap[i-1], has_swap[i-1]) ;
        		has_swap[i] = no_swap[i] + 1;
        	}
        	else{
        		has_swap[i] = has_swap[i-1] + 1;
        		no_swap[i] = no_swap[i-1];
        	}
        }
        return min(has_swap[n-1], no_swap[n-1]);
    }
};

//sol1.2, O(n), O(1), dp
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
    	int n = A.size();
    	// vector<int> has_swap(n, n);
    	// vector<int> no_swap(n, n);
        int pre_has_swap, pre_no_swap;
        int has_swap = 1, no_swap = 0;
        for(int i = 1; i < n; i++){
            pre_has_swap = has_swap;
            pre_no_swap = no_swap;
            
        	if(A[i-1] < A[i] && B[i-1] < B[i]){
	        	has_swap = pre_has_swap + 1;
	        	no_swap = pre_no_swap;
        	}
            else{
                has_swap = n;
                no_swap = n;
            }
            
            if(A[i-1] < B[i] && B[i-1] < A[i]){
                has_swap = min(has_swap, pre_no_swap + 1);
                no_swap = min(no_swap, pre_has_swap);
            }
        }
        return min(has_swap, no_swap);
    }
};
