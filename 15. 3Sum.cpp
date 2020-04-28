
//!!! sol1.1, my two pointer, O(n^2), O(1)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 0 || nums[0] > 0 || nums.back() < 0) return {};
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) break;
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            int j = i + 1, k = n - 1; 
            while(j < k){
                if(j != i + 1 && nums[j-1] == nums[j]){
                    j++; continue;
                }      
                int s = nums[i] + nums[j] + nums[k];
                if( s == 0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++; k--;
                }
                else if(s > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res; 
        
    }
};


// -1, 0, 1, 2, -1, -4
// -4  -1 -1  0  1   2
// 4 1 1 0 -1 -2




//! sol1, O(n^2), O(1) from gy1, two pointer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() == 0 || nums[0] > 0 || nums.back() < 0) return res;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1, k = nums.size() - 1, target = 0 - nums[i];
            while(j < k){
                if(nums[j] + nums[k] == target){  // avoid the repeat of j by runing j++ and k--
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while(j < k && nums[k] == nums[k-1]) k--;
                    j++; k--;
                }
                else if(nums[j] + nums[k] > target) k--;
                else j++;
            }
        }
        return res;       
    }
};

sol2, my hash_set, same as sol2, O(n^2), O(n) not considering the result vector
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        unordered_map<int, int> m;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            m[-nums[i]] = i;            
        }        
        
        for(int i = 0; i < nums.size(); i++){
            if(i != 0 && nums[i] == nums[i-1]) continue;
            
            for(int j = i + 1; j < nums.size(); j++){
                if(j != i + 1 && nums[j] == nums[j-1]) continue;
                if(m.count(nums[i] + nums[j]) > 0 ){
                    if(m[nums[i] + nums[j]] > j){
                        res.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                    }
                }                
            }
        }
        return res;
    
    }
    
};

