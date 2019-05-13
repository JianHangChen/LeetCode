 
    sol1, dp,  O(n), O(n)
    int trap(vector<int>& height) {

        int size = height.size();
        if(size < 3){return 0;}
        int ans = 0;
        
        vector<int> max_left(size), max_right(size);
        max_left[0] = height[0];
        max_right[size-1] = height[size-1];
        
        for (int i = 1; i < size; i++){
            max_left[i] = max(max_left[i-1], height[i]);
        }
        for (int i = size - 2; i >= 0; i--){
            max_right[i] = max(max_right[i+1], height[i]);
        }
        
        
        for (int i = 1; i < size - 1 ; ++i){
            
            ans += min(max_left[i], max_right[i]) - height[i];
            
        }
        return ans;
    }

    sol2, stack,  O(n), O(n)
    int trap(vector<int>& height) {

        int size = height.size();
        if(size < 3){return 0;}
        int ans = 0;
        
        
        stack<int> s;
        
        int i = 0;
        while (i < size){
            
            while(!s.empty() && height[i] > height[s.top()]){
                
                int top = s.top(); s.pop();
                if(!s.empty()){
                    int dist = i - s.top() - 1;
                    ans += dist * (min(height[i], height[s.top()]) - height[top]);
                }
                
            }
            
            s.push(i++);            
            
        }
        return ans;
    }
    
    //!!! sol3, two pointers, O(n), O(1)
    int trap(vector<int>& height) {
        int size = height.size();
        int ans = 0;
        if (size < 3){ return 0;}
        
        int left = 0, right = size - 1;
        int left_max=height[left], right_max=height[right];
        

        while (left < right){
            if (left_max <= right_max){
                ans += left_max - height[left] ;
                left++;
                left_max = max(left_max, height[left]);
            }
            else{
                ans += right_max - height[right];
                right--;
                right_max = max(right_max, height[right]);
            }
        }
        return ans;
    }
