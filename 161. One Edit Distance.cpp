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
  
