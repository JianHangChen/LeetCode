//!!! my, O(n), O(1) Boyer-Moore Voting Algorithm

// take example:
// 1 1 1 2 2 3 4 5 2 2 1 1 2    (13 numbers, 5 1, 5 2, 1 3, 1 4, 1 5)
//idx == 2: (3 1) (0 0)
//idx == 3: (3 1) (1 2)
//idx == 4: (3 1) (2 2)
// 1 1 1 2 2 3 | 4 5 2 2 1 1 2
//idx == 5: (2 1) (1 2)   // meet 3, propotionally delete 1/3 of number: 1, 2 and 3, now the kings are 1 and 2
// 1 1 1 2 2 3 4 | 5 2 2 1 1 2
//idx == 6: (1 1) (0 2)   // meet 4, propotionally delete 1/3 of number: 1, 2 and 4, now the king is 1
//idx == 7: (1 1) (1 5)   // meet 5, now the kings are 1 and 5

//1 1 1 2 2 3 4 5 2 | 2 1 1 2
//idx == 8: (0 1) (0 1)   // meet 2, propotionally delete 1/3 of number: 1, 5, and 2, no king



class Solution {
public:
    vector<int> majorityElement(vector<int>& nums){
        int n = nums.size();
        int first, first_count = 0, second, second_count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == first){
                first_count++;
            }
            else if(nums[i] == second){
                second_count++;
            }
            else if(first_count == 0){
                first = nums[i]; first_count = 1;
            }
            else if(second_count == 0){
                second = nums[i]; second_count = 1;
            }
            else{
                first_count--;
                second_count--;
            }    
        }
        vector<int> res;
        first_count = 0; second_count = 0;
        for(int i = 0; i < n; i++){
            if( nums[i] == first) first_count++;
            else if(nums[i] == second) second_count++;
        }
        if(first_count > n / 3) res.push_back(first);
        if(second_count > n / 3) res.push_back(second);
        return res;

    }

};



// very good explanation

// And also here is a real generalized solution, where you could change K to any number and it will still work

// class Solution {
//     public List<Integer> majorityElement(int[] nums) {
//         int k = 3;
//         int targetFreq = nums.length / k;
//         Map<Integer, Integer> kCounters = new HashMap();
//         Map<Integer, Integer> freq = new HashMap();
//         // 1st pass to build kCounters and freq
//         for (int num : nums) {
//             // update freq
//             freq.put(num, freq.getOrDefault(num, 0) + 1);
//             // update kCounters
//             if (kCounters.containsKey(num) || kCounters.size() < k) {
//                 kCounters.put(num, kCounters.getOrDefault(num, 0) + 1);
//             } else {
//                 // decrease all other keys, erase them if count falls to zero
//                 Set<Integer> keySet = new HashSet(kCounters.keySet()); // has to use a separate set to avoid ConcurrentModificationException
//                 for (int candidate : keySet) {
//                     kCounters.put(candidate, kCounters.get(candidate) - 1);
//                     if (kCounters.get(candidate) == 0) kCounters.remove(candidate); 
//                 } 
//             }
//         }
//         // 2nd pass to get valid candidates
//         List<Integer> majorities = new ArrayList();
//         for (int candidate : kCounters.keySet()) {
//             if (freq.get(candidate) > targetFreq) majorities.add(candidate);
//         }
//         return majorities;
//     }
// }
