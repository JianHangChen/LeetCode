// sol1, my， O(n+l), O(l)
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int left_amount = 0;
        for(auto& v:shift){
            if(v[0] == 0) left_amount += v[1];
            else left_amount -= v[1];
        }
        int n = s.size();
        // abcd  left = 1  bcda     left = -1   d abc -> right 1->left 3
        while(left_amount < 0){ // nice method to get (negative number % n), from Brenda
            left_amount += n;
        }
        left_amount = left_amount % n;
        return s.substr(left_amount, n - left_amount) + s.substr(0, left_amount);
        
    }
};
