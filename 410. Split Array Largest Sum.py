 #binary search 

def splitArray(self, nums: List[int], m: int) -> int:
    def issplit(mid, m): # return if the nums can be split into m pieces where sum(piece) <= mid for every piece
        count = 0
        cur_sum = 0
        for i in range(len(nums)):

            cur_sum += nums[i]
            if cur_sum > mid:
                cur_sum = nums[i]
                count += 1

                if count == m:
                    return False


        return True




    l = max(nums)
    r = sum(nums)

    while l < r:
        mid = l + (r - l) // 2
        if issplit(mid, m):
            r = mid
        else:
            l = mid + 1

    return l
