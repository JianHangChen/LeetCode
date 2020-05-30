//!!! sol1.1, from milinthosani in solution answer, O(n), O(1), two pointer, concise
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(abs(n1-n2) > 1 || s == t) return false;
        int i = 0, j = 0;
        bool inserted = false;
        while(i < n1 && j < n2){
            if(s[i] != t[j]){
                if(inserted) return false;
                inserted = true;
                if(n1 > n2) j--;
                else if(n1 < n2) i--;
            }
            i++; j++;            
        }
        return true;
    }
};

//!! sol1, my O(n), O(1), two pointer
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        
        if(abs(n1-n2) > 1) return false;
        if(n2 - n1 == 1){
            return ifInsert(s, t);
        }
        else if(n1 - n2 == 1){
            return ifInsert(t, s);
        }
        else{ // n1 == n2
            int i = 0, j = 0;
            bool inserted = false;
            while(i < n1 && j < n2){
                if(s[i] != t[j]){
                    if(inserted) return false;
                    else{
                        inserted = true;
                    }
                }
                i++; j++;
            }
            return inserted;
        }
        return true;
    }
    bool ifInsert(string& s, string& t){
        int n1 = s.size(), n2 = t.size();
        int i = 0, j = 0;
        bool inserted = false;
        while(i < n1 && j < n2){
            if(s[i] != t[j]){
                if(inserted) return false;
                else{
                    inserted = true;
                    j++;
                }
            }
            else{
                i++; j++;
            }
        }
        return true;
    }
    
};

//using substr
bool isOneEditDistance(string &s, string &t) {
        
        int ls = s.size(), lt = t.size();
        if(ls == lt){
            int count = 0;
            for(int i = 0; i < ls; i++){
                if( s[i] != t[i] ){
                    count++;
                }
            }
            return count == 1;
        }
        else if( abs(ls - lt) == 1){
            
            if(ls > lt){
                swap(s, t);
            }
            
            int i = 0;
            
            while( i < s.size()){
                if(s[i] != t[i]){
                    break;
                }
                i++;
            }
            return s.substr(i) == t.substr(i+1);
            
        }
        else{
            return false;
        }
    }
    
    // sol2, https://github.com/grandyang/leetcode/issues/161
// using substre
    bool isOneEditDistance(string &s, string &t) {
        int ls = s.size(), lt = t.size();
        for(int i = 0; i < min(ls, lt); i++){
            if(s[i] != t[i]){
                if(ls == lt){
                    return s.substr(i+1) == t.substr(i+1);
                } 
                else if((ls - lt) == 1){
                    return s.substr(i+1) == t.substr(i);
                }
                else if( (lt - ls) == 1){
                    return s.substr(i) == t.substr(i+1);
                }
                else{
                    return false;
                }
            }
        }
        
        return abs(ls - lt) == 1;
    }
