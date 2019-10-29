
//!!! sol2 my binary O(log n)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n  = citations.size();
        int l = 0, h = n, mid;

        while(l < h){
            mid = l + (h - l) / 2;

            if(n - mid > citations[mid]){
                l = mid + 1;
            }
            else{
                h = mid;
            }
        }
        return n - l;
    }
};


//sol1 O(n)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n  = citations.size();
        vector<int> nums(n+1, 0);
        for(int i = 0; i < n; i++){
            if(citations[i] > n){
                nums[n]++;
            }
            else{
                nums[citations[i]]++;
            }
        }
        int count = 0;
        for(int i = n; i >= 0; i--){
            count += nums[i];
            if(count >= i){
                return i;
            }
        }
        return n;
    }
};
