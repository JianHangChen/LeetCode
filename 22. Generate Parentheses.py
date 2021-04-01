//!!! sol1, my backtracking, O( C(2n, n) / (n+1) ), around O(4^n / sqrt(n)), O(4^n/sqrt(n))
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n){       
        string path = "";
        dfs(path, n, n);
        return res;
    }
    void dfs(string path, int left, int right){ // left left, and right left
        if(left > right) return;
        if(left == 0 && right == 0){
            res.push_back(path);
            return;
        }
        
        if(left > 0){
            dfs(path + '(', left-1, right);
        }
        if(right > 0){
            dfs(path + ')', left, right-1);
        }
    }
};


class Solution:   
    # sol1, brute force, check balance in real time
    
    def generateParenthesis(self, n: int) -> List[str]:

            
        def generate(A = [], balance  = 0):
            if len(A) == 2 * n:
                if balance == 0:
                    ans.append("".join(A) )
            else:
                A.append("(")
                balance += 1
                if balance <= n:
                    generate(A, balance)
                A.pop()
                balance -= 1
                
                A.append(")")
                balance -= 1
                if balance >= 0:
                    generate(A, balance)
                A.pop()
                balance += 1
        ans = []
        generate()
        return ans
    
    # !!!! sol3, backtracking
    # complexity: each number need step: catalan number: 1/(n+1)*C(2n,n) O(4^n/(n*sqrt(n)))
    # final complexity O(4^n/sqrt(n))
    # space O(4^n/sqrt(n))
    def generateParenthesis(self, n: int) -> List[str]:
        def backtracking(res = "", left = 0, right = 0):
            if len(res) == 2 * n:
                ans.append(res)
            else:
                if left < n:
                    backtracking(res+"(", left+1, right)
                if right < left:
                    backtracking(res+")", left, right+1)
            
        ans = []
        backtracking()
        return ans
    
    # sol3, closure number
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return [""]
        ans = []
        for c in range(n):
            for left in self.generateParenthesis(c):
                for right in self.generateParenthesis(n-1-c):
                    ans.append("({}){}".format(left,right))
        
        return ans
            
            
            
        

    
