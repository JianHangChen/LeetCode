class Solution:
    """
    @param nums: The integer array.
    @param target: Target to find.
    @return: The first position of target. Position starts from 0.
    """
    def binarySearch(self, nums, target):
        low = 0
        high = len(nums) - 1
        
        while low < high:
            mid = low + (high - low) // 2
            if nums[mid] >= target:
                high = mid
            else:
                low = mid + 1
        if nums and nums[low] == target:
            return low
        else:
            return -1
