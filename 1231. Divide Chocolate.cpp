// !!! sol1, binary search, O(nlogr), O(1) 
// r = hi - 1 (range);
// https://leetcode.com/problems/divide-chocolate/discuss/408503/JavaC%2B%2BPython-Binary-Search
class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int K) {
        int s = 0;
        for(int num:sweetness) s += num;
        int hi = s / (K+1), lo = 1;
        
        while(lo < hi){
            int mid = lo + (hi - lo + 1) / 2;
            if(check(mid, sweetness, K)){
                lo = mid;
            }
            else{
                hi = mid - 1;
            }
        }        
        return lo;
    }
    
    bool check(int minimum, vector<int>& sweetness, int K){
            int accumulate = 0;
            int count = 0;
            for(int i = 0; i < sweetness.size(); i++){
                accumulate += sweetness[i];
                if(accumulate >= minimum){
                    accumulate = 0;
                    count++;
                    if(count == K+1) return true;
                }
            }
            return false;
    }
    
};
