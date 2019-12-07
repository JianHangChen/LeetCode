

// 1 <= N <= 10^9
//100000000
//99999999


// !!!!sol2.1, from gy2, special coding for counting digits, O( (logN)^2 ), ( O(1) or O(logN) space depend on how you treat long)
class Solution{
public:
	bool reorderedPowerOf2(int N){
		long codeN = convert(N);
		for(int i = 0; i < 31; i++){
			if( convert(1 << i) == codeN) return true;
		}
		return false;
	}	
	long convert(int N){
		if(N == 0) return 1;
		long code = 0;
		while(N > 0){
			code += pow(10, N % 10);
			N /= 10;
		}
		return code;
	}
};




// sol2, from gy1, O(sum(ilogi))
// N -> sort(N), 2^i -> sort(2^i)
#include <string>
#include <vector>
using namespace std;
class Solution{
public:
	bool reorderedPowerOf2(int N){
		string n = to_string(N);
		sort(n.begin(), n.end());

		for(int i = 0; i < 31; i++){
			string n2 = to_string(1 << i);
			sort(n2.begin(), n2.end());
			if(n == n2) return true;
		}
		return false;
	}	
};

// sol1, my, very slow, backtracking, O((logN)!(logN)), O(logN)
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        vector<int> num;
        if(N == 0) num.push_back(0);
        while(N != 0){
	        num.push_back(N%10);
	        N /= 10;
        }

        if(permute(num, 0, 0)) return true;

        return false;

    }

    bool permute(vector<int>& num, int start, int level){

    	if(level == num.size()){
    		int N = 0;
    		if(num.back() == 0) return false;
    		for(int i = 0; i < num.size(); i++){
    			N = N * 10 + num[num.size() - i - 1]; 
    		}
    		if(isPowerOf2(N)) return true;
    		else return false;
    	}
    	for(int i = start; i < num.size(); i++){
    		swap(num[start], num[i]);
    		if(permute(num, start + 1, level + 1)) return true;
    		swap(num[start], num[i]);
    	}
    	return false;
    }

    bool isPowerOf2(int N){
    	while(N > 0){
    		if(N == 1) return true;
    		else{
    			if(N % 2 == 1) return false;
    			else N = N/2;
    		}
    	}
    	return false;
    }

};
