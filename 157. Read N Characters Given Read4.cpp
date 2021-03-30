
// !!! sol2, gy, O(n), O(1), read all 4 * times, and then use min(ibuf, n) to get the smallest size 
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ibuf = 0;
        for(int i = 0; i <= n / 4; i++){ // if n == 16-> n / 4 = 4
            int cur = read4(buf+ibuf);
            ibuf += cur;
            if(cur == 0) break;
        }
        return min(ibuf, n);
    }
};

// !!!!!!! sol1.1, revised to for loop, O(n), O(4), use extra buf4
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char buf4[4];
        int ibuf4 = 0, buf4len = 0;
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

// sol1, my, O(n), O(4), using extra buf4 to store tmp result
class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int ibuf = 0, ibuf4 = 0;        
        
        char buf4[4];
        int buf4len = 0;
        int i = 0;
        while( i < n ){
            if(buf4len > 0){
                buf4len--;
                buf[i++] = buf4[ibuf4++];
                
            }
            else{
                buf4len = read4(buf4);
                ibuf4 = 0;
                if(buf4len == 0) break;
            }            
        }
                
        return i;
    }
};
