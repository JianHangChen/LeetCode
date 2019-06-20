class NumArray {
public:
    vector<int> cum;
    NumArray(vector<int>& nums){
        int n = nums.size();
        cum.resize(n+1, 0);
        for(int i = 0; i < n; i++){
            cum[i+1] = cum[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return cum[j+1] - cum[i];
    }

};
