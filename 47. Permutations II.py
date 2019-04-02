# sol1: iteratively
def permuteUnique(self, nums: List[int]) -> List[List[int]]:
    ans = [[]]
    for num in nums:
        new_ans = []
        for item in ans:
            for i in range(len(item), -1, -1):
                new_ans.append(item[:i] + [num] + item[i:])
                if i > 0 and num == item[i-1]: break
        ans = new_ans

    return ans

# sol2, dfs
# test nums=[], nums = None
def permuteUnique(self, nums: List[int]) -> List[List[int]]:
    ans = []

    def dfs(nums, item):
        if nums == []:
            ans.append(item)
        else:
            for i in range(len(nums)):
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                dfs(nums[:i]+nums[i+1:],item + [nums[i]])
    if nums:
        dfs(sorted(nums),[])
    return ans
