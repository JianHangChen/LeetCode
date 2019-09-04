//sol4,  !!!!!, linear dp, O(n), O(1)
class Solution{
public:
	int wiggleMaxLength(vector<int>& nums){
		int n = nums.size();
		if(n < 2) return n;
		int up = 1, down = 1;
		for(int i = 1; i < n; i++){
			if(nums[i-1] < nums[i]){
				up = down + 1;
			}
			else if(nums[i-1] > nums[i]){
				down = up + 1;
			}
		}
		return max(up, down);
	}
};

//sol3,  linear dp, O(n), O(n)
class Solution{
public:
	int wiggleMaxLength(vector<int>& nums){
		int n = nums.size();
		if(n < 2) return n;
		vector<int> up(n, 0), down = up;
		up[0] = 1; down[0] = 1;
		for(int i = 1; i < n; i++){
			if(nums[i-1] < nums[i]){
				up[i] = down[i-1] + 1;
				down[i] = down[i-1];
			}
			else if(nums[i-1] > nums[i]){
				down[i] = up[i-1] + 1;
				up[i] = up[i-1]; 
			}
			else{
				down[i] = down[i-1];
				up[i] = up[i-1];
			}
		}
		return max(up[n-1], down[n-1]);
	}
};

// sol2, dp, O(n^2), O(n), from sol2
class Solution{
public:
	int wiggleMaxLength(std::vector<int>& nums){
		int n = nums.size();

		if(n == 0) return 0;
		vector<int> up(n, 0), down = up;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < i; j++){
				if(nums[j] < nums[i]){
					up[i] = max(up[i], down[j] + 1);
				}
				if(nums[j] > nums[i]){
					down[i] = max(down[i], up[j] + 1);
				}
			}
		}
		return max(up[n-1], down[n-1]) + 1;
	}
};



// sol1, brute force, O(n!), O(n), from sol1

class Solution{
public:
	int wiggleMaxLength(vector<int>& nums){
		int n = nums.size();
		if(n <= 1) return n;

		return max(getlen(nums, 0, true), getlen(nums, 0 , false)) + 1;
	}

	int getlen(std::vector<int>& nums, int idx, bool isUp){
		int res = 0;
		for(int i = idx + 1; i < nums.size(); i++){
			if(isUp && nums[i] > nums[idx] || !isUp && nums[i] < nums[idx]){
				res = max(res, getlen(nums, i, !isUp) + 1);
			}
		}
		return res;
	}

};

