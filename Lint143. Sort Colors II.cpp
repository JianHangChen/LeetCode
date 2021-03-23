class Solution {
public:
    //sol2 selection sort, nlogn
    // divide and conquer
    void sortColors2(vector<int> &colors, int k) {
        sortcolor(colors, 0, colors.size() - 1, 1, k);
    }
    // k = 4
    // [3,2,2,1,4] 
    // mid = 1 + 3/2 = 2
    // [1,2,2,4,3]
    // 

    void sortcolor(vector<int>& colors, int start, int end, int small, int large){
        if(small == large) return;
        int mid = small + (large - small) / 2;
        int a = start, b = end, i = a;
        while(i <= b){
            if(colors[i] > mid){
                swap(colors[i], colors[b--]);
            }
            else{ // if(colors[i] <= mid)
                swap(colors[i++], colors[a++]);
            }
        }
        sortcolor(colors, start, b, small, mid);
        sortcolor(colors, b+1, end, mid+1, large);
    }

    //!!! sol1.1, counting sort to save space, O(n), O(1)
    void sortColors2(vector<int> &colors, int k) {
        int n = colors.size();
        for(int i = 0; i < n; i++){
            int color = colors[i];
            if(color < 0) continue;
            int idx = color - 1;
            if(colors[idx] > 0){
                swap(colors[idx], colors[i]);
                colors[idx] = -1;
                i--;
            }
            else{
                colors[i] = 0;
                colors[idx]--;
            }
        }
        int j = n - 1;
        for(int i = k - 1; i >= 0; i--){
            int count = -colors[i];
            while(count > 0){
                colors[j--] = i + 1;
                count--;
            }
        }


    }
    
    // 3  2  2  1  4
    // -1 -2 -1 -1 0
    // -1 2 2 3 4

    // my sol1, counting sort , O(n), O(k)
    // void sortColors2(vector<int> &colors, int k) {
    //     vector<int> count(k, 0);

    //     for(int color:colors){
    //         count[color-1]++;
    //     }
    //     int j = 0;
    //     for(int i = 0; i < k; i++){
    //         while(count[i] > 0){
    //             colors[j++] = i + 1;
    //             count[i]--;
    //         }
    //     }

    // }
};
