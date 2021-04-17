// !!! sol2, O(n), O(n)
// n: target.size()
// https://leetcode.com/problems/alphabet-board-path/discuss/345278/C%2B%2BJava-O(n)
class Solution {
public:
    vector<int> GetCoor(char c){
        int idx = c - 'a';
        return {idx/5, idx%5};
    }
    string alphabetBoardPath(string target) {
        vector<int> cur = {0, 0};       
        
        string res = "";
        for(char c:target){
            vector<int> next = GetCoor(c);
            if(next != cur){
                int dx = next[0] - cur[0], dy = next[1] - cur[1];
                while(dy < 0){ //!! tricky left first for target is z
                    res += 'L';
                    dy++;
                }
                while(dx < 0){ //!! up first for z
                    res += 'U';
                    dx++;
                }
                while(dx > 0){
                    res += 'D';
                    dx--;
                }
                while(dy > 0){
                    res += 'R';
                    dy--;
                }
                cur = next;
            }
            res += '!';
        }
        return res;
        
    }
};



// my sol1
class Solution {
public:
    string alphabetBoardPath(string target) {
        vector<int> cur = {0, 0};
        
        unordered_map<char, vector<int>> coor;
        char c = 'a';
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 5; j++){
                coor[c++] = {i, j};
                if(c > 'z') break;
            }
        }
        
        
        string res = "";
        for(char c:target){
            if(coor[c] == cur){
                res += '!'; continue;
            }
            if(cur == coor['z']){
                res += 'U';
                cur = coor['u'];
            }
            bool targetz = false;
            if(c == 'z'){
                targetz = true;
                c = 'u';
            }
            int dx = coor[c][0] - cur[0], dy = coor[c][1] - cur[1];
            while(dx > 0){
                res += 'D';
                dx--;
            }
            while(dx < 0){
                res += 'U';
                dx++;
            }
            while(dy < 0){
                res += 'L';
                dy++;
            }
            while(dy > 0){
                res += 'R';
                dy--;
            }
            
            cur = coor[c];
            if(targetz){
                res += 'D';
                cur = coor['z'];
            }
            res += '!';
        }
        return res;
        
    }
};
