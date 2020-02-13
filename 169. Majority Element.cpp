//boyer-moore voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
 

        int count = 0, cur = -1;

        for(int i = 0; i < nums.size(); i++){
          if(count == 0){
            cur = nums[i];
            count++;
          }
          else{
            if(cur == nums[i]){
              count++;
            }
            else{
              count--;
            }
          }
        }

        return cur;

    }
};


def majorityElement(self, nums):

    #!!!!!!!! sol1 hash, O(n), O(n)
    mid = len(nums)//2
    table = {}
    for num in nums:
        if num not in table:
            table[num] = 1
        else:
            table[num] += 1
        if table[num] > mid:
            return num

    #sol1.1 hash, counter
    counts = collections.Counter(nums)
    # return max(counts.keys(), key = counts.get)

    mid = len(nums)//2
    for num, c in counts.items():
        if c > mid:
            return num

    #sol2, sort, O(nlogn), O(1)
    
    n = len(nums)
    nums = sorted(nums)
    return nums[n//2]

    #sol3, randomize, O(inf) but average less than 2 iteration

    mid = len(nums)//2
    while True:
        candidate = random.choice(nums) #!!!
        res = sum(1 for num in nums if num == candidate) #!!!
        if res > mid:
            return candidate

    #sol4, divide and conquer O(nlogn), space O(logn)

    def divide(nums, lo, hi):
        if lo == hi:
            return nums[lo]

        mid = (hi-lo)//2 + lo
        left = divide(nums,lo,mid)
        right = divide(nums,mid+1,hi)
        if left == right:
            return left
        else:
            left_count = sum(1 for i in range(lo, hi+1) if nums[i] == left)
            right_count = sum(1 for i in range(lo, hi+1) if nums[i] == right)
            if left_count > right_count:
                return left
            else:
                return right

    return divide(nums, 0, len(nums)-1)


    #!!!!!! sol5, Boyer-Moore Voting Algorithm, O(n), O(1)
    n = len(nums)
    count = 0
    for i in range(n):
        if count == 0:
            cur = nums[i]
            count = 1
        else:
            if cur == nums[i]:
                count += 1
            else:
                count -= 1
    return cur
