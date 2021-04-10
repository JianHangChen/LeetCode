class Solution {
public:
    int compress(vector<char>& chars) {
        int s = 0, f = 0, n = chars.size(), count;
        while(f < n){
            chars[s++] = chars[f++];
            count = 1;
            while(f < n && chars[f] == chars[f-1]){
                count++;
                f++;
            }
            if(count != 1){
                string cntStr = to_string(count);
                for(char c:cntStr) chars[s++] = c;
            }
        }
        return s;
    }
};
