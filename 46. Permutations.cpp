
/// !!! my backtracking, repeat sol1.1, between O(n!)  and O(n*n!),  space O(n!)
//n + n(n-1) + ... + n!   =  C(n, 1) + C(n,2) + ...C(n, n) = sum( n!/(n-k)! ) = 
class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res;    
        permute(0, nums, res);
        return res;
    }

    void permute(int level, vector<int>& nums, vector<vector<int>>& res){
        if(level + 1 == nums.size()){
            res.push_back(nums);
            return;
        }
        
        for(int i = level; i < nums.size(); i++){
            swap(nums[level], nums[i]);
            permute(level+1, nums, res);
            swap(nums[level], nums[i]);
        }
    }
    
};


// !!! my the same as sol2,  space O(n!)
// (sum[(n)! * n] ) -> better than (n^2*n!), worse than O(n! * n)

// (n - 1)! * n^2
// [1 ... , n -1]
// for 1, O(n-1)
// for2, O(n-2)
// for(n-1), O(0)
// n - 1 + ... + 1 -> O(n^2)
class Solution{
public:
  vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> res = {{}}, tmp;
    int n = nums.size();
    if(n == 0) return {};

    for(int i = 0; i < n; i++){
      for(auto& v:res){
        for(int j = 0; j <= v.size(); j++){
          vector<int> ele = v;
          ele.insert(ele.begin() + j, nums[i]);
          tmp.push_back(ele);
        }
      }
      res = tmp;
      tmp.clear();
    }
    return res;
  }

};



// ! sol3, from gy3, recursively

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        if(nums.size() == 0) return {{}};
        vector<vector<int>> res;
        int back = nums.back(); nums.pop_back();
        vector<vector<int>> front_permute = permute(nums);
        for(auto v:front_permute){
            for(int i = 0; i < v.size() + 1; i++){
                v.insert(v.begin() + i, back);
                res.push_back(v);
                v.erase(v.begin() + i);
            }
        }
        return res;

    }
};

// !!! sol2, form gy4, iteratively

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res({{}}), res_new;
        for(int i = 0; i < nums.size(); i++){
            for(vector<int> v:res){
                for(int j = 0; j < v.size() + 1; j++){
                    v.insert(v.begin() + j, nums[i]);   //!!! insert
                    res_new.push_back(v);
                    v.erase(v.begin() + j);    //!! backtracking here
                }

            }
            res = res_new; res_new.clear();
        }
        return res;
    }
};

// !!! sol1.1, dfs, backtracking , from gy2, no need to use v
// between O(n!)  and O(n*n!),  space O(n!)

class Solution{
public:
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> res;
        permute(0, nums, res);
        return res;
    }
    void permute(int level, vector<int>& nums, vector<vector<int>>& res){
        if(level == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = level; i < nums.size(); i++){
            swap(nums[level], nums[i]);
            permute(level + 1, nums, res);
            swap(nums[level], nums[i]);
        }
        return;
    }
};

// sol1, from gy1, dfs, backtracking   , between O(n!)  and O(n*n!),  space O(n!)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> visited(nums.size(), false);
        vector<int> v;
        permute(nums, 0, visited, res, v);
        return res;
    }
    void permute(vector<int>& nums, int level, vector<bool>& visited, vector<vector<int>>& res, vector<int>& v){
        if(level == nums.size()){
            res.push_back(v);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if( !visited[i] ){
                visited[i] = true; v.push_back(nums[i]);
                permute(nums, level + 1, visited, res, v);
                visited[i] = false; v.pop_back();
            }
        }
    }
};





class Solution:
    
    # test [], [1], [1,2]
    # sol1, iteratively 
    # 将数字插入数组中的 0, 1, .., 的某个位置得到新数组

    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = [[]]
        
        for num in nums:
            new_ans = []
            for item in ans:
                for i in range(len(item) + 1):
                    new_ans.append( item[:i] + [num] + item[i:] )
            ans = new_ans
            
        return ans
    
    # sol2, DFS
    # 随机抽出nums剩下数组的某个数nums[i]，插入到item数组的固定（最前或者最后）位置

    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(nums, item, ans):
            if nums == []:
                ans.append(item)
            else:
                for i in range(len(nums)):
                    dfs(nums[:i]+nums[i+1:], item+[nums[i]], ans)
        ans = []
        dfs(nums, [], ans)
        return ans
    
    # sol3.1 奇技淫巧. from Stefan
    # 将第一个数随机插入permuted 数组中

    def permute(self, nums: List[int]) -> List[List[int]]:
        return nums and [ p[:i]+[nums[0]]+p[i:] for p in self.permute(nums[1:]) for i in range(len(p)+1) ] or [[]]
    
    # sol3.2
    # 随机找一个数作为第一个，将剩下的数permute
    def permute(self, nums: List[int]) -> List[List[int]]:
        return [[nums[i]] + p for i in range(len(nums)) for p in self.permute(nums[:i]+nums[i+1:])] or [[]]
    
    # sol3.3
    # 趁机复习一下reduce的用法
    from functools import reduce
    def permute(self, nums: List[int]) -> List[List[int]]:
        return reduce(lambda P, n: [p[:i] + [n] + p[i:] for p in P for i in range(len(p)+1)], nums,[[]])
    
    # sol3.4
    # 复习一下library
    def permute(self, nums:List[int]) -> List[List[int]]:
        return list(map(list, itertools.permutations(nums)))
        
        
        
