


// https://leetcode.com/discuss/interview-question/861453/amazon-oa-2020-items-in-containers

// !!! sol2, O(S+N), O(S+N), linear
// from harshsodi
/*
      0 1 2 3 4 5 6 7 8 9
      * * | * * * | * * *
left -1-1 2 2 2 2 6 6 6 6
right 2 2 2 6 6 6 6-1-1-1
star  1 2 2 3 4 5 5 6 7 8
*/
vector<int> numberOfItems(string s, vector<int>& startindices, vector<int>& endindices){
    int l = s.size(), n = startindices.size();
    vector<int> res(n);
    vector<int> left(l), right(l), star(l);
    int pre_left = -1, post_right = -1, cum = 0;
    for(int i = 0; i < l; i++){
        if(s[i] == '|') pre_left = i;
        left[i] = pre_left;
    }
    for(int i = l - 1; i >= 0; i--){
        if(s[i] == '|') post_right = i;
        right[i] = post_right;
    }
    for(int i = 0; i < l; i++){
        if(s[i] == '*') cum++;
        star[i] = cum; 
    }
    for(int i = 0; i < n; i++){
        int start = startindices[i] - 1, end = endindices[i] - 1;
        int a = right[start], b = left[end];
        if(a >=b ) res[i] = 0;
        else res[i] = star[b] - star[a];
    }
    return res;
};


//sol1, binary search O(S+NlogS), O(S)   S means how many '|' in the string, the worst case the the string length, N is the indices number

vector<int> numberOfItems(string s, vector<int>& startindices, vector<int>& endindices){
    int l = s.size(), n = startindices.size();
    vector<int> res(n);
    int cum = 0;
    vector<int> idxs, cum_star;
    for(int i = 0; i < l; i++){
        if(s[i] == '|'){
            cum_star.push_back(cum);
            idxs.push_back(i);
        }
        else{
            cum++;
        }
    }
    
    for(int i = 0; i < n; i++){
        int start = startindices[i] - 1, end = endindices[i] - 1;
        int a = lower_bound(idxs.begin(), idxs.end(), start) - idxs.begin();
        int b = upper_bound(idxs.begin(), idxs.end(), end) - idxs.begin() - 1;
        if(a > b) res[i] = 0;
        else res[i] = cum_star[b] - cum_star[a];
    }
    return res;        
}



int main(){
    vector<string> s = {"|**|*|*", "*|*|", "*|*|*|", "|**|***|*|****|", "|**|*|***", "***|**|*" };
    vector<vector<int>> startIndices = {{1, 1}, {1}, {1},{9, 5}, {1,1}, {1} };
    vector<vector<int>> endIndices = {{5, 6}, {3}, {6}, {15, 14}, {7,8}, {3}};    
    
    for(int k = 0; k < s.size(); k++){
        vector<int> res = numberOfItems(s[k], startIndices[k], endIndices[k]);
        for(int i = 0; i < res.size(); i++) cout << res[i] << " , ";
        cout << endl;
    }
    
    
    // return -1;
}
