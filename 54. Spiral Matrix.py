class Solution {
public:
    
    //sol1, speed the same but hard to implement, O(1), O(1)
    void turn(int &direction,int &i,int &j, int &top,int &bottom,int &left, int &right){
        if (direction == 0){
            if (j < right){j++; return;}
            i++;
            top++;
        }
        else if(direction == 1){
            if (i < bottom){i++; return;}
            j--;
            right--;
        }
        else if(direction == 2){
            if (j > left){j--; return;}
            i--;
            bottom--;
        }
        else{
            if (i > top){i--; return;}
            j++;
            left++;
        }
        
        direction = (direction + 1) % 4;
    }
    
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        if (m < 1){return res;}
        int n = matrix[0].size();
        
        int upper = 0, lower = m - 1, left = 0, right = n - 1;
        
        int direction = 0; // 0 , 1, 2, 3 right, down, left, up
        
        int i = 0, j = 0;
        
        while (i >= upper && i <= lower && j >= left && j <= right){       
            res.push_back(matrix[i][j]);
            turn(direction,i, j, upper, lower, left, right);
        }
        return res;
        
    };
    
    
    //sol2
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r = matrix.size();
        if (r < 1){ return res;}
        int c = matrix[0].size();
        
        int i = 0, j = 0, direction = 0;
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        
        vector< vector<bool> > visited(r, vector<bool>(c, false) );
        
        for(int q = 0; q < r * c; q++){
            //cout << "i, j: " << i << j << endl;
            
            res.push_back(matrix[i][j]);
            visited[i][j] = true;
            
            int ii = i + dr[direction];
            int jj = j + dc[direction];
            
            if (ii >= r || ii < 0 || jj >= c || jj < 0|| visited[ii][jj]){
                direction = (direction + 1) % 4;
                i = i + dr[direction];
                j = j + dc[direction];
            }
            else{
                i = ii;
                j = jj;
            }            
        }
        return res;        
    }
    
    //sol3, spiral layer by layer
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r = matrix.size();
        if (r < 1){ return res;}
        int c = matrix[0].size();
        
        int left = 0, right = c - 1;
        int top = 0, bottom = r - 1;
        
        while (left <= right && top <= bottom){
            
            //spin        
            for (int j = left; j <= right; j++){
                res.push_back(matrix[top][j]);
            }
            for (int i = top+1; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            if( left!=right && top != bottom){
                //roll back
                for(int j = right - 1; j >= left; j--){
                    res.push_back(matrix[bottom][j]);
                }
                for(int i = bottom - 1; i > top; i--){
                    res.push_back(matrix[i][left]);
                }
            }
            left++; right--; top++; bottom--;            
        }
        return res;          
    }
};
