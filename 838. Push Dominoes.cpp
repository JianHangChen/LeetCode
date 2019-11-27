// sol4, from gy2, rank from which direction.
class Solution{
public:
    string pushDominoes(string state){
        int n = state.size(); int cur;
        vector<int> rank(n, 0);

        for(int i = 1; i < n; i++){
            if(state[i-1] == 'R' && state[i] == '.'){
                state[i] = 'R';
                rank[i] = rank[i-1] + 1;
            }
        }

        for(int i = n - 2; i >= 0; i--){
            if(state[i+1] == 'L'){
                cur = rank[i+1] + 1;
                if(state[i] == '.' || state[i] == 'R' && rank[i] > cur){
                    state[i] = 'L';
                    rank[i] = cur;
                }
                else if(state[i] == 'R' && rank[i] == cur){
                    state[i] = '.';
                }
            }
        }
        return state;
    }
};


// !!!! sol3,  from gy1
class Solution{
public:
    string pushDominoes(string state){
        state = "L" + state + "R";
        int i = 0, j = 1;

        while(i < state.size() && j < state.size()){
            if( state[j] == '.'){
                j++;
            }else{
                if(state[i] == 'L' && state[j] == 'L' || state[i] == 'R' && state[j] == 'R'){
                    for(int k = i + 1; k < j; k++){
                        state[k] = state[i];
                    }
                }
 
                else if(state[i] == 'R' && state[j] == 'L'){
                    int i_right, j_left;
                    if( ( j - i) % 2 == 0 ){ // R.L
                        i_right = i + (j - i) / 2 - 1;
                    }
                    else{          // R....L
                        i_right = i + (j - i) / 2;
                    }
                    j_left = i + (j - i) / 2 + 1;
                    for(int k = i + 1; k <= i_right; k++){
                            state[k] = 'R';
                    }
                    for(int k = j_left; k < j; k++){
                        state[k] = 'L';
                    }
                }
                i = j; j++;
            }
        }
        return state.substr(1, state.size() - 2);
    }
};

// sol2, my, queue for changes , O(n)
class Solution {
public:

    string pushDominoes(string state){

        int n = state.size();
        queue<int> q; string ans = state;
        for(int i = 0; i < n; i++){
            if(state[i] == 'R' || state[i] == 'L') q.push(i);
        }


        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){
                 int idx = q.front(); q.pop();
                 if(state[idx] == 'R'){
                    if( idx + 1 < n && state[idx+1] == '.'){
                        if(idx + 2 >= n || state[idx+2] != 'L'){
                            ans[idx+1] = 'R';
                            q.push(idx+1);
                        }
                    }
                }
                else if(state[idx] == 'L'){
                    if(idx - 1 >= 0 && state[idx-1] == '.'){
                        if(idx - 2 < 0 || state[idx-2] != 'R'){
                            ans[idx-1] = 'L';
                            q.push(idx-1);
                        }
                    }
                }
            }
            state = ans;
        }
        return ans;
    }
};

 // sol1, my dfs, very slow , O(n^2)
class Solution {
public:

    string pushDominoes(string state){

        int n = state.size();
        string ans = state;
        bool change = false;
        for(int i = 0; i < n; i++){
            if(state[i] == 'R'){
                if( i + 1 < n && state[i+1] == '.'){
                    if(i + 2 >= n || state[i+2] != 'L'){
                        ans[i+1] = 'R';
                        change = true;
                    }
                }
            }
            else if(state[i] == 'L'){
                if(i - 1 >= 0 && state[i-1] == '.'){
                    if(i - 2 < 0 || state[i-2] != 'R'){
                        ans[i-1] = 'L';
                        change = true;
                    }
                }
            }
        }
        if(change) return pushDominoes(ans);
        else return ans;
    }

};
