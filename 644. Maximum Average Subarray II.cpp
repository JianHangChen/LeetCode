//!!! sol1.1, gy4, O( nlog(valmax-valmin)), O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double l = nums[0], r = nums[0];
        for(int i = 1; i < n; i++){
            l = min(l, (double)nums[i]);
            r = max(r, (double)nums[i]);
        }
        while(l + 1e-5 <= r){
            double m = l + (r - l) / 2.;
            if(valid(m, nums, k)){ // if find a array >= k, avg >= m
                l = m;
            }
            else{ // avg is not inside [m, r]
                r = m;
            }            
        }
        return l;
    }
    bool valid(double m, vector<int>& nums, int k){
        // avg >= m  ->   sum(nums[i])/c >= m  ->  sum(nums[i]) >= cm
        // ->sum( nums[i] - m ) >= 0
        int n = nums.size();
        double presum = 0, sum = 0, minsum = 0;
        for(int i = 0; i < n; i++){
            sum += (nums[i] - m);
            
            
            if(i >= k - 1){
                if(sum - minsum >= 0) return true;
                
                presum += nums[i - (k-1)] - m;
                minsum = min(minsum, presum);
            }
            
        }
        
        
        return false;
        
    }
};

//!!! sol1, gy3, O( nlog(valmax-valmin)), O(n)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double l = nums[0], r = nums[0];
        for(int i = 1; i < n; i++){
            l = min(l, (double)nums[i]);
            r = max(r, (double)nums[i]);
        }
        while(l + 1e-5 <= r){
            double m = l + (r - l) / 2.;
            if(valid(m, nums, k)){ // if find a array >= k, avg >= m
                l = m;
            }
            else{ // avg is not inside [m, r]
                r = m;
            }            
        }
        return l;
    }
    bool valid(double m, vector<int>& nums, int k){
        // avg >= m  ->   sum(nums[i])/c >= m  ->  sum(nums[i]) >= cm
        // ->sum( nums[i] - m ) >= 0
        int n = nums.size();
        vector<double> presum(n+1);
        for(int i = 0; i < n; i++) presum[i+1] = presum[i] + (nums[i] - m);
        double min_presum = 0; 
        for(int i = 0; i < n; i++){
            if(i + k - 1 >= n) break;
            min_presum = min(min_presum, presum[i]);
            if( presum[i+k] - min_presum >= 0) return true;
        }
        return false;
        
    }
};
