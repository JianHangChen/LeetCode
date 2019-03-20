class Solution:
    
    # sol1, my, two sets, O(m+n), O(m+n)
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        res = []
        set1 = set(nums1)
        set2 = set(nums2)
        if len(set1) <len(set2):
            set1, set2 = set2, set1
        
        for i in set2:
            if i in set1:
                res.append(i)
                
        return res

    # sol2, from sol2, python built-in intersection
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list(set(nums1)&set(nums2))
    
    
    # follow-up question, from FB interview
# This is a Facebook interview question.
# They ask for the intersection, which has a trivial solution using a hash or a set.
# Then they ask you to solve it under these constraints:
# O(n) time and O(1) space.
# You are told the lists are sorted.
# Cases to take into consideration include:
# duplicates, negative values, single value lists, 0's, and empty list arguments.
# Other considerations might include
# sparse arrays.
# by hasanseirafi

function intersections(l1, l2) {
    l1.sort((a, b) => a - b) // assume sorted
    l2.sort((a, b) => a - b) // assume sorted
    const intersections = []
    let l = 0, r = 0;
    while ((l2[l] && l1[r]) !== undefined) {
       const left = l1[r], right = l2[l];
        if (right === left) {
            intersections.push(right)
            while (left === l1[r]) r++;
            while (right === l2[l]) l++;
            continue;
        }
        if (right > left) while (left === l1[r]) r++;
         else while (right === l2[l]) l++;
        
    }
    return intersections;
}

    
