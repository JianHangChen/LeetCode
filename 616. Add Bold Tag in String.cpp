
// sol1, my!!!

class Solution {
public:

    string addBoldTag(string &s, vector<string> &dict) {
        int n = s.size();
        vector<bool> bold(n, false);
        
        for(auto word:dict){
            for(int i = 0; i < n; i++){
                int j = 0;
                while(j < word.size()){
                    if(s[i+j] != word[j]) break;
                    j++;
                }
                
                if(j == word.size()){
                    for(int k = 0; k < word.size(); k++){
                        bold[i + k] = true;
                    }
                }
            }
        }
        
        string res = "";
        
        bool inbold = false;
        
        for(int i = 0; i < n; i++){
            if(bold[i]){
                if(!inbold){
                    res += "<b>";
                    res += s[i];
                    inbold = true;
                }
                else{
                    res += s[i];
                }
            }
            else{
                if(inbold){
                    inbold = false;
                    res += "</b>";
                    res += s[i];
                }
                else{
                    res += s[i];
                }
            }
        }
        if(inbold){
            res += "</b>";
        }
        return res;
        
    }
};


// sol2, from grandyang, practice substr

class Solution{
    public:
    string addBoldTag(string &s, vector<string> &dict){
        int n = s.size(), end = 0;
        vector<bool> bold(n, false);
        for(int i = 0; i < n; i++){
            for(auto word:dict){
                int len = word.size();
                if(i + len <= n && s.substr(i, len) == word){
                    end = max(end, i + len);
                }
            }
            bold[i] = end > i;
        }
        
        string res = "";
        
        for(int i = 0; i < n; i++){
            if(!bold[i]){
                res += s[i];
            }
            else{
                int j = i;
                while(j < n && bold[j]){
                    bold[j];
                    j++;
                }
                res += "<b>" + s.substr(i, j - i) + "</b>";
                i = j - 1;
            }
        }
        
        return res;
        
    }
};
