
// sol2, dp, hint by gy
class Solution{
public:
	int numFactoredBinaryTrees(vector<int> &A){
		long res = 0; int n = A.size(); int P = 1e9 + 7;
		vector<int> nums(A);
		sort(nums.begin(), nums.end());		

		unordered_map<int, long> dp; // for number i, dp[i] is the num of factored binary trees;
		
		for(int i = 0; i < n; i++){
			dp[nums[i]] = 1;
			for(int j = 0; j < i; j++){
				if(	nums[i] % nums[j] == 0 && dp.count( nums[i] / nums[j] ) > 0 ){
					dp[nums[i]] = (dp[nums[i]] + dp[nums[j]] * dp[nums[i] / nums[j]]) % P;
				}
			}
			res = (res + dp[nums[i]]) % P;
		}
		return res;
	}
};

// my sol1, cached dfs
class Solution {
private:
	unordered_map<int, int> ck;
	int P = pow(10,9) + 7;
public:
    int numFactoredBinaryTrees(vector<int> &A) {
        unordered_set<int> s(A.begin(), A.end());
        long long res = 0; // initialization!!!
        for(int num:A){
        	res += check(num, A,s);
        }
        return res % P;
    }

    int check(int num, vector<int> &A, unordered_set<int>& s){
    	if(ck.count(num) > 0) return ck[num];
    	long long res = 1;
    	if(num <= 1) return 0;
    	for(int a:A){
    		if(num != a && num % a == 0 && s.count(num / a) > 0){
    			res += check(a, A,s)  * check(num / a, A,s); // multiply!! instead of add!
    		}
    	}
    	int ans = res % P;
    	ck[num] = ans;
  
    	return ans;
    }
};

