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
        
        
        
