// sol2, !!!! true O(n), O(1)
// skip method

// Yes, it's amortized because each calculation should be O(1) average. The important thing to note is that the moment you traverse a bunch of temperatures to search for the largest temp, you make traversals that can never be crossed again. Any temperature less than the current one will just stop at that, and any temperature larger will still hit that current one and then jump across all the indices you've already traversed. So it's O(2n) total
// Time Complexity: Even though the number of steps to jump (while loop) is NOT a constant, note that each element in a 'valley' will be accessed at most twice thanks to the leaps (consider the example T=[5,4,5,1,2,3,4,6]), the algorithm essentially only keeps the monotonely increasing part of the original sequence. Thus the complexity is O(n).

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T){
        int n = T.size();
        vector<int> res(n, 0);
        
        for(int i = n - 1; i >= 0; i--){
            int j = i+1;
            while(j < n){
                if(T[i] < T[j]){
                    res[i] = j - i;
                    break;
                }
                else{
                    if(res[j] == 0) break;
                    j = j + res[j];
                }
            }
        } 
        return res;        
    }
};

//sol3, ! use stack, decreasing stack , from grandyang
// O(n), O(w)

// class Solution{
// public:
//     vector<int> dailyTemperatures(vector<int> & T){
//         int n = T.size();
//         stack<int> st;
//         vector<int> res(n, 0);
        
//         for(int i = 0; i < n; i++){
//             while(!st.empty() && T[st.top()] < T[i]){
//                 int j = st.top(); st.pop();
//                 res[j] = i - j;
//             }

//             st.push(i);
            
//         }
//         return res;        
//     }
// };

// sol1, my O(nw), O(w)
// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int>& T) {
//         int n = T.size();
//         vector<int> pos(101, -1);
//         vector<int> res(n, 0);
        
        
//         for(int i = n-1; i >= 0; i--){
//             pos[T[i]] = i;
            
//             for(int temp = T[i] + 1; temp <= 100; temp++){
//                 if(pos[temp] != -1){
//                     if(res[i] == 0) res[i] = pos[temp] - i;
//                     else res[i] = min(res[i], pos[temp] - i); 
//                 }    
//             }
//         }
//         return res;
        
//     }
// };



class Solution:
    # sol1, O(n) no need to use stack
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        l = len(T)
        res = [0] * l
        for i in range(l - 1, -1, -1):
            j = i + 1
            while j <= l - 1:
                if T[i] < T[j]:
                    res[i] = j - i
                    break
                else:
                    if res[j] == 0:
                        break
                    j = j + res[j]
        return res        
    
    # sol2, next array, O(NW), here W = 102-31=71
    # from sol1 in answer
    
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        n = len(T)
        ans = [0] * n
        nxt = [sys.maxsize]*72
        for i in range(n - 1, -1, -1):
            
            idx = min(nxt[j-30] for j in range(T[i]+1, 102))
            if idx != sys.maxsize:
                ans[i] = idx - i
            nxt[T[i] - 30] = i
        
        return ans
    
    # sol3, stack O(n), O(W)
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        l = len(T)
        res = [0] * l
        stack = []
        for i in range(l):
            while stack and T[i] > T[stack[-1]]:
                cur = stack.pop()
                res[cur] = i - cur
            stack.append(i)
        return res
