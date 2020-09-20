#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
#include <vector> 
#include <cmath> 
#include <iostream> 
#include <map> 
using namespace std; 


// https://www.hackerrank.com/challenges/minimum-operations/problem#:~:text=In%20this%20challenge%2C%20the%20task,green%20balls%2C%20and%20blue%20balls.
// expalin:
// The technique used is dp with bitmast. The keys to understand min_operations() is to understand what dp[i][j] means. j means what color balls are kept. If j=1, red balls are kept and the other color balls are moved. If j=2, green balls are kept and the other color balls are moved. If j=4, blue balls are kept and the other color balls are moved. If j=3, which is 1|2, either red or green balls are kept. If j=0, all color balls are moved, which means the basket is empty. i means up to i-th basket are separated. Then dp[3][1] represents the minimum operations that are required to separate up to 3rd basket and during the separation red balls are always kept. dp[3][3] means the minimum operations that are required to separate up to 3rd basket and during the separation, sometimes red balls are kept and sometimes green balls are kept. I hope this help you understand the code.

int min_operations(vector <int> red, vector <int> green, vector <int> blue) {
    int n = red.size();
    vector<vector<int>> dp(n+1, vector<int> (8, 1<<29));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 8; j++){
            dp[i+1][j|1] = min(dp[i+1][j|1], dp[i][j] + green[i] + blue[i]);
            dp[i+1][j|2] = min(dp[i+1][j|2], dp[i][j] + red[i] + blue[i]);
            dp[i+1][j|4] = min(dp[i+1][j|4], dp[i][j] + red[i] + green[i]);
        }
    }
    int final_colors = 0;
    for(int i = 0; i < n; i++){
        if(red[i]) final_colors |= 1;
        if(green[i]) final_colors |= 2;
        if(blue[i]) final_colors |= 4;
    }
    if( dp[n][final_colors] >= 1 << 29){
        dp[n][final_colors] = -1;
    }
    return dp[n][final_colors];
}

int main() {

    int n, r, g, b;
    cin >> n;
    vector<int> red, blue, green;

    for(int i = 0; i < n; i++){

        cin >> r >> g >> b;
        red.push_back(r);
        green.push_back(g);
        blue.push_back(b);
    }

    cout << min_operations(red, green, blue) << "\n";
    return 0;
}



