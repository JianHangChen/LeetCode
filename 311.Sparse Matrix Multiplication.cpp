   
    // sol1
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        int m = A.size(), n, q;
        if(m > 0) n = A[0].size();
        if(m == 0 || n == 0 ) return {{}};
        q = B[0].size();
        if(q == 0) return {{}};
        
        
        vector<vector<int>> ans(m, vector<int> (q,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(A[i][j] != 0){
                    for(int k= 0; k < q; k++){
                        if(B[j][k] != 0){
                            ans[i][k] += A[i][j] * B[j][k];
                        }
                    }
                }
                
            }
        }
        return ans;
    }

    // sol2, stupid
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        int m = A.size(), n, q;
        if(m > 0) n = A[0].size();
        if(m == 0 || n == 0 ) return {{}};
        q = B[0].size();
        if(q == 0) return {{}};
        
        vector<vector<int>> res(m, vector<int> (q,0));
        vector< vector< pair<int, int> > > non_zero_A(m);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if( A[i][j] != 0 ){
                    non_zero_A[i].push_back({j, A[i][j]});
                }
            }
        }
        int col, val;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < non_zero_A[i].size(); j++){
                col = non_zero_A[i][j].first;
                val = non_zero_A[i][j].second;
                for(int k = 0; k < q; k++){
                    if(B[col][k] != 0){
                        res[i][k] += val * B[col][k];
                    }
                }
            }
        }
        return res;
    }
