class Solution {
public:
    //sol1
    int lengthLongestPath(string input) {
        int n = input.size();
        
        unordered_map<int, int> count = {{0,0}};
        int level = 0;
        
        int start;
        int res = 0;
        
        for(int i = 0; i < n; i++){
            start = i;
            while(i < n && input[i] != '\n' && input[i] != '\t') i++;
            
            if(i >= n || input[i] == '\n'){
                
                string t = input.substr(start, i - start);
                int len_t = t.size();
                
                if( t.find('.') != string::npos ){
                    res = max(res, count[level] + len_t );
                }
                else{
                    count[level + 1] = count[level] + len_t + 1;
                }
                level = 0;
            }
            else{ // meet \t
                level++;
            }
            
        }
        return res;
        
    }
    
    // sol2, use stringstream
    int lengthLongestPath(string input) {
        unordered_map<int, int> layer = {{0, 0}};
        stringstream s(input);
        string line;
        int res = 0;
        while(getline(s, line)){
            int level = line.find_last_of('\t') + 1;
            int len_t = line.substr(level).size();
            if(line.find('.') != string::npos)//is file
            { 
                res = max(res, layer[level] + len_t);
            } 
            else{
                layer[level+1] = layer[level] + len_t + 1;
            }
        }
        return res;
        
    }


};
