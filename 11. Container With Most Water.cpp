    //two pointers,  O(n), O(1)
    int maxArea(vector<int>& height){
        int n = height.size();
        int max_area = 0, area;
        int i = 0, j = n - 1;
        while(i < j){
            if (height[i] > height[j]){
                area = (j - i) * height[j];
                j--;
            }
            else{
                area = (j - i) * height[i];
                i++;
            }
            max_area = max(max_area, area);
        }
        return max_area;
        
    }
