// !! sol2, sort, using two point, from sol3, O(NlogN), O(1)

// [1,1,3,3,5,5,6,7]

class Solution {
public:
    int countElements(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        int count = 0;
        sort(arr.begin(), arr.end());
        
        int i = 0, j = 1;
        int run_len = 1;
        
        while(j < n){
            if(arr[i] == arr[j]){
                run_len++;
                j++;
            }
            else{
                if(arr[i] + 1 == arr[j]){
                    count += run_len;
                }
                i = j;
                j++;
                run_len = 1;
            }
        }
        
        return count;
        
    }
};


//!! sol1, hash, my O(n), O(n), same as sol2
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> s;
        for(int num:arr){
            s.insert(num);
        }
        
        int res = 0;
        for(int num:arr){
            if( s.count(num+1) > 0) res++;
        }
        return res;
        
    }
};
