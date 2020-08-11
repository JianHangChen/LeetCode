    sol1, hashtable
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> t;
        vector<int> res;
        int n = numbers.size();
        
        for(int i = 0; i < n; i++){
            
            int num  = numbers[i];
            
            if(t.find(target - num) != t.end()){
                res = {t[target - num] + 1, i + 1};
                return res;
            }
            
            t[num] = i;
        }
        return res;
        
    }
    
    

    //!!! sol2, two pointer, O(n)

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int r = numbers.size() - 1;
        
        int l = 0;
        
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                res = {l+1, r+1};
                break;
            }
            else if(numbers[l] + numbers[r] > target) {
                r--;
            }
            else{
                l++;
            }
        }
        
        return res;
    }
    
