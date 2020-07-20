// sol2, dfs, from 9ch sol1

class Solution {
public:

    int dfs(int idx, int step, string& str, vector<bool>& exist, int n){
        if(idx >= str.size()){
            if(step == n - 1){ // get the answer
                for(int i = 1; i <= n; i++){
                    if(!exist[i]) return i;
                }
            }
            else{
                return 0;
            }
        }
        
        int candidate = 0;
        for(int i = 0; i < 2; i++){
            int cur_idx = idx + i;
            if(cur_idx >= str.size()) return 0;
            int digit = str[cur_idx] - '0';
            
            candidate = candidate * 10 + digit;
            
            if(candidate == 0 || candidate > n) return 0;
            if(exist[candidate]) continue;
            
            exist[candidate] = true;
            int ans = dfs(cur_idx + 1, step+1, str, exist, n);
            if(ans != 0) return ans;
            exist[candidate] = false;
            
        }
        return 0;
        
    }
    
    int findMissing2(int n, string &str) {
        vector<bool> exist(n+1, false);
        return dfs(0, 0, str, exist, n);
        
    }
   
}; 


// my sol1, not working, get the candidate digit, but fail in case like 12 or 21
// class Solution {
// public:
//     int findMissing2(int n, string &str) {
//         vector<int> count(10,0);
        
//         for(int i = 1; i <= n; i++){
//             int j = i;
//             while(j > 0){
//                 count[j % 10]++;
//                 j /= 10;
//             }
//         }
        
//         for(char c:str){
//             count[c - '0']--;
//         }
        
//         int digit = 0;
//         for(int i = 0; i < 10; i++) digit += count[i];
//         if(digit == 1){
//             for(int i = 0; i < 10; i++){
//                 if(count[i] != 0) return i;
//             }
//         }
//         else{
//             int ans = 0;
//             for(int i = 0; i < 10; i++){
//                 if(count[i] != 0){
//                     count[i]--;
//                     ans += i * 10;
//                     break;
//                 }
//             }
//             for(int i = 0; i < 10; i++){
//                 if(count[i] != 0){
//                     ans += i;
//                     return ans;
//                 }
//             }
            
            
//         }
        
//         return -1;
//     }
// };
