class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        # sol1: DP using a tableau
        # 典型的DP题目
        # 第一个想法可能是 tableau中存着 “从0 到 i 为止的subarray 的最大和”
        # 不过这样子就无法实现DP中上一个结果i-1对于下一个i有什么帮助
        # 在这题中，tableau中存着 “从0 到 i 为止 含有i的 subarray 的最大和”
        # 每次我们要计算 tableau[i]的时候， tableau[i-1]如果是正的，那么就存入tableau[i-1]+nums[i]，否则就只存入nums[i]
        # 得到tableau之后，求最大值即可得到答案
        
        length = len(nums)
        if length == 0:
            return 0
        table = [None]*length
        table[0] = nums[0]
        for i in range(1,length):
            if table[i-1] < 0:
                table[i] = nums[i]
            else:
                table[i] = table[i-1] + nums[i]
        return max(table)
        
        sol2: DP, modify from sol2. no need for a tableau
        length = len(nums)
        if length == 0:
            return 0
        cur_val = max_val = nums[0]
        for num in nums[1:]:
            if cur_val < 0:
                cur_val = num
            else:
                cur_val += num
            if cur_val > max_val:
                max_val = cur_val
        return max_val
        
        #sol3: prefix sum 
        if not nums:
            return 0
        presum = minsum = 0
        maxsub = -sys.maxsize
        for num in nums:
            presum += num
            maxsub = max(maxsub, presum - minsum)
            minsum = min(minsum, presum)
        return maxsub
        
        sol4: divide and conquer:
        # 我个人不是很喜欢这个方法
        #l_max # maximum sum contains left
        #r_max # maximum sum contains right
        #s # sum
        #sub_max # maximum sub array
        
        l_max, r_max, s, sub_max = self.divide(nums)
        return sub_max
    
    def divide(self, nums):
        length = len(nums)
        if length == 1:
            return nums[0],nums[0],nums[0],nums[0]
        mid = length//2
        l_max1, r_max1, s1, sub_max1 = self.divide(nums[:mid])
        l_max2, r_max2, s2, sub_max2 = self.divide(nums[mid:])
        l_max = max(l_max1, s1 + l_max2)
        r_max = max(r_max2, s2 + r_max1)
        s = s1 + s2
        sub_max = max(sub_max1, sub_max2, r_max1 + l_max2)
        return l_max, r_max, s, sub_max
    
    
        
        
