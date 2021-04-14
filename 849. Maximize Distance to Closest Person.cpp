//!!! sol2, from sol2, two pointer
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int pre = -1, future = 0;
        int maxDist = 1;
        for(int i = 0; i < n; i++){
            if(seats[i] == 1){
                pre = i;
            }
            else{
                while(future <= i || future != n && seats[future] != 1){
                    future++;
                }
                if(pre == -1) maxDist = max(maxDist, i + 1);
                else if(future == n) maxDist = max(maxDist, n - i);
                else maxDist = max(maxDist, min(i - pre, future - i));
            }
        }
        return maxDist;
    }
};

// sol1, my, O(n), O(n)
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> leftClosest(n), rightClosest(n);
        int left = -1e9, right = 1e9;
        for(int i = 0; i < n; i++){
            if(seats[i] == 1){
                left = i;
            }
            leftClosest[i] = left;
        }
        for(int i = n - 1; i >= 0; i--){
            if(seats[i] == 1){
                right = i;
            }
            rightClosest[i] = right;
        }
        int maxDist = 0;
        for(int i = 0; i < n; i++){
            if(seats[i] == 0){
                maxDist = max(min(i - leftClosest[i], rightClosest[i] - i), maxDist);
            }
        }
        return maxDist;
    }
};
