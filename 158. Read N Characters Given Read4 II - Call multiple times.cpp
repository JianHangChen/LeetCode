// sol1, from gy2, copy to buf4, O(n), O(4)

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char buf4[4];
    int ibuf4 = 0;
    int buf4len = 0;
    
    int read(char *buf, int n) {
        for(int i = 0; i < n; i++){
            if(buf4len == 0){
                buf4len = read4(buf4);
                ibuf4 = 0;
                if(buf4len == 0) return i;
            }
            buf[i] = buf4[ibuf4++];
            buf4len--;
        }       
        return n;
    }
};
