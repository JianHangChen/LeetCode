# presum+hash
  def subarraySum(self, nums):
      if nums == []:
          return
      table = {0:-1}
      presum = 0
      for i in range(len(nums)):
          presum += nums[i]
          if presum in table:
              return [table[presum] + 1,i]
          table[presum] = i
