

// !!!! sol1, get segmentation (Left, right) for each character, sort and combine the segmentations  
// from ch9
class Solution {
public:
    int getLongestScene(string &str) {
        int n = str.size();
        vector<vector<int>> seg(26, vector<int> ({n, -1}));
        
        for(int i = 0; i < n; i++){
            seg[str[i]-'a'][0] = min( seg[str[i]-'a'][0], i);
            seg[str[i]-'a'][1] = max( seg[str[i]-'a'][1], i);
        }
        sort(seg.begin(), seg.end());
        int L = seg[0][0], R = seg[0][1];
        int max_len = R - L + 1;
        for(int i = 1; i < 26; i++){
            
            if( seg[i][0] <= R){
                R = max(R, seg[i][1]);
            }
            else{
                L = seg[i][0];
                R = seg[i][1];
            }
            max_len = max(max_len, R - L + 1);
        }
        
        return max_len;
        
    }
};
