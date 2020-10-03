

// Find the most frequent number in sliding window (类似leetcode: sliding window maximum/median)
// Example: 
// Input: arr = [1,2,2,1,3,3,2], k=3 (k is sliding window size)
// Output: [2,2,2,3,3] 
// *window内数字出现次数相同时随意输出其中一个即可

class SOL{
public:
    unordered_map<int, int> freq;
    unordered_map<int, unordered_set<int>> m; // m[count] = {1 , 2 ,3} means there are count number of 1, 2, 3   
    int max_count = 0;
    
    vector<int> slidingfreq(vector<int>& arr, int k){
        int n = arr.size();
        vector<int> res(n - k + 1);
        for(int i = 0; i < k; i++){
            freq[arr[i]]++;
            max_count = max(max_count, freq[arr[i]]);
        }
        
        for(auto& item:freq){
            int number = item.first, c = item.second;
            m[c].insert(number);
        }
        for(int i = k; i <= n; i++){
            res[i-k] = *m[max_count].begin();   
            if(i == n) break;
            remove(arr, i-k);
            add(arr, i);
        }
        return res;
    }
    
    void remove(vector<int>& arr, int i){
        m[freq[arr[i]]--].erase(arr[i]);
        m[freq[arr[i]]].insert(arr[i]);
        if(m[max_count].size() == 0) max_count--;
    }
    void add(vector<int>& arr, int i){
        m[freq[arr[i]]++].erase(arr[i]);
        m[freq[arr[i]]].insert(arr[i]);
        max_count = max(max_count, freq[arr[i]]);
    }
};


int main() {
    vector<int> arr = {1, 2, 2, 3, 2, 3, 2};
    int k = 3;
    SOL sol;
    
    vector<int> res = sol.slidingfreq(arr, k);
    
    for(int a:res) cout << a << endl;
    return -1;
}
