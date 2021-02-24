// !!! sol1.1 O(mn), O(n)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n+1, 0);
        int res = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    if(matrix[i][j] == '1') h[j] = 1;
                    else h[j] = 0;
                }
                else{
                    if(matrix[i][j] == '1') h[j] = h[j]+1;
                    else h[j] = 0;
                }
            }
            res = max(res, maxHistogram(h));
        }
        return res;        
    }
    int maxHistogram(vector<int>& h){
        int n = h.size();
        stack<int> st;
        int res = 0;
        for(int i = 0; i < n; i++){
            if(st.empty() || h[st.top()] < h[i]){
                st.push(i);
            }
            else{
                int cur = st.top(); st.pop();
                int left = -1;
                if(!st.empty()) left = st.top();
                res = max(res, h[cur] * (i - left - 1));
                i--;
            }
        }
        return res;
    }
    
};

//sol1, my, use monotone stack for max rectangle histogram 
// O(mn), O(mn)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> s(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    if(matrix[i][j] == '1') s[i][j] = 1;
                    else s[i][j] = 0;
                }
                else{
                    if(matrix[i][j] == '1') s[i][j] = s[i-1][j]+1;
                    else s[i][j] = 0;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m; i++){
            s[i].push_back(0);
            stack<int> st;
            for(int r = 0; r < s[i].size(); r++){// r: right
                if(st.empty() || s[i][st.top()] < s[i][r] ) st.push(r);
                else{
                    int cur = st.top(); st.pop();
                    int l = -1; // l: left
                    if(!st.empty()) l = st.top();
                    res = max(res, s[i][cur] * (r - l - 1));
                    r--;
                }
            }
        }
        return res;        
    }
};
