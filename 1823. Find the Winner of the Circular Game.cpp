
// sol2, josephus problem
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/discuss/1152705/JavaC%2B%2BPython-4-lines-O(n)-time-O(1)-space
// from n = 6 to n = 5
//0 1 2 3|4|5 n = 6
//2 3|4|x 0 1
//3 x|0|x 1 2 
//x x 0 x|1|2
//x x x x|0|1
//x x x x 0 x


// 0
// |0| 1
// 0 |1| 2
class Solution {
public:
    // prev winner index previous(i)
    int previous(int cur, int n, int k){
        return (cur + k) % (n+1); // n is the previous count of all number
    }
    int findTheWinner(int n, int k) {
        int cur = 0;
        for(int i = 1; i < n; i++){
            cur = previous(cur, i, k);
        }
        return cur + 1;
    }
};

// josephus problem, interesting
// https://www.youtube.com/watch?v=uCsD3ZGzMgE

// 12345
// 23451 

// 3451 
// 4513

// 34512

// 45123
// 51234
// 12345

// sol1, my, O(nk), O(k)
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++) q.push(i);
        while(q.size() > 1){
            for(int i = 0; i < k - 1; i++){
                int cur = q.front(); q.pop();
                q.push(cur);
            }
            q.pop();
        }
        return q.front();
        
    }
};
