// sol2, follow up, what if the weight often changes?

// sol1, my, same as sol2
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

/**Z
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
