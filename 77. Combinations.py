//!! sol1, my, dfs
// [1 2 3 4]
// O(kC[n, k])
// O(C[n, k])

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb = {};
        select(res, comb, n, k, 1);
        return res;
    }
    void select(vector<vector<int>>& res, vector<int>& comb, int n, int k, int start){
        if(comb.size() == k){
            res.push_back(comb);
            return;
        }
        for(int i = start; i <= n; i++){
            comb.push_back(i);
            select(res, comb, n, k, i+1);
            comb.pop_back();
        }
    }
};


class Solution:
    # sol 1, recursive
    def combine(self, n: int, k: int) -> List[List[int]]:
        def helpler(start, k):
            if k == 0:
                return [[]]
            else:
                res = []
                for i in range(start, n - k + 2):
                    for item in helpler( i + 1, k - 1):
                        res.append([i] + item)
            return res
        
        return helpler(1, k)
        

    
    
    # sol2, dfs, iterativley
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = [[i] for i in range(1, n+1)]
        k -= 1
        while k:
            new_res = []
            for item in res:
                for j in range( item[-1]+1, n - k + 2):
                    new_res.append( item + [j] ) 
        
            res = new_res
            k -= 1
        return res

    
    # sol3, backtracking
    def combine(self, n: int, k: int) -> List[List[int]]:
        stack = []
        res = []
        
        i = 1
        
        while True:
            if len(stack) == k:
                res.append(stack[:]) #!!careful
            if len(stack) == k or k - len(stack) > n - i + 1: # has less candidate than we need
                if not stack:
                    return res
                i = stack.pop() + 1
                
            else:
                stack.append(i)
                i += 1
               
