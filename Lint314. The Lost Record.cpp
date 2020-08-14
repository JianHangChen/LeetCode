

// !!! O(n), O(n) greedy
// https://www.bilibili.com/video/BV1W64y1c7h8
class Solution {
public:

    int minimumMessages(int m, vector<int> &a) {
        int n = a.size();
        if(n < 3) return -1;
        auto arr = a;
        arr[0] = max(arr[0], 0);
        arr[1] = max(arr[1], 0);
        for(int i = 2; i < n; i++){
            arr[i] = max(arr[i], 0);
            if(arr[i-2] + arr[i-1] + arr[i] < m){
                if(a[i] == -1){
                    arr[i] = m - arr[i-1] - arr[i-2];
                }
                else if(a[i-1] == -1){
                    arr[i-1] = m - arr[i] - arr[i-2];
                }
                else if(a[i-2] == -1){
                    arr[i-2] = m - arr[i] - arr[i-1];
                }
                else return -1;
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            res += arr[i];
        }
        return res;
    }
    
};
