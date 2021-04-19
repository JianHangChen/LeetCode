// sol1.1, use istringstream
class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.size();
        int countSpace = 0;
        
        for(int i = 0; i < n; i++){
            if(text[i] == ' ') countSpace++;
        }
        istringstream is(text);
        vector<string> words;
        string cur;
        while(is>>cur){
            words.push_back(cur);
        }
        
        int gap = words.size() == 1 ? 0 : countSpace / (words.size()-1);
        int rem = countSpace - (words.size() - 1) * gap;
        
        string res;
        for(int i = 0; i < words.size() - 1; i++){
            res += words[i];
            res += string(gap, ' ');
        }
        res += words.back();
        res += string(rem, ' ');

        return res;
    }
};

// sol1, my
class Solution {
public:
    string reorderSpaces(string text) {
        int n = text.size();
        int countSpace = 0, countWord = 0;
        for(int i = 0; i < n; i++){
            if(text[i] == ' ') countSpace++;
            if(isalpha(text[i]) && (i == 0||!isalpha(text[i-1]))){
                countWord++;
            }
        }
        int avgSpace = countWord == 1 ? countSpace : countSpace / (countWord-1);
        
        string res, cur;
        istringstream is(text);
        while(is>>cur){
            res += cur;
            res += string(avgSpace, ' ');
        }
        while(res.size() > n){
            res.pop_back();
        }
        while(res.size() < n){
            res += ' ';
        }

        return res;
    }
};
