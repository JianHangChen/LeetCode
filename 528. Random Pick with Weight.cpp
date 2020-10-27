//!!!! sol2, follow up, what if the weight often changes?
// https://leetcode.com/problems/random-pick-with-weight/discuss/182620/Follow-up%3A-what-if-we-can-change-weights-array

class Solution {
private:
    vector<int> bit, nums;
    int n;
    int total_w = 0;
public:
    void update(int index, int val){ // update value of position index
        int offset = val - nums[index];
        nums[index] = val;
        int i = index+1;
        while(i <= n){
            bit[i] += offset;
            i = i + (i & (-i));
        }
    }
    int getsum(int index){
        int i = index + 1;
        int s = 0;
        while(i > 0){
            s += bit[i];
            i = i - (i & (-i));
        }
        return s;
    }
    
    Solution(vector<int>& w){
        n = w.size();
        nums.resize(n);
        bit.resize(n+1, 0);
        for(int i = 0; i < n; i++){
            update(i, w[i]);
            total_w += w[i];
        }
    }
    
    int pickIndex(){
        int r = rand() % total_w;
        int l = 0, h = n - 1;
        while(l < h){
            int mid = l + (h - l) / 2;
            int s = getsum(mid);
            if(r < s){
                h = mid;                
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};

    
//!! sol1, my, same as sol2
// initialization O(n), O(n)
// pick O(logn)
class Solution {
public:
    vector<int> pre;
    int s;
    Solution(vector<int>& w) {
        s = 0;
        for(int num:w){
            pre.push_back(s);
            s += num;
        }
        
    }
    
    int pickIndex() {
        int r = rand() % s;
        auto ub = upper_bound(pre.begin(), pre.end(), r);
        return ub - pre.begin() - 1;
    }
};
