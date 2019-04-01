
    # sol1
def nextPermutation(self, nums: List[int]) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    def swap(i,j):
        nums[i],nums[j] = nums[j],nums[i]

    def reverse(i):
        for k in range(i,i + (len(nums) - i)//2):
            swap(k, i + len(nums) - 1 - k)


    i = len(nums) - 1
    while i > 0:
        if nums[i-1] < nums[i]:
            j = i
            while j < len(nums) - 1:
                if nums[j+1] <= nums[i-1]:
                    break
                j += 1
            swap(i-1, j)
            reverse(i)
            return
        else:
            i -= 1

    reverse(0)

                
