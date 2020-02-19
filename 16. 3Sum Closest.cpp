//sol1, my, O(n^2), O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        int n = nums.size(), distance = INT_MAX, res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n ; i++){
            int j = i + 1, k = n - 1;
            while(j < k){
                int s = nums[i] + nums[j] + nums[k];
                if(s == target){
                    return target;
                }
                else if(s < target){
                    if(target - s < distance){
                        distance = target - s;
                        res = s;
                    }
                    j++;
                }
                else{
                    if(s - target < distance){
                        distance = s - target;
                        res = s;
                    }
                    k--;
                }
            }
        }
        return res;

    }
};
