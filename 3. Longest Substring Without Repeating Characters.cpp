
    
// !!!!!!!sol1, my, two pointer, O(n), O(1), but this O(n) is slower
class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int i = 0, j = 0;
        int res = 1;
        vector<int> count(256, 0);
        while(j < n && i < n){ // [i, j] included
            char c = s[j];
            count[c]++;
            while(count[c] > 1){
                count[s[i++]]--;
            }
            res = max(res, j - i + 1);
            j++;
        }
        return res;
    }
};
    
//!sol2, index storage
// class Solution {
// public:

//     int lengthOfLongestSubstring(string s) {
//         int n = s.size();
//     	int max_l = 0;
//     	int cur_start = -1;
//     	int i = 0;
//         int cur_len = 0;

//     	int a[256];
//     	memset( a, -1, sizeof(a) );
        
//     	while(i < n){
//             if(a[s[i]] > cur_start){
//                 cur_start = a[s[i]];
//             }
//     		cur_len = i - cur_start;
//             a[s[i]] = i;
            

//     		max_l = max(max_l, cur_len);
//     		i++;
//     	}
//     	return max_l;  
//     }

// };
