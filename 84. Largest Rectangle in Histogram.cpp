// !!! sol2, O(n), O(n), monotone increasing stack
//https://www.youtube.com/watch?v=GYuBQacXr1A&feature=youtu.be
// gy
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        int res = 0;
        stack<int> st; // monotone increasing stack, idx stored
        for(int i = 0; i < n; i++){
            if(st.empty() || heights[st.top()] <= heights[i]){
                st.push(i);
            }
            else{
                int cur = st.top(); st.pop();
                int left;
                if(st.empty()) left = -1;
                else left = st.top();
                res = max(res, heights[cur] * (i - left - 1));
                i--; // i did not change
            }                
        }
        return res;
    }
};

// sol1, my, brute force, O(n^2), O(1)
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         vector<int> right(n), left(n);
//         int n = heights.size();
//         int res = 0;
//         for(int i = 0; i < n; i++){
//             int left = i - 1, right = i + 1;
//             while(right < n){
//                 if(heights[i] > heights[right]) break;
//                 right++;
//             }
//             while(left >= 0){
//                 if(heights[i] > heights[left]) break;
//                 left--;
//             }

//             res = max(res, (right - left - 1) * heights[i]);

//         }
//         return res;
        
//     }
// };
