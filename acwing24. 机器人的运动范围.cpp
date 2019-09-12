//dfs
class Solution {
private:
    vector<int> di = {0, 0, 1, -1};
    vector<int> dj = {1,-1, 0, 0};
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows == 0 || cols == 0) return 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        
        return dfs(0, 0, rows, cols, visited, threshold);
    }
    
    int dfs(int i, int j, int rows, int cols, vector<vector<bool>>& visited, int threshold){
        int count = 1;
        visited[i][j] = true;
        
        for(int k = 0; k < 4; k++){
            int x = i + di[k], y = j + dj[k];
            if(x < rows && x >= 0 && y < cols && y >= 0 && !visited[x][y] && getSum(x) + getSum(y) <= threshold){
                count += dfs(x, y, rows, cols, visited, threshold);
            }
        }
        return count;
    }

    
    int getSum(int num){
        int s = 0;
        while(num){
            s += num % 10;
            num /= 10;
        }
        return s;
    }
};


//sol1 bfs!!!
class Solution {
private:
    

public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows == 0 || cols == 0) return 0;
        int count = 0;
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));
        
        vector<int> di = {0, 0, 1, -1};
        vector<int> dj = {1,-1, 0, 0};
        queue<vector<int>> q( { {0,0} } );
        
        
        
        while(!q.empty()){
            vector<int> cur = q.front(); q.pop();
            if(visited[cur[0]][cur[1]] || getSum(cur[0]) + getSum(cur[1]) > threshold) continue;
            visited[cur[0]][cur[1]] = true;
            count++;
            
            for(int k = 0; k < 4; k++){
                int i = cur[0] + di[k];
                int j = cur[1] + dj[k];
                
                if(i >= 0 && i < rows && j >= 0 && j < cols)
                    q.push({i,j});
            }

        }

        return count;
    }
    

    
    int getSum(int num){
        int s = 0;
        while(num){
            s += num % 10;
            num /= 10;
        }
        return s;
    }
};
