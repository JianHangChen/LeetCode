


//!!!!! sol4, DP, from gy3, O(M + N),  M is the maximum range of difficulty, O(M) 

class Solution{
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
		vector<int> dp(1e5 + 1, 0);
		for(int i = 0; i < profit.size(); i++){
			dp[difficulty[i]] = max(dp[difficulty[i]], profit[i]);
		}
		for(int i = 1; i < dp.size(); i++){
			dp[i] = max(dp[i], dp[i-1]);
		}
		int res = 0;
		for(auto wker:worker){
			res += dp[wker];
		}
		return res;
	}	
};

//!! sol3, from gy2, sol1, O(nlogn + mlogm), O(n)
class Solution{
public:
	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker){
		vector<vector<int>> works;
		for(int i = 0; i < profit.size(); i++){
			works.push_back({difficulty[i], profit[i]});
		}
		sort(works.begin(), works.end());
		sort(worker.begin(), worker.end(), less<int> ());//!!!
		int idx = 0, best = 0, res = 0;
		for(int wker:worker){
			while(idx < works.size() && wker >= works[idx][0] ){
				best = max(best, works[idx][1]);
				idx++;
			}
			res += best;
		}
		return res;
	}
};



//!!!!! sol2,  from gy1, O(nlogn + wlogn), O(n), binary search
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(); 
        map<int, int> m; // diff->profit
        for(int i = 0; i < n; i++){
        	m[difficulty[i]] = max(m[difficulty[i]], profit[i]); // !! here should use max, otherwise new profit will erase old one no matter how big the value is
        }
        int max_profit_to_now = 0;
        for(auto& work:m){ //change m: diff->max_profit_to_now
        	work.second = max(work.second, max_profit_to_now);
        	max_profit_to_now = work.second;
        }
        int res = 0;
        for(int wker:worker){
        	auto it = m.upper_bound(wker);
        	if(it != m.begin()) res += (--it)->second; //(*(--it)).second
        }
        return res;
    }
};






// sol1, my O(n^2), too slow
class Solution {
public:

	struct{
		bool operator()(vector<int>& a, vector<int>& b){
			if(a[1] == b[1]) return a[0] < b[0];
			return a[1] > b[1];
		}
	} cmp;
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(); if(n == 0) return 0;
        vector<vector<int>> works;
        for(int i = 0; i < n; i++) works.push_back({difficulty[i], profit[i]});
        sort(works.begin(), works.end(), cmp);
        int res = 0;
        for(int diff:worker){
        	for(int i = 0; i < n; i++){
        		if(diff >= works[i][0]){
        			res += works[i][1]; break;
        		}
        	}
        }
        return res;
    }
};
