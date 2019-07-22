// sol2,!!! 
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
    	vector<pair<int, int>> p[26];
    	int n = S.size(), m = words.size(), res=0;
    	for(int i = 0; i < m; i++){
    		int c = words[i][0] - 'a';
    		p[c].emplace_back(i,1);
    	}

    	for(int i = 0; i < n; i++){
    		int c = S[i] - 'a';
    		auto vect = p[c];
    		p[c].clear();
    		for(auto pa:vect){
    			if(pa.second == words[pa.first].size()){
    				res++;
    			}
    			else{
                    pa.second++;
    				p[words[pa.first][pa.second-1] - 'a'].push_back(pa);
                    // this not working:
    				// p[word[pa.second] - 'a'].push_back(pa);
    				// pa.second++;                    
    			}
    		}
    	}
    	return res;
    }
};


// sol1,  
class Solution {
public:
    bool isValidWord(string& word, vector<vector<int>>& pos){
        int m = word.size(), i = -1; // i is in S
        
        vector<int> start(26, 0);
        for(int j  = 0; j < m; j++){
            int c = word[j] - 'a';
            
            while(start[c] < pos[c].size() && pos[c][start[c]] <= i){
                start[c]++;
            }

            if(start[c] >= pos[c].size()){ return false;}
            
            i = pos[c][start[c]];
            start[c]++;
        }
        return true;
    }

        
    int numMatchingSubseq(string S, vector<string>& words) {
        int res = 0;
        vector<vector<int>> pos(26, vector<int> ());
        
        int n = S.size(); 
        for(int i = 0; i < n; i++){
            pos[ S[i] - 'a'].push_back(i); 
        }
        
        for(auto word:words){

            if(isValidWord(word, pos)) res++;

        }
        return res;
    }
};
