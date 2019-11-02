// !!!!!!!! sol2, from gy2 O(n), O(1)
class Solution{
public:
    bool verifyPreorder(vector<int>& preorder){
        int i_stack = -1, low = INT_MIN;
        for(int val:preorder){
            if(val < low) return false;
            while(i_stack > -1 && preorder[i_stack] < val){
                low = preorder[i_stack--];
            }
            preorder[++i_stack] = val;
        }
        return true;
    }
};



//! sol1, from gy1, O(n), O(n)
class Solution {
public:
    bool verifyPreorder(vector<int> &preorder) {
        stack<int> s;
        int low = INT_MIN;

        for(int i = 0; i < preorder.size(); i++){
            if(preorder[i] < low) return false;

            if(s.empty() || s.top() > preorder[i]) {s.push(preorder[i]);}
            else{
                while(!s.empty() && s.top() < preorder[i]){
                    low = s.top(); s.pop();
                }
                s.push(preorder[i]);
            }
        }
        return true;
    }
};


//sol3, divide and conquer from gy3, O(n^2)
class Solution{
public:
    bool verifyPreorder(vector<int>& preorder){
        return verifyPreorder(preorder, 0, preorder.size()-1, INT_MIN, INT_MAX);
    }

    bool verifyPreorder(vector<int>& preorder, int start, int end, int low, int high){
        if(start > end) return true;
        int val = preorder[start]; // val of the mid number
        if(val <= low || val >= high) return false;
        
        int right;
        for(right = start + 1; right <= end; right++){
            if(preorder[right] >= val){
                break;
            }
        }
        return verifyPreorder(preorder, start+1, right-1, low, val)
        && verifyPreorder(preorder, right, end, val, high);

    }
};
