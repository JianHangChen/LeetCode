// !!! sol2, two multiset, from gy2, O(nlogk), O(k)
class Solution {
public:
    multiset<int, greater<int>> max_set;
    multiset<int> min_set;
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> res(n - (k - 1), 0);
        for(int i = 0; i < k; i++) add(nums[i]);
        
        for(int i = k; i <= n; i++){
            res[i-k] = k%2==1 ? *max_set.begin() : ((double)*max_set.begin() + *min_set.begin()) / 2.0;
            if(i == n) break;
            erase(nums[i-k]);
            add(nums[i]);            
        }
        return res;
        
    }
    
    void add(int num){
        if(max_set.empty() || num <= *max_set.begin()){
            max_set.insert(num);
        }
        else{
            min_set.insert(num);
        }
        maintain();
    }
    
    void erase(int num){
        if(num > *max_set.begin()){
            min_set.erase(min_set.find(num));
        }
        else{
            max_set.erase(max_set.find(num));
        }
        maintain();
        
    }
    
    void maintain(){
        if(max_set.size() > min_set.size() + 1){
            min_set.insert(*max_set.begin());
            max_set.erase(max_set.begin());            
        }
        else if(max_set.size() < min_set.size()){
            max_set.insert(*min_set.begin());
            min_set.erase(min_set.begin());
        }
    }
    
    
};



// wrong, it's hard to use multiset to get a index.
// class Solution {
// public:
//     vector<double> medianSlidingWindow(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<double> medians( n-(k-1) , 0);
//         multiset<int> ms(nums.begin(), nums.begin() + k); //!! we can use this for set initialization
//         auto mid = next(ms.begin(), k / 2); // !!!use next and prev looking for the element inside multiset using index, cannot directly beign() + n like vector.
        
//         bool isodd = k % 2 == 1;
//         medians[0] = isodd ? *mid : double(*prev(mid) + *mid) / 2.0;
        
//         for(int i = 1; i < medians.size(); i++){
//             if(nums[i-1] <= *mid){
//                 mid++;
//             }
//             else{
//                 mid--;
//             }
//             ms.erase(ms.find(nums[i-1]));
//             // cout << "erase: " << nums[i-1] << endl;
//             ms.insert(nums[i+k-1]);

//             if(nums[i+k-1] < *mid){
//                 mid--;
//             }
//             else{
//                 mid++;
//             }
//             // cout << "isnert: " << nums[i+k-1] << endl;
//             medians[i] = isodd ? *mid : double(*prev(mid) + *mid) / 2.0;
//         }
//         return medians;
//     }
// };
