class Solution {
private:
    int n;
public:
    vector<int> pourWater(vector<int> &heights, int V, int K) {
        n = heights.size();
        for(int i = 0; i < V; i++){
            int l = K, r = K;
            
            while(l > 0 && heights[l-1] <= heights[l]) l--;
            while(l < K && heights[l] == heights[l+1]) l++;
            while(r < n-1 && heights[r] >= heights[r+1]) r++;
            while(r > K && heights[r-1] == heights[r]) r--;
            
            (heights[l] < heights[K]) ? (heights[l]++) : (heights[r]++);
        }
        return heights;
    }

};
