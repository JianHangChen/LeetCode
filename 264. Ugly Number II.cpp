

sol2, O(nlogn), O(n), use set
class Solution {
public:
    vector<int> primes = {2, 3, 5};
    int nthUglyNumber(int n) {
        unordered_set<long long> visited;
        set<long long> s;
        s.insert(1);
        long long cur;
        for(int i = 1; i <= n; i++){
            cur = *s.begin(); s.erase(s.begin());
            for(int p:primes){
                if(!visited.count(p*cur)) visited.insert(p*cur);
                s.insert(p*cur);
            }
        }
        return cur;

    }
};

//!!! sol1.1, O(n), O(n)
// 1 2 3 5
// 4 6 10 | 6 9 15 | 10 15 25
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n+1, 0);
        nums[1] = 1;
        vector<int> primes = {2, 3, 5};    
        vector<int> idxs = {1, 1, 1};
        for(int t = 2; t <= n; t++){
            int cur = INT_MAX;
            for(int i = 0; i < 3; i++){
                cur = min( cur,  nums[idxs[i]] * primes[i]); 
            }
            for(int i = 0; i < 3; i++){
                if(cur == nums[idxs[i]] * primes[i]){
                    idxs[i]++;
                }
            }
            nums[t] = cur;
        }
        return nums[n];
        
    }
};


sol1, O(n), O(n)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglys(1, 1);
        int i = 0, j = 0, k = 0;
        for(int t = 1; t < n; t++){
            int minUgly = min(uglys[i] * 2, min(uglys[j] * 3, uglys[k] * 5));
            if(minUgly == uglys[i] * 2){
                i++;
            }
            if(minUgly == uglys[j] * 3){
                j++;
            }
            if(minUgly == uglys[k] * 5){
                k++;
            }
            uglys.push_back(minUgly);
        }
        return uglys.back();
    }
};


class Solution:


# # sol1: time too long
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        num = 0
        i = 0
        while(i< n):
            num += 1
            if self.isUgly(num):
                i += 1
                print(i,num)
        return num
            

    def isUgly(self,num):
        if num <= 0:
            return False
        for i in [2,3,5]:
            while num % i == 0:
                num //= i
        return num == 1

    # sol2: sol1 update time too long
    def __init__(self):
        self.lookup = [1]
        
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        

        num = 0
        i = 0
        while(i< n):
            num += 1
            if self.isUgly(num):
                self.lookup.append(num)
                i += 1
                # print(i,num)
        return num
            

    def isUgly(self,num):
        if num <= 0:
            return False
        if num in self.lookup:
            return True
        
        for i in [2,3,5]:
            if num % i == 0:
                return self.isUgly(num // i)
        return False


# sol3: dynamic programing
# 这个解法的思路主要是每得到一个新的丑数再往后乘2, 3, 5都可以得到新的丑数，
# 但是问题主要是在于每个数*2，3，5得到的数的大小差距非常大。
# 所以要引入分别引入 2，3，5的index
# https://www.geeksforgeeks.org/ugly-numbers/
# Algorithmic Paradigm: Dynamic Programming
# Time Complexity: O(n)
# Auxiliary Space: O(n)
    
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        count = 1
        base = [2,3,5]
        factor = [0,0,0]
        num_list = [1]

        
        while count < n:
            nums = [base[i]*num_list[factor[i]] for i in range(3)]

            num = min(nums)
            i = nums.index(num)
            factor[i] += 1
            if num > num_list[-1]:
                num_list.append(num)
                count += 1
 
        return num_list[-1]

# sol4: DP, similar to sol3, https://leetcode.com/problems/ugly-number-ii/discuss/69384/My-expressive-Python-solution
# 思路基本上一样，就是换种写法
    def nthUglyNumber(self, n):
        ugly = [1]
        i2, i3, i5 = 0, 0, 0
        while n > 1:
            u2, u3, u5 = 2 * ugly[i2], 3 * ugly[i3], 5 * ugly[i5]
            umin = min((u2, u3, u5))
            if umin == u2:
                i2 += 1
            elif umin == u3:
                i3 += 1
            elif umin == u5:
                i5 += 1
            ugly.append(umin)
            n -= 1
        return ugly[-1]
    
# sol5: hashset + priority queue
# nlog(n)   https://www.jiuzhang.com/solution/ugly-number-ii/#tag-highlight-lang-python
    import heapq
    def nthUglyNumber(self, n):
        ugly = [1]
        heapq.heapify(ugly)
        
        visited = set(ugly)
        for i in range(n):
            cur = heapq.heappop(ugly)
            for factor in [2,3,5]:
                candidate = cur * factor
                if candidate not in visited:
                    visited.add(candidate)
                    heapq.heappush(ugly, candidate)
        return cur
    
# # sol6, only use priority queue
    import heapq
    def nthUglyNumber(self, n):
        ugly = [(1,1)]
        
        
        for i in range(n):
            cur, max_factor = heapq.heappop(ugly)
            for factor in [2,3,5]:
                if factor >= max_factor:
                    heapq.heappush(ugly, (factor*cur, factor))
        return cur
        
        
        

                    
        
