
// !!!!!! sol2, O(n), O(n) from 9 chapter
class Solution{
public:
    int hIndex(vector<int>& citations){
        int n = citations.size();
        vector<int> nums(n+1, 0);

        for(int i = 0; i < n; i++){
            if(citations[i] >= n){
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


 // ! sol1.1, O(nlogn), from gy
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());


        for(int i = 0; i < n; i++){
            if(citations[i] < i + 1){
                return i;
            }
        }
        return n;
    }
};



// sol1, my O(nlogn), easily wrong
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());

        int h = 0;

        for(int i = 0; i < n; i++){
            if(citations[i] <= i + 1){
                h = max(h, citations[i]);
                return h;
            }
            else{
                h = i + 1;
            }
        }
        return h;
    }
};


