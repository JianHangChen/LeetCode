
// !!! sol3, hash+monotonous decreasing stack, O(n), O(n)

class Solution{
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        vector<int> res;
        unordered_map<int, int> m;
        stack<int> s;
        for(int i = 0; i < nums2.size(); i++){
            if(s.empty() || s.top() > nums2[i]) s.push(nums2[i]);
            else{
                m[s.top()] = nums2[i]; s.pop();
                i--;
            }
        }
        while(!s.empty()){
            m[s.top()] = -1; s.pop();
        }
        for(int num:nums1) res.push_back(m[num]);
        return res;
    }
};

//! my sol2, skip, O(n), O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        
        vector<int> next(nums2.size());
        
        for(int i = 0; i < nums2.size(); i++) m[nums2[i]] = i;
        
        for(int i = nums2.size() - 1; i >= 0; i--){
            int j = i + 1;
            while(j <= nums2.size()){
                if(j == nums2.size() || nums2[j] > nums2[i]){
                    next[i] = j;
                    break;
                }
                else{
                    j = next[j];
                }
            }            
        }
        
        
        vector<int> res;
        for(int num:nums1){
            if(next[m[num]] == nums2.size()) res.push_back(-1);
            else res.push_back(nums2[next[m[num]]]);
        }
        return res;
    }
};

my sol1, brute force hash, same as sol1, O(n^2), O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums2.size(); i++) m[nums2[i]] = i;
        vector<int> res;
        for(int num:nums1){
            int i;
            for(i = m[num] + 1; i < nums2.size(); i++){
                if(nums2[i] > num){
                    res.push_back(nums2[i]);
                    break;
                }
            }
            if(i == nums2.size()) res.push_back(-1);
        }
        return res;
    }
};
