//!! my sol1, O(N), O(1), proof in sol1
class Solution {
public:
    bool isRobotBounded(string instructions) {
        int r = 0, dx = 0, dy =0;
        for(char c:instructions){
            if(c == 'R') r++;
            else if(c == 'L') r--;
            else{ // G
                if(r == 0) dy++;
                else if(r == 1) dx++;
                else if(r == 2) dy--;
                else dx--;
            }
            r = (r + 4) % 4;
        }
        if(dx == 0 && dy == 0) return true;
        if(r == 0) return false;
        return true;
    }
};
