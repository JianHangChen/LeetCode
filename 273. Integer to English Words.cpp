

// sol1, my
class Solution {

private:
    unordered_map<int, string> one_dec = { {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, {6, "Six"},{7, "Seven"}, {8, "Eight"}, {9, "Nine"} },
    two_dec = { {10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"},
    {14, "Fourteen"}, {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, {19, "Nineteen"}},
    tens = {{1, "Ten"}, {2, "Twenty"}, {3, "Thirty"}, {4, "Forty"}, {5, "Fifty"}, {6, "Sixty"}, {7, "Seventy"}, {8, "Eighty"}, {9, "Ninety"}},
    levels = {{3, "Billion"}, {2, "Million"}, {1, "Thousand"} };

public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        vector< vector<string>> words;
        string res;

        while(num > 0){
            int three = num % 1000;
            num /= 1000;
            words.push_back( getHundreds(three) );
        }
        int n = words.size();

        for(int i = n - 1; i >= 0; i--){

            for(int j = 0; j < words[i].size(); j++){
                if( res.size() > 0) res += " ";
                res += words[i][j];
            }
            if(i > 0 && words[i].size() > 0){
                if(res.size() > 0) res += " ";
                res += levels[i];
            }
        }
        return res;
    }


    vector<string> getHundreds(int num){
        vector<string> words;
        int hundred = num / 100;
        if(hundred != 0) {words.push_back(one_dec[hundred]); words.push_back("Hundred");}
        int two = num % 100;

        if(two_dec.count(two) > 0){
            words.push_back( two_dec[two] );
         }
        else{
           int second = two / 10, third = two % 10;
            if(tens.count(second) > 0) words.push_back( tens[second]);
            if(third != 0) words.push_back(one_dec[third]);
        }
       return words;
    }
};
