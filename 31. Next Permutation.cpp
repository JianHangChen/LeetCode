
// !!sol1.1, the same from gy2, more succinct
class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int i , j, n = nums.size();
        for(i = n - 2; i >= 0 ; i--){
            if(nums[i] < nums[i+1]) break;
        }
        if(i >= 0){
            for(j = n - 1; j > i; j--){
                if(nums[i] < nums[j]) break;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};


// sol1, from sol1, O(n), O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        while(i > 0){
            if(nums[i-1] < nums[i]){
                break;
            }
            i--;
        }
        int j = n - 1;
        while(j > 0){
            if(i == 0 || nums[i-1] < nums[j]){
                if(i != 0){
                    swap(nums[i-1], nums[j]);                
                }
                j = n - 1;
                while(i < j){
                    swap(nums[i++], nums[j--]);
                }
                break;
            }
            j--;
        }
        
    }
};

    # sol1
def nextPermutation(self, nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    def swap(i,j):
        nums[i],nums[j] = nums[j],nums[i]

    def reverse(i):
        for k in range(i,i + (len(nums) - i)//2):
            swap(k, i + len(nums) - 1 - k)


    i = len(nums) - 1
    while i > 0:
        if nums[i-1] < nums[i]:
            j = i
            while j < len(nums) - 1:
                if nums[j+1] <= nums[i-1]:
                    break
                j += 1
            swap(i-1, j)
            reverse(i)
            return
        else:
            i -= 1

    reverse(0)

                
