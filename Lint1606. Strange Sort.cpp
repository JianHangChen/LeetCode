
//!!! sol3, quicksort, from princeton algorithm23, O(nlogn), O(log n) extra recursion space
class Solution{
public:
    void quicksort(vector<int>& num, vector<int>& cost, int lo, int hi){
        if(lo >= hi) return;
        
        int pivot = partition(num, cost, lo, hi);
        quicksort(num, cost,  lo, pivot - 1);
        quicksort(num, cost, pivot + 1, hi);
        return;
    }


    vector<int> strangeSort(int n, vector<int>& num, vector<int>& cost){
        quicksort(num, cost, 0, n - 1);
        return num;
    }
    
    int partition(vector<int>& num, vector<int>& cost, int lo, int hi){
        int r = lo + rand() % (hi - lo + 1);
        swap(num[lo], num[r]);
        swap(cost[lo], cost[r]);
        
    
        int i = lo, j = hi + 1;
        
        while(true){
            while(cost[++i] < cost[lo]){
                if(i == hi) break;
            }
            while(cost[--j] > cost[lo]){
                if(j == lo) break;
            }
            
            if(i >= j) break;
            swap(num[i], num[j]);
            swap(cost[i], cost[j]);
        }
        swap(num[j], num[lo]);
        swap(cost[j], cost[lo]);
        return j;
    }
    
};


// sol2, from not, use the feature of cmp, TLE
// O(nlogn), O(n)

// struct CMP{
//     bool operator()(vector<int>& a, vector<int>& b) const{
//         return a[0] < b[0];
//     }
// } cmp;
// class Solution{
// public:
//     vector<int> strangeSort(int n, vector<int> & num, vector<int>& cost){
//         vector<vector<int>> pairs(n);
//         for(int i = 0; i < n; i++){
//             pairs[i] = {cost[i], num[i]};
//         }
//         sort(pairs.begin(), pairs.end(), cmp);
        
//         vector<int> res(n);
//         for(int i = 0; i < n; i++){
//             res[i] = pairs[i][1];
//         }
//         return res;
//     }    
// };


// sol1, my O(nlogn), O(n) for mapping and res
// class Solution {
// public:
//     /**
//      * @param n: Length of the array
//      * @param num: num array
//      * @param cost: cost array
//      * @return: nothing
//      */
//     vector<int> strangeSort(int n, vector<int> &num, vector<int> &cost) {
//         unordered_map<int, vector<int>> m;
        
//         for(int i = 0; i < n; i++){
//             m[cost[i]].push_back(num[i]);
//         }
//         sort(cost.begin(), cost.end());
//         vector<int> res;
        
//         int i = 0; 
        
//         while(i < n){
//             for(auto item:m[cost[i]]){
//                 res.push_back(item);
//             }
//             i = i + m[cost[i]].size();
//         }
//         return res;
//     }
// };
