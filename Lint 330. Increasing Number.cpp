

class Solution {
public:
    /**
     * @param N:  a positive integer N
     * @return: return a maximum integer less than N, each digit of which must be monotonically increasing.
     */
    long long getIncreasingNumber(long long N) {
        if(N > 123456789) return 123456789;
        N--;
        string s = to_string(N);
        int n = s.size();
        int i = n - 1;
        while(i > 0){
            if(s[i-1] >= s[i]){
                decrease(s, i-1);
                fillout(s, i);
                cout << s << endl;
            }
            else{
                i--;
            }
        }
        
        return stoi(s);
        

    }
    void decrease(string& s, int i){
        string t = s.substr(0, i+1);
        int n = stoi(t);
        n--;
        string s_ = to_string(n);
        for(int j = 0; j <= i; j++) s[j] = '0';
        for(int j = s_.size() - 1; j >= 0; j--){
            s[i--] = s_[j];
        }
    }
    void fillout(string& s, int i){
        int n = s.size();
        int j = n - 1;
        int t = 9;
        while(j >= i){
            s[j--] = t + '0';
            t--;
        }
        
    }
    

};

//  111222333
