

//!!! sol2, from sol1, one pass, O(n), O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int red = 0, blue = n - 1;
        
        int i = 0;
        while( i <= blue){
            if(nums[i] == 0){
                if(i == red){  
                    // !!important to increase i when it is overlap with red, 
                    //that means all elements from red is 0
                    red++; i++;
                }
                else{
                    // we don't know what's nums[red], so after swap, we still need to check nums[i]
                    swap(nums[i], nums[red++]);               
                }
            }
            else if(nums[i] == 2){
                // we don't know what's nums[blue], so after swap, we still need to check nums[i]
                // but we don't need to check i == blue, because it will finally end due to blue--
                swap(nums[i], nums[blue--]);
            }
            else{
                i++;
            }
        }    
        

        return;
        
    }
};

// sol1, my, counting sort, O(n), O(1) 
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3,0);
        for(int i = 0; i < nums.size(); i++){
            count[nums[i]]++;
        }
        int i = 0;
        for(int j = 0; j < 3; j++){
            while(count[j] > 0){
                count[j]--;
                nums[i++] = j;
            }
        }
        return;
        
    }
};
