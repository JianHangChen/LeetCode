class Solution {
public:
    
    int romanToInt(string s) 
    {
        int i = 0;
        int n = s.size();
        int res = 0 ;

        int value[26];
        value['I' - 'A'] = 1;
        value['V' - 'A'] = 5;
        value['X' - 'A'] = 10;
        value['L' - 'A'] = 50;
        value['C' - 'A'] = 100;
        value['D' - 'A'] = 500;
        value['M' - 'A'] = 1000;

        int right = value[ s.front() - 'A'];
        int cur;

        for(int i  = 1; i < n; i++){
            cur = right;
            right = value[ s[i] - 'A'];

            if( cur >= right){
                res += cur;
            }
            else{
                res -= cur;
            }
        }

        return (res + right);

    }
};

//use dict
/*
class Solution {
private:
	unordered_map<char, int> dict = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

public:
    int romanToInt(string s) {
        int i = 0;
        int n = s.size();
        int res = 0 ;
        while(i < n){
        	if( i + 1 < n){
	        	if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')  ||
	        	   s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')	||
	        	   s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')
	        		){
	        		res += ( dict[ s[i+1] ] - dict[ s[i] ]);
	        		i += 2;
	        		continue;
	        	}

        	}
    		res += dict[ s[i] ];
    		i++;

        }
        return res;
    }
};

*/
