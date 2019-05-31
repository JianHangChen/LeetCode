 DP
class Solution {
private:
	unordered_map<int, vector<int>> direction = {
		{0,{1,0}},
		{1,{-1,0}},
		{2,{0, 1}},
		{3,{0, -1}}
	};

	int m, n;
public:
    /**
     * @param grid: Given a 2D grid, each cell is either 'W', 'E' or '0'
     * @return: an integer, the maximum enemies you can kill using one bomb
     */
    int maxKilledEnemies(vector<vector<char>> &grid) {




        int res = 0;

        // set m, n
        m = grid.size();
        if(m > 0){
        	n = grid[0].size();
        }
        else{
        	return 0;
        }

        int dp[m][n][4];

        //from top-left to bottom-right direction 1,3


        for(int i = 0; i < m; i++){
       		for(int j = 0; j < n; j++){

       			vector<int> top_left = {3, 1};

       			for(auto dir:top_left){
       				int i_ = i + direction[dir][0];
       				int j_ = j + direction[dir][1];

       				if(i_ >= m || i_ < 0 || j_ >= n || j_ < 0 || grid[i_][j_] == 'W' ){ //hit a "W" or out of boundary
       					dp[i][j][dir] = 0;
       				}
       				else if(grid[i_][j_] == '0'){
       					dp[i][j][dir] = dp[i_][j_][dir];
       				}
       				else{  // "E"
       					dp[i][j][dir] = dp[i_][j_][dir] + 1;
       				}

       			}
       		}
        }

        for(int i = m - 1; i >= 0; i--){
       		for(int j = n - 1; j >= 0; j--){

    			vector<int> bottom_right = {2, 0};

       			for(auto dir:bottom_right){
       				int i_ = i + direction[dir][0];
       				int j_ = j + direction[dir][1];

       				if(i_ >= m || i_ < 0 || j_ >= n || j_ < 0 || grid[i_][j_] == 'W' ){ //hit a "W" or out of boundary
       					dp[i][j][dir] = 0;
       				}
       				else if(grid[i_][j_] == '0'){
       					dp[i][j][dir] = dp[i_][j_][dir];
       				}
       				else{  // "E"
       					dp[i][j][dir] = dp[i_][j_][dir] + 1;
       				}
       			}    


       		}
        }

        for(int i = 0; i < m; i++){
       		for(int j = 0; j < n; j++){

       			if(grid[i][j] == '0'){
       				int sum = 0;
       				for(auto& ele:dp[i][j]){
       					sum += ele;
       				}
       				res = max(sum, res);
       			}

       		}
       	}

       			
        return res;

    }

};
