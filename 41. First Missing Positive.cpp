    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
        	while(nums[i] - 1 >= 0 && nums[i] - 1 < n && nums[ nums[i] - 1 ] != nums[i]){
        		swap(nums[nums[i] - 1], nums[i]);  	 
        	}
        }

        for(int i = 0; i < n; i++){
        	if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }

class Solution:
    
    #sol1, O(n) but space O(n)
    def firstMissingPositive(self, nums: List[int]) -> int:
        visited = [False] * (len(nums) + 1)
        
        for num in nums:
            if 0 < num <= len(nums):
                visited[num-1] = True
        
        for i in range(len(visited)):
            if visited[i] == False:
                return i + 1
                
    # sol2, O(n) ,O(1)    
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while n  >= nums[i] > 0 and nums[nums[i] - 1] != nums[i]:# 1. avoid nums[i] == i+1 2. avoid infinite loop for repeated number
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range( n ):
            if nums[i] != i + 1:
                return i + 1
        return n + 1
